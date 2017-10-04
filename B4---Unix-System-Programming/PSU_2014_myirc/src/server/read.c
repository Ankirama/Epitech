/*
** read.c for read in /home/mar_b/rendu/PSU_2014_myirc
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Apr  1 10:18:18 2015 Fabien Martinez
** Last update Wed Apr  1 10:37:57 2015 Fabien Martinez
*/

#include "server.h"

static void	_close_connection(t_server *server, int fd)
{
  t_list	*tmp;
  t_channel	*chan;

  my_printf(1, "%d: Connecion closed.\n", fd);
  my_close(fd);
  server->type_fd[fd] = FD_FREE;
  tmp = server->client[fd].channels->next;
  while (tmp != server->client[fd].channels)
    {
      chan = get_channel(server->channels, tmp->data);
      remove_element(&chan->clients, server->client[fd].nick);
      chan->nb_users -= 1;
      if (chan->nb_users == 0)
	remove_channel(&server->channels, tmp->data);
      tmp = tmp->next;
    }
}

static int	_check_end_msg(char *buf, int r)
{
  if (buf[r - 1] == '\n')
    {
      buf[r - 1] = '\0';
      if (r > 1 && buf[r - 2] == '\r')
	buf[r - 2] = '\0';
      return (1);
    }
  return (0);
}

/*
** brief: used to display our client's message
** @server: our structure
** @fd: our file descriptor
*/
static void	_read_client(t_server *server, int fd)
{
  int		r;
  t_list	*list_read;
  char		buf[BUF_SIZE + 1];

  list_read = create_root();
  memset(buf, 0, BUF_SIZE + 1);
  while ((r = read(fd, buf, BUF_SIZE)) > 0)
    {
      buf[r] = '\0';
      if (_check_end_msg(buf, r))
	{
	  add_element(&list_read, buf);
	  break;
	}
      add_element(&list_read, buf);
      memset(buf, 0, BUF_SIZE + 1);
    }
  if (!r || (r && interpret_message(server, fd, list_read)))
    _close_connection(server, fd);
  let_it_go(&list_read);
}

static void	_set_client(t_server *server, int fd)
{
  char		*name;
  char		*nb;
  t_sockaddr_in	addr;
  socklen_t	len;

  len = sizeof(addr);
  name = my_malloc(str_nbr(fd) + strlen("guest") + 1);
  name[0] = '\0';
  name = strcat(name, "guest");
  nb = int_to_str(fd);
  name = strcat(name, nb);
  free(nb);
  server->client[fd].nick = strdup(name);
  free(name);
  server->client[fd].channels = create_root();
  server->client[fd].nb_channels = 0;
  server->write_buffer[fd] = create_root();
  if (getpeername(fd, (t_sockaddr *)&addr, &len) == -1)
    {
      my_printf(2, "getpeername: %s\n", strerror(errno));
      server->client[fd].hostname = strdup("unknown");
    }
  server->client[fd].hostname = strdup(inet_ntoa(addr.sin_addr));
  welcome(server, fd);
}

/*
** brief: it will set our read function and allow a client to be connected
** @server: our structure
** @fd: our fd where the client will be connected
*/
void		read_server(t_server *server, int fd)
{
  int		s;
  t_sockaddr_in	client_sin;
  socklen_t	client_sin_len;

  client_sin_len = sizeof(client_sin);
  if ((s = accept(fd, (t_sockaddr *)&client_sin, &client_sin_len)) != -1
      || s >= MAX_FD)
    {
      _set_client(server, s);
      my_printf(1, "New client from %s.\n", server->client[s].hostname);
      server->type_fd[s] = FD_CLIENT;
      server->fct_read[s] = _read_client;
      server->fct_write[s] = write_client;
    }
  else if (s == -1)
    my_printf(2, "accept: %s\n", strerror(errno));
  else
    {
      my_close(s);
      my_printf(2, "Error: unable to add a client, max reached!\n");
    }
}
