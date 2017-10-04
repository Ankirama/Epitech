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

static int	_set_error_code(t_server *s, char *channel)
{
  int		code;

  code = 0;
  if (!channel)
    code = ERR_NEEDMOREPARAMS;
  else if (channel[0] != '#' || !get_channel(s->channels, channel))
    code = ERR_NOSUCHCHANNEL;
  return (code);
}

static char	*_check_error(char *channel, int code)
{
  char		*err;

  err = NULL;
  if (code == ERR_NEEDMOREPARAMS)
    err = strdup("USERS :Not enough parameters");
  else if (code == ERR_NOSUCHCHANNEL)
    err = create_error_msg(channel, " :No such channel");
  return (err);
}

int	cmd_users(t_server *server, int fd, char **argv)
{
  int	code;
  char	*end;

  if ((code = _set_error_code(server, argv == NULL ? NULL : argv[0])) != 0)
    send_code_msg(server, fd, code,
		  _check_error(argv == NULL ? NULL : argv[0], code));
  else
    {
      send_code_msg(server, fd, RPL_NAMREPLY, get_user_list(server, argv[0]));
      end = my_malloc(strlen(argv[0]) + strlen(" :End of /NAMES list") + 1);
      end[0] = '\0';
      end = strcat(end, argv[0]);
      end = strcat(end, " :End of /NAMES list");
      send_code_msg(server, fd, RPL_ENDOFNAMES, end);
    }
  return (0);
}
