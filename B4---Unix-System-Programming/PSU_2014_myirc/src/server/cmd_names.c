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

int		cmd_names(t_server *server, int fd, char **argv)
{
  t_channel	*tmp;
  char		*names;
  char		*end;

  if (!argv || !argv[0])
    {
      tmp = server->channels;
      while (tmp != NULL)
	{
	  send_code_msg(server, fd, RPL_NAMREPLY,
			get_user_list(server, tmp->name));
	  tmp = tmp->next;
	}
    }
  else if ((names = get_user_list(server, argv[0])))
    send_code_msg(server, fd, RPL_NAMREPLY, names);
  if (argv != NULL && argv[0] != NULL)
    end = create_error_msg(argv[0], " :End of /NAMES list");
  send_code_msg(server, fd, RPL_ENDOFNAMES,
		!argv || !argv[0] ? strdup("* :End of /NAMES list") : end);
  return (0);
}
