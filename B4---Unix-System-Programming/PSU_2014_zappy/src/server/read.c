/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 17:41:56 2015 CHARLES VITERBO
*/

/*
** @file read.c
** @brief functions to read from client or server
** @author ankirama
** @version 1.0
*/

#include "read.h"

/*
** @brief it will check if we have \r or \n in our message and remove it
**
** @deprecated \r is useless on unix but it could be useful on windows
**
** @param buf our buffer we want to change
** @param r the size of this buffzer
** @return 0 if we didnt change the buffer (so the buffer isn't the end, else 1
*/
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
** @brief conditions to check the read's return
**
** @param server our server's structure
** @param list_read our circular buffer (a list)
** @param fd our client's fd
** @param r return value of read
*/
static void	_condition_read(t_server *server,
				t_list *list_read,
				int fd, int r)
{
  if (r > 0 && server->client[fd].cmds->size < 10)
    add_element(&server->client[fd].cmds, list_read, 1);
  else if (r <= 0)
    {
      let_it_go(&list_read);
      close_connection(server, fd);
    }
  else if (r > 0 && server->client[fd].cmds->size >= 10)
    let_it_go(&list_read);
}

/*
** @brief used to display our client's message
**
** @param server our structure
** @param fd our file descriptor
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
	  add_element(&list_read, my_strdup(buf), strlen(buf));
	  break;
	}
      add_element(&list_read, my_strdup(buf), strlen(buf));
      memset(buf, 0, BUF_SIZE + 1);
    }
  _condition_read(server, list_read, fd, r);
}

/*
** @brief it will create / set our new client with default values
**
** It will set our new client and send our welcome message
**
** @param server main structure
** @param fd file descriptor
** @return 0 if no error else -1
*/
static int	_set_client(t_server *server, int fd)
{
  server->client[fd].playerId = 0;
  server->client[fd].team = NULL;
  memset(server->client[fd].inventaire, 0, sizeof(unsigned int) * NB_OBJ);
  server->client[fd].food = DEFAULT_FOOD;
  server->client[fd].orientation = DIR_UP;
  server->client[fd].pos = 0;
  server->client[fd].fd = fd;
  server->client[fd].graphic = 0;
  if ((server->write_buffer[fd] = create_root()) == NULL)
    return (-1);
  server->client[fd].created = 0;
  server->client[fd].level = 1;
  if ((server->client[fd].cmds = create_root()) == NULL)
    {
      let_it_go(&(server->write_buffer[fd]));
      return (-1);
    }
  server->client[fd].time_cmd = -1;
  welcome(server, fd);
  return (0);
}

/*
** @brief it will set our read function and allow a client to be connected
**
** @param server our structure
** @param fd our fd where the client will be connected
*/
void		read_server(t_server *server, int fd)
{
  int		s;
  t_sockaddr_in	client_sin;
  socklen_t	client_sin_len;

  client_sin_len = sizeof(client_sin);
  if ((s = my_accept(fd, (t_sockaddr *)&client_sin, &client_sin_len)) != -1
      && s < server->nb_fd && _set_client(server, s) != -1)
    {
      cmd_log("New client connected", "read_server", xdate(), TYPE_INFO);
      server->type_fd[s] = FD_CLIENT;
      server->fct_read[s] = _read_client;
      server->fct_write[s] = write_client;
      server->curr_max = s < server->curr_max ? server->curr_max : s;
    }
  else
    {
      my_close(s);
      cmd_log("Unable to create new player", "read_server", xdate(), 1);
    }
}
