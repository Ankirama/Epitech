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

static void	_change_user(t_server *server, char *user, int fd)
{
  t_list	*chan;
  t_channel	*tmp;

  chan = server->client[fd].channels->next;
  while (chan != server->client[fd].channels)
    {
      tmp = get_channel(server->channels, chan->data);
      change_element(&(tmp->clients),
		     server->client[fd].nick, user);
      display_list(tmp->clients, 1);
      chan = chan->next;
    }
}

static int	_check_user(t_server *server, char *user, int fd)
{
  int		i;

  i = -1;
  while (++i < MAX_FD)
    {
      if (i == fd || server->type_fd[i] != FD_CLIENT || !server->client[i].nick)
	continue;
      if ((strcmp(user, server->client[i].nick)) == 0)
	return (0);
    }
  return (1);
}

static char	*_check_error(t_server *server, int fd, char *user, int *code)
{
  if (user == NULL)
    {
      *code = ERR_NONICKNAMEGIVEN;
      return (strdup(":No nickname given"));
    }
  else if (user[0] == '*' || user[0] == '#' || user[0] == '"' ||
	   user[0] == '\'' || user[0] == '&' || user[0] == ':')
    {
      *code = ERR_ERRONEUSNICKNAME;
      return (create_error_msg(user, " :Erroneous Nickname"));
    }
  else if (_check_user(server, user, fd) == 0)
    {
      *code = ERR_NICKNAMEINUSE;
      return (create_error_msg(user, " :Nickname is already in use"));
    }
  return (NULL);
}

int	cmd_nick(t_server *server, int fd, char **argv)
{
  char	*err;
  int	code;

  code = 0;
  err = _check_error(server, fd, argv == NULL ? NULL : argv[0], &code);
  if (code != 0)
    send_code_msg(server, fd, code, err);
  else
    {
      _change_user(server, argv[0], fd);
      free(server->client[fd].nick);
      server->client[fd].nick = strdup(argv[0]);
    }
  return (0);
}
