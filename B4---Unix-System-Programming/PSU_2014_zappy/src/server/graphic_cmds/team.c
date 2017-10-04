/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 17:24:38 2015 CHARLES VITERBO
*/

/*
** @file player.c
** @brief functions about player gfx
** @author ankirama
** @version 1.0
*/

#include "graphic_cmds.h"

/*
** @brief send the teams' names
**
** @param server our server's structure
*/
void	team_names(t_server *server)
{
  int	i;
  int	j;

  for (i = 0; i < server->nb_teams; ++i)
    {
      for (j = 0; j <= server->curr_max; ++j)
	{
	  if (server->type_fd[j] == FD_GFX)
	    {
	      send_msg_str(server, j, "tna ", server->teams[i].name);
	      nbr_log("tna sent to", j, "team_names", TYPE_INFO);
	    }
	}
    }
}
