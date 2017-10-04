/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 00:16:11 2015 CHARLES VITERBO
*/

/*
** @file interpret_message.c
** @brief interpret message send by a client
** @author ankirama
** @version 1.0
*/

#include "interpret_message.h"

static t_function	g_fct_zappy[NB_FCT_ZAPPY] = {
  {"avance", cmd_up, 7},
  {"droite", cmd_right, 7},
  {"gauche", cmd_left, 7},
  {"voir", cmd_show, 7},
  {"inventaire", cmd_inventory, 1},
  {"prend", cmd_take_obj, 7},
  {"pose", cmd_put_obj, 7},
  {"expulse", cmd_fire, 7},
  {"broadcast", cmd_broadcast, 7},
  {"incantation", cmd_incantation, 300},
  {"fork", cmd_fork, 42},
  {"connect_nbr", cmd_available, 0},
  {"debug", cmd_debug, 5}};

/*
** @brief convert list to a string
**
** Check malloc / strdup
**
** @param list our list we will convert
** @return string created
*/
static char	*_recompose_message(t_list *list)
{
  char		*msg;
  t_list	*tmp;

  if ((msg = my_malloc(list->size + 1)) == NULL)
    return (NULL);
  msg[0] = '\0';
  tmp = list->next;
  while (tmp != list)
    {
      msg = strcat(msg, tmp->data);
      tmp = tmp->next;
    }
  if (strlen(msg) == 0)
    {
      free(msg);
      return (NULL);
    }
  return (msg);
}

/*
** @brief change from the second string (to the end) and concat' these strings
**
** example: arr = "broadcast" "this" "is" "an" "example" "here"
** it will be converted to arr = "broadcast" "this is an example here"
** Check malloc / strdup
**
** @param arr our array we will convert
** @param i index set to 0. Used to concat
** @param elt used to set number element. Set to -1
** @return new array if we have more than one string in our array or arr
*/
static char	**_recompose_tokens(char **arr, int i, int elt)
{
  char		**token;

  if (arr && arr[0] && arr[1] && strcmp(arr[0], "broadcast") == 0)
    {
      if (!(token = my_malloc(sizeof(char *) * (3))) ||
	  !(token[0] = my_strdup(arr[0])))
	return (free_wordtab(arr));
      while (arr[++i])
	++elt;
      if (!(token[1] = my_malloc(1 + elt * strlen(" ") + array_len(&arr[1]))))
	return (free_wordtab(arr));
      token[1][0] = '\0';
      i = 0;
      while (arr[++i] != NULL)
	{
	  token[1] = strcat(token[1], arr[i]);
	  if (arr[i + 1] != NULL)
	    token[1] = strcat(token[1], " ");
	}
      token[2] = NULL;
      free_wordtab(arr);
      return (token);
    }
  else
    return (!arr || !arr[0] ? NULL : arr);
}

/*
** @brief check if we can exec the command or if it already executed
**
** @param server main structure
** @param fd current client
** @param token our command (with arguments)
** @param index currecnt index for good command
** @return 0 if timer started, 1 else
*/
static int	_exec_command(t_server *server, int fd, char **token, int index)
{
  int		return_value;

  if (server->client[fd].time_cmd == -1 && g_fct_zappy[index].exec_time != 0)
    {
      if (strcmp(token[0], "debug") == 0 && server->debug_mode == 0)
	return (1);
      if (strcmp(g_fct_zappy[index].name, "incantation") == 0 &&
	  g_fct_zappy[index].fct_zappy(server, fd, &token[1]) == 0)
	return (1);
      if (strcmp(g_fct_zappy[index].name, "fork") == 0)
	player_egg(server, fd);
      gettimeofday(&server->client[fd].start_cmd, NULL);
      server->client[fd].time_cmd =
	g_fct_zappy[index].exec_time * 1000 / server->time;
      return (0);
    }
  else
    {
      return_value = g_fct_zappy[index].fct_zappy(server, fd, &token[1]);
      server->client[fd].time_cmd = -1;
      return (return_value);
    }
}

/*
** @brief Interpret our message and execute our command
**
** It will recompose our message and tokens and check our token[0] to exec cmd
**
** @param server main structure
** @param fd file descriptor
** @param list our list we will recompose
** @param i index init to 0
** @return 1 if the exec time is done, else 0 or -1 (or -2) in any error
*/
static int	_interpret_message(t_server *server, int fd, t_list *list,
				   int i)
{
  char		*msg;
  char		**token;
  int		error;

  if (!(msg = _recompose_message(list)) ||
      !(token = _recompose_tokens(str_to_wordtab(msg, ' ', ' '), 0, -1)))
    return (-1);
  if ((error = check_creation_client(server, fd, token, msg)) != 1)
    {
      free_wordtab(token);
      if (error == -1)
	close_connection(server, fd);
      return (error == 0 ? 1 : (error == 2 ? -2 : -1));
    }
  while (i < NB_FCT_ZAPPY && strcmp(g_fct_zappy[i].name, token[0]) != 0)
    ++i;
  if (token != NULL && token[0] != NULL && i < NB_FCT_ZAPPY)
    error = _exec_command(server, fd, token, i);
  else
    error = send_msg(server, fd, my_strdup("ko\n")) == 0 ? 1 : -1;
  nbr_log(i == NB_FCT_ZAPPY ? "ko": msg, fd, "_interpret_message",
	  TYPE_INFO);
  free(msg);
  free_wordtab(token);
  return (error);
}

/*
** @brief check if there is any cmd to interpret and execute it
**
** @param server main structure
** @param fd current user
** @return 0 if no problem, else 1 and -1 if connection already close
*/
int		interpret_message(t_server *server, int fd)
{
  int		return_val;
  t_list	*tmp;
  t_list	*del_me;

  return_val = 0;
  if (server->client[fd].cmds->size == 0)
    return (0);
  if (is_time_elapsed(&server->client[fd].start_cmd,
		      server->client[fd].time_cmd))
    return_val = _interpret_message(server, fd,
				    server->client[fd].cmds->next->data, 0);
  if (return_val != 0 && return_val != -2 && server->type_fd[fd] == FD_CLIENT)
    {
      --(server->client[fd].cmds->size);
      tmp = server->client[fd].cmds->next;
      server->client[fd].cmds->next = server->client[fd].cmds->next->next;
      del_me = tmp->data;
      let_it_go(&del_me);
      free(tmp);
    }
  return (return_val == -1 ? 1 : (return_val == -2 ? -1 : 0));
}
