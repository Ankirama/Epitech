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

static void	_list_one(t_server *server, t_channel *lst, int fd,
			  char *channel)
{
  char		*nb_users;
  char		*msg;

  if (lst == NULL)
    send_code_msg(server, fd, ERR_NOSUCHNICK,
		  create_error_msg(channel, " :No such nick/channel"));
  else
    {
      nb_users = int_to_str(nb_elements(lst->clients));
      msg = my_malloc(strlen(channel) + 1 +
		      strlen(nb_users) + strlen(" :") + 1);
      msg[0] = '\0';
      msg = strcat(msg, channel);
      msg = strcat(msg, " ");
      msg = strcat(msg, nb_users);
      msg = strcat(msg, " :");
      free(nb_users);
      send_code_msg(server, fd, RPL_LIST, msg);
    }
}

static void	_list_all(t_server *server, int fd)
{
  t_channel	*tmp;

  tmp = server->channels;
  while (tmp != NULL)
    {
      _list_one(server, tmp, fd, tmp->name);
      tmp = tmp->next;
    }
}

static void	_check_list(t_server *server, int fd, char *channels)
{
  int		begin;
  int		end;
  int		size;
  char		*tmp;

  begin = 0;
  end = 0;
  while (channels[end] != '\0')
    {
      begin = end;
      size = 0;
      while (channels[end] != '\0' && channels[end] != ',')
	{
	  ++end;
	  ++size;
	}
      tmp = strndup(&channels[begin], size);
      _list_one(server, get_channel(server->channels, tmp), fd, tmp);
      free(tmp);
      end = channels[end] == '\0' ? end : end + 1;
    }
}

int	cmd_list(t_server *server, int fd, char **argv)
{
  send_code_msg(server, fd, RPL_LISTSTART, strdup("Channel :Users  Name"));
  if (argv == NULL || argv[0] == NULL)
    _list_all(server, fd);
  else
    _check_list(server, fd, argv[0]);
  send_code_msg(server, fd, RPL_LISTEND, strdup(":End of /LIST"));
  return (0);
}
