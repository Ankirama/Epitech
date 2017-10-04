/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sat Jul  4 18:56:13 2015 CHARLES VITERBO
*/

/*
** @file welcome.c
** @brief send a welcome message for each new connexion
** @author ankirama
** @version 1.0
*/

#include "welcome.h"

/*
** @brief close the connection with the client if
** there is no more place in team or wrong team's name
**
** @param s our main structure
** @param fd our client's fd
** @ return 2
*/
static int	_close_connection(t_server *s, int fd)
{
  my_printf(fd, "ko\n");
  s->type_fd[fd] = FD_GFX;
  close_connection(s, fd);
  return (2);
}

/*
** @brief check if current client is already in a team
**
** if we can create our new client then we will create it
**
** @param ser main struct with all informations
** @param fd used to check current client
** @param arr tokens with command(s) from client
** @return 1 if already set, else 0
*/
int	check_creation_client(t_server *s, int fd, char **arr, char *msg)
{
  int	idx;
  int	plrs;

  if (s->client[fd].created == 1)
    return (1);
  plrs = 0;
  free(msg);
  if (!strcmp(arr[0], GRAPHIC_CLIENT))
    return (set_graphic_client(s, fd, 0, 0));
  if ((idx = get_team_index(s->teams, s->nb_teams, arr[0])) == -1)
    plrs = -1;
  plrs = plrs == -1 ? -1 : s->teams[idx].max_players -
    (s->teams[idx].nb_players + 1);
  if (plrs >= 0)
    {
      if (send_msg_nb(s, fd, "", plrs) == -1)
	return (-1);
      return (add_client(s, fd, arr, idx));
    }
  else
    return (_close_connection(s, fd));
  return (0);
}

/*
** @brief It will send a basic welcome message on each connexion
**
** @param server server's structure with every info needed
** @param fd client's fd used to communicate with him
*/
void	welcome(t_server *server, int fd)
{
  send_msg(server, fd, my_strdup("BIENVENUE\n"));
}
