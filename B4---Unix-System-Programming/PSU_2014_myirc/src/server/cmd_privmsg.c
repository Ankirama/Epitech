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

static int	_check_error(t_server *server, int fd, char **argv)
{
  if (argv == NULL || argv[0] == NULL)
    {
      send_code_msg(server, fd, ERR_NORECIPIENT,
		    strdup(":No recipient given (PRIVMSG)"));
      return (1);
    }
  else if (argv[1] == NULL)
    {
      send_code_msg(server, fd, ERR_NOTEXTTOSEND, strdup(":No text to send"));
      return (1);
    }
  else if (array_len(argv) + strlen("PRIVMSG") > MAX_MSG - strlen("\r\n"))
    {
      send_info_msg(server, fd, server->client[fd].nick, "QUIT :Excess Flood");
      return (-1);
    }
  return (0);
}

static char	*_create_msg(char **argv, char *user)
{
  char		*msg;
  int		i;

  if (argv[0][0] == ':')
    msg = my_malloc(strlen("PRIVMSG ") + strlen(user) + strlen(" ") +
		    array_len(argv) + 1);
  else
    msg = my_malloc(strlen("PRIVMSG ") + strlen(user) + strlen(" :") +
		    strlen(argv[0]) + 1);
  msg[0] = '\0';
  msg = strcat(msg, "PRIVMSG ");
  msg = strcat(msg, user);
  msg = strcat(msg, " ");
  if (argv[0][0] == ':')
    {
      i = -1;
      while (argv[++i] != NULL)
	msg = strcat(msg, argv[i]);
    }
  else
    {
      msg = strcat(msg, ":");
      msg = strcat(msg, argv[0]);
    }
  return (msg);
}

static void	_send_to_client(t_server *server, int fd, char *user, char *msg)
{
  int		i;
  int		found;

  i = -1;
  found = 0;
  while (!found && ++i < MAX_FD)
    {
      if (server->type_fd[i] == FD_CLIENT &&
	  strcmp(server->client[i].nick, user) == 0)
	found = 1;
    }
  if (!found)
    send_code_msg(server, fd, ERR_NOSUCHNICK,
		  create_error_msg(user, " :No such nick/channel"));
  else
    send_info_msg(server, i, server->client[fd].nick, msg);
}

static void	_send_to_channel(t_server *server, int fd,
				 char *chan, char *msg)
{
  t_channel	*tmp;
  int		i;
  t_list	*lst;

  if (!(tmp = get_channel(server->channels, chan)))
    send_code_msg(server, fd, ERR_NOSUCHNICK,
		  create_error_msg(chan, " :No such nick/channel"));
  else if (get_list(tmp->clients, server->client[fd].nick) == tmp->clients)
    send_code_msg(server, fd, ERR_CANNOTSENDTOCHAN,
		  create_error_msg(chan, " :Cannot send to channel"));
  else
    {
      lst = tmp->clients->next;
      while (lst != tmp->clients)
	{
	  i = -1;
	  while (++i < MAX_FD)
	    if (server->type_fd[i] == FD_CLIENT &&
		strcmp(server->client[i].nick, lst->data) == 0)
	      break;
	  if (i != fd)
	    send_info_msg(server, i, server->client[fd].nick, msg);
	  lst = lst->next;
	}
    }
}

int	cmd_privmsg(t_server *server, int fd, char **argv)
{
  int	error;
  char	*msg;

  if ((error = _check_error(server, fd, argv)) == 0)
    {
      msg = _create_msg(&argv[1], argv[0]);
      if (argv[0][0] != '#')
	_send_to_client(server, fd, argv[0], msg);
      else
	_send_to_channel(server, fd, argv[0], msg);
      free(msg);
    }
  else if (error == -1)
    return (1);
  return (0);
}
