/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Fri Mar  6 22:56:39 2015 Fabien Martinez
*/

#include "server.h"

static int	_set_error_code(t_server *s, int fd, char *channel)
{
  int		code;
  t_channel	*tmp;

  code = 0;
  if (!channel)
    code = ERR_NEEDMOREPARAMS;
  else if ((tmp = get_channel(s->channels, channel)) != NULL &&
	   tmp->nb_users == MAX_USERS)
    code = ERR_CHANNELISFULL;
  else if (s->client[fd].nb_channels == MAX_CHANNELS)
    code = ERR_TOOMANYCHANNELS;
  else if (channel[0] != '#')
    code = ERR_NOSUCHCHANNEL;
  return (code);
}

static char	*_check_error(char *channel, int code)
{
  char		*err;

  err = NULL;
  if (code == ERR_NEEDMOREPARAMS)
    err = strdup("JOIN :Not enough parameters");
  else if (code == ERR_CHANNELISFULL)
    err = create_error_msg(channel, " :Cannot join channel (+l)");
  else if (code == ERR_NOSUCHCHANNEL)
    err = create_error_msg(channel, " :No such channel");
  else if (code == ERR_TOOMANYCHANNELS)
    err = create_error_msg(channel, ":You have joined too many channels");
  return (err);
}

char		*get_user_list(t_server *server, char *channel)
{
  char		*lst;
  t_channel	*chan;
  t_list	*tmp;

  if ((chan = get_channel(server->channels, channel)) == NULL ||
      chan->clients->size == 0)
    return (NULL);
  else
    {
      lst = my_malloc(strlen(channel) + strlen(" :") + strlen("= ") +
		      chan->clients->size + nb_elements(chan->clients) + 1);
      lst[0] = '\0';
      lst = strcat(lst, "= ");
      lst = strcat(lst, channel);
      lst = strcat(lst, " :");
      tmp = chan->clients->next;
      while (tmp != chan->clients)
	{
	  lst = strcat(lst, tmp->data);
	  if (tmp->next != chan->clients)
	    lst = strcat(lst, " ");
	  tmp = tmp->next;
	}
      return (lst);
    }
}

/*
** return: return 1 if channel is in list, else 0
*/
static char	_check_exist(t_list *list, char *channel)
{
  t_list	*tmp;

  tmp = list->next;
  while (tmp != list && strcmp(tmp->data, channel) != 0)
    tmp = tmp->next;
  return (tmp != list);
}

int		cmd_join(t_server *server, int fd, char **argv)
{
  int		code;
  t_channel	*tmp;
  char		*end;

  if ((code = _set_error_code(server, fd, argv == NULL ? NULL : argv[0])) != 0)
    send_code_msg(server, fd, code,
	       _check_error(argv == NULL ? NULL : argv[0], code));
  else if (!_check_exist(server->client[fd].channels, argv[0]))
    {
      if (!(tmp = get_channel(server->channels, argv[0])))
	add_channel(&(server->channels), argv[0]);
      add_element(&(get_channel(server->channels, argv[0])->clients),
		  server->client[fd].nick);
      add_element(&(server->client[fd].channels), argv[0]);
      get_channel(server->channels, argv[0])->nb_users += 1;
      send_code_msg(server, fd, RPL_NAMREPLY, get_user_list(server, argv[0]));
      end = my_malloc(strlen(argv[0]) + strlen(" :End of /NAMES list") + 1);
      end[0] = '\0';
      end = strcat(end, argv[0]);
      end = strcat(end, " :End of /NAMES list");
      send_code_msg(server, fd, RPL_ENDOFNAMES, end);
    }
  return (0);
}
