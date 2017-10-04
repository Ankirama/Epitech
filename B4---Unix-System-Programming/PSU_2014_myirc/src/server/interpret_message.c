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

static t_function	g_fct_irc[NB_FCT_IRC] = {{cmd_nick, "NICK"},
						 {cmd_join, "JOIN"},
						 {cmd_part, "PART"},
						 {cmd_names, "NAMES"},
						 {cmd_list, "LIST"},
						 {cmd_privmsg, "PRIVMSG"},
						 {cmd_users, "USERS"},
						 {cmd_quit, "QUIT"}};

static char	*_recompose_message(t_list *list)
{
  char		*msg;
  t_list	*tmp;

  msg = my_malloc(list->size + 1);
  msg[0] = '\0';
  tmp = list->next;
  while (tmp != list)
    {
      msg = strcat(msg, tmp->data);
      tmp = tmp->next;
    }
  return (msg);
}

static char	**_recompose_tokens(char **arr, int i, int nb_elt)
{
  char		**token;

  if (arr && arr[0] && arr[1] && arr[2] && arr[2][0] == ':')
    {
      token = my_malloc(sizeof(char *) * (4));
      token[0] = strdup(arr[0]);
      token[1] = strdup(arr[1]);
      while (arr[++i])
	++nb_elt;
      token[2] = my_malloc(1 + nb_elt * strlen(" ") + array_len(&arr[2]));
      i = 1;
      token[2][0] = '\0';
      while (arr[++i])
	{
	  token[2] = strcat(token[2], arr[i]);
	  if (arr[i + 1])
	    token[2] = strcat(token[2], " ");
	}
      token[3] = NULL;
      free_wordtab(arr);
      return (token);
    }
  else
    return (arr);
}

int	interpret_message(t_server *server, int fd, t_list *list)
{
  char	*msg;
  char	**token;
  int	i;
  int	error;

  msg = _recompose_message(list);
  token = _recompose_tokens(str_to_wordtab(msg, ' ', ' '), 1, -1);
  my_printf(1, "Client %d: [%s]\r\n", fd, msg);
  free(msg);
  i = 0;
  error = 0;
  while (token && token[0] && i < NB_FCT_IRC &&
	 strcmp(g_fct_irc[i].name, token[0]) != 0)
    ++i;
  if (token != NULL && token[0] != NULL && i < NB_FCT_IRC)
    error = g_fct_irc[i].fct_irc(server, fd, &token[1]);
  else if (token && token[0])
    {
      msg = create_error_msg(token[0], " :Unknown command");
      send_code_msg(server, fd, ERR_UNKNOWNCOMMAND, msg);
    }
  free_wordtab(token);
  return (error);
}
