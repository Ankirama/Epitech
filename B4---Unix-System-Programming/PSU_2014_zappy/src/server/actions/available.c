/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

/*
** @file available.c
** @brief actions from client (only available)
** @author ankirama
** @version 0.1
*/

#include "actions.h"

/*
** @brief it will send available in the current client's team
**
** @param server main struct
** @param fd file descriptor
** @param argv useless here
** @return 1
*/
int	cmd_available(t_server *server, int fd, char **argv)
{
  int	i;

  (void)argv;
  i = get_team_index(server->teams, server->nb_teams, server->client[fd].team);
  send_msg_nb(server, fd, "",
	      server->teams[i].max_players - server->teams[i].nb_players);
  return (1);
}
