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

static int	_set_error_code(t_server *s, int fd, char *channel)
{
  int		code;
  t_channel	*chan;
  t_list	*tmp;

  code = 0;
  if (!channel)
    code = ERR_NEEDMOREPARAMS;
  else if (channel[0] != '#' ||
	   (chan = get_channel(s->channels, channel)) == NULL)
    code = ERR_NOSUCHCHANNEL;
  else
    {
      tmp = chan->clients->next;
      while (tmp != chan->clients &&
	     strcmp(tmp->data, s->client[fd].nick) != 0)
	tmp = tmp->next;
      if (tmp == chan->clients)
	code = ERR_NOTONCHANNEL;
    }
  return (code);
}

static char	*_check_error(char *channel, int code)
{
  char		*err;

  err = NULL;
  if (code == ERR_NEEDMOREPARAMS)
    err = strdup("PART :Not enough parameters");
  else if (code == ERR_NOSUCHCHANNEL)
    err = create_error_msg(channel, " :No such channel");
  else if (code == ERR_NOTONCHANNEL)
    err = create_error_msg(channel, ":You're not on that channel");
  return (err);
}

int		cmd_part(t_server *server, int fd, char **argv)
{
  int		code;
  t_channel	*tmp;

  if ((code = _set_error_code(server, fd, argv == NULL ? NULL : argv[0])) != 0)
    send_code_msg(server, fd, code,
		  _check_error(!argv ? NULL : argv[0], code));
  else
    {
      tmp = get_channel(server->channels, argv[0]);
      remove_element(&(tmp->clients),
		     server->client[fd].nick);
      tmp->nb_users -= 1;
      if (tmp->nb_users == 0)
	remove_channel(&server->channels, argv[0]);
      remove_element(&(server->client[fd].channels), argv[0]);
    }
  return (0);
}
