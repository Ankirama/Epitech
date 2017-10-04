/*
** main.c<2> for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

#include "server.h"

static void	_luser(t_server *s, int fd)
{
  int		i;
  int		nb_users;
  char		*str;
  char		*nbr;

  nb_users = 0;
  for (i = 0; i < MAX_FD; ++i)
    nb_users = s->type_fd[i] == FD_CLIENT ? nb_users + 1 : nb_users;
  str = my_malloc(strlen(":There are ") + str_nbr(nb_users) + 1);
  str[0] = '\0';
  nbr = int_to_str(nb_users);
  str = strcat(str, ":There are ");
  str = strcat(str, nbr);
  free(nbr);
  send_code_msg(s, fd, RPL_LUSERCLIENT,
		create_error_msg(str, " users and 0 invisible on 1 servers"));
  free(str);
  send_code_msg(s, fd, RPL_LUSEROP, strdup("0 :operators(s) online"));
  send_code_msg(s, fd, RPL_LUSERUNKNOWN, strdup("0 :unknown connection(s)"));
  nbr = nb_channel(s->channels);
  send_code_msg(s, fd, RPL_LUSERCHANNELS,
		create_error_msg(nbr, " :channels formed"));
  free(nbr);
  send_code_msg(s, fd, RPL_LUSERME, strdup(":I have 0 clients and 1 servers"));
}

void	welcome(t_server *server, int fd)
{
  _luser(server, fd);
  send_code_msg(server, fd, RPL_MOTDSTART,
		create_error_msg(":- log.horizon.sao",
				 " Message of the day -"));
  send_code_msg(server, fd, RPL_MOTD, strdup(":- It's our first irc server"));
  send_code_msg(server, fd, RPL_ENDOFMOTD, strdup(":End of /MOTD command"));
}
