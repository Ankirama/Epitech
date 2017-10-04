/*
** main.c<2> for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 10:32:07 2015 Fabien Martinez
*/

#include "server.h"

static void	_split_msg_list(t_server *server, int fd, char *msg)
{
  int		begin;
  int		len;
  char		*tmp;

  begin = 0;
  len = strlen(msg);
  while (begin < len)
    {
      tmp = strndup(&msg[begin], MAX_MSG);
      add_element(&(server->write_buffer[fd]), tmp);
      free(tmp);
      begin += MAX_MSG;
    }
}

char	*create_error_msg(char *value, char *msg)
{
  char	*error;

  error = my_malloc(strlen(value) + strlen(msg) + 1);
  error[0] = '\0';
  error = strcat(error, value);
  error = strcat(error, msg);
  return (error);
}

void	send_code_msg(t_server *server, int fd, int code, char *err)
{
  char	*nick;
  char	*nbr;
  char	*msg;

  nick = strdup(!server->client[fd].nick ? "*" : server->client[fd].nick);
  nbr = int_to_str(code);
  msg = my_malloc(1 + strlen(server->hostname) + 1 + strlen(nbr) + 1 +
		  strlen(nick) + 1 + strlen(err) + strlen("\r\n") + 1);
  msg[0] = '\0';
  msg = strcat(msg, ":");
  msg = strcat(msg, server->hostname);
  msg = strcat(msg, " ");
  msg = strcat(msg, nbr);
  msg = strcat(msg, " ");
  msg = strcat(msg, nick);
  msg = strcat(msg, " ");
  msg = strcat(msg, err);
  msg = strcat(msg, "\r\n");
  _split_msg_list(server, fd, msg);
  free(msg);
  free(err);
  free(nick);
}

void	send_info_msg(t_server *server, int fd, char *nick, char *message)
{
  char	*msg;

  msg = my_malloc(1 + strlen(nick) + 1 + strlen(server->client[fd].hostname) +
		  1 + strlen(message) + strlen("\r\n") + 1);
  msg[0] = '\0';
  msg = strcat(msg, ":");
  msg = strcat(msg, nick);
  msg = strcat(msg, "@");
  msg = strcat(msg, server->client[fd].hostname);
  msg = strcat(msg, " ");
  msg = strcat(msg, message);
  msg = strcat(msg, "\r\n");
  _split_msg_list(server, fd, msg);
  free(msg);
}

void		write_client(t_server *server, int fd)
{
  t_list	*tmp;

  tmp = server->write_buffer[fd]->next;
  if (tmp != server->write_buffer[fd])
    {
      while (tmp != server->write_buffer[fd])
	{
	  my_printf(fd, "%s", tmp->data);
	  tmp = tmp->next;
	}
      let_it_go(&(server->write_buffer[fd]));
      server->write_buffer[fd] = create_root();
    }
}
