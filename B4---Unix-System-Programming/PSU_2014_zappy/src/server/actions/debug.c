/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sat Jul  4 05:04:37 2015 Alexandre Chenevier
*/

/*
** @file debug.c
** @brief special mode to debug and display all infos
** @author ankirama
** @version 1.0
*/

# include "actions.h"

/*
** @brief send a message with number (without newline)
**
** @param server main structure
** @param fd file descriptor
** @param msg message to send
** @param nb number to send
*/
void	send_msg_nbs(t_server *server, int fd, char *msg, int nb)
{
  char	*tmp;
  char	*tmp_nb;

  tmp = my_malloc(strlen(msg) + str_nbr(nb) + 1);
  tmp[0] = '\0';
  tmp = strcat(tmp, msg);
  tmp_nb = int_to_str(nb);
  tmp = strcat(tmp, tmp_nb);
  free(tmp_nb);
  send_msg(server, fd, tmp);
}

/*
** @brief send msg with a number (with newline)
**
** @param server main struct
** @param fd file descriptor
** @msg message we will send
** @nb number in the end of the message
*/
int	send_msg_nb(t_server *server, int fd, char *msg, int nb)
{
  char	*tmp;
  char	*tmp_nb;

  if (!(tmp = my_malloc(strlen(msg) + str_nbr(nb) + strlen("\n") + 1)))
    return (-1);
  tmp[0] = '\0';
  tmp = strcat(tmp, msg);
  tmp_nb = int_to_str(nb);
  tmp = strcat(tmp, tmp_nb);
  free(tmp_nb);
  tmp = strcat(tmp, "\n");
  return (send_msg(server, fd, tmp));
}

/*
** @brief concat 2 msg to send (with newline)
**
** @param server main struct
** @param fd file descriptor
** @param msg first message
** @param str second message
*/
void	send_msg_str(t_server *server, int fd, char *msg, char *str)
{
  char	*tmp;

  if (msg != NULL && str != NULL)
    {
      tmp = my_malloc(strlen(msg) + strlen(str) + strlen("\n") + 1);
      tmp[0] = 0;
      tmp = strcat(tmp, msg);
      tmp = strcat(tmp, str);
      tmp = strcat(tmp, "\n");
      send_msg(server, fd, tmp);
    }
}

/*
** @brief send a list of cmds
**
** @param server main struct
** @param fd file descriptor
*/
static void	_send_list(t_server *server, int fd)
{
  t_list	*tmp;
  t_list	*cmds;

  send_msg(server, fd, my_strdup("---START CMDS LIST---\n"));
  cmds = server->client[fd].cmds->next;
  while (cmds != server->client[fd].cmds)
    {
      tmp = ((t_list *)cmds->data)->next;
      while (tmp != cmds->data)
	{
	  add_element(&(server->write_buffer[fd]), strdup(tmp->data),
		      strlen(tmp->data));
	  add_element(&(server->write_buffer[fd]), strdup("\n"), 1);
	  tmp = tmp->next;
	}
      cmds = cmds->next;
    }
  send_msg(server, fd, my_strdup("---END CMDS LIST---\n"));
}

/*
** @brief special comamnd to send infos
**
** @param server main structure
** @param fd file descriptor
** @param argv useless here
*/
int	cmd_debug(t_server *server, int fd, char **argv)
{
  (void)argv;
  send_msg_nb(server, fd, "DEBUG [ON]:\nfd client: ", fd);
  send_msg_nb(server, fd, "playerID: ", server->client[fd].playerId);
  send_msg_str(server, fd, "teamName: ", server->client[fd].team);
  send_msg_nb(server, fd, "position: ", server->client[fd].pos);
  send_msg_nb(server, fd, "level: ", server->client[fd].level);
  send_msg_nb(server, fd, "initialised: ", server->client[fd].created);
  _send_list(server, fd);
  send_msg_nb(server, fd, "time_cmd: ", (int)(server->client[fd].time_cmd));
  send_msg(server, fd, my_strdup("DEBUG [OFF]\n"));
  close_connection(server, fd);
  return (1);
}
