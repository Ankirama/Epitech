/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 16:06:44 2015 CHARLES VITERBO
*/

/*
** @file map.c
** @brief functions about map gfx
** @author ankirama
** @version 1.0
*/

#include "graphic_cmds.h"

/*
** @brief send the map's size to the graphic client
**
** @param server our server's structure
*/
void	map_size(t_server *server)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg_nbs(server, i, "msz ", server->map.width);
	  send_msg_nb(server, i, " ", server->map.height);
	  nbr_log("msz sent to", i, "map_size", TYPE_INFO);
	}
    }
}

/*
** @brief send bct and all informations on a cell to the graphic client
**
** @param server our server's structure
** @param idx the cell's position
*/
void	get_cell(t_server *server, int idx)
{
  int	i;
  int	j;

  if (idx >= 0 && (unsigned int)idx < server->map.width * server->map.height)
    {
      for (i = 0; i <= server->curr_max; ++i)
	{
	  if (server->type_fd[i] == FD_GFX)
	    {
	      send_msg_nbs(server, i, "bct ", idx % server->map.width);
	      send_msg_nbs(server, i, " ", idx / server->map.width);
	      send_msg_nbs(server, i, " ", server->map.map[idx].food);
	      for (j = 0; j < NB_OBJ - 1; ++j)
		send_msg_nbs(server, i, " ", server->map.map[idx].stones[j]);
	      send_msg_nb(server, i, " ",
			  server->map.map[idx].stones[ID_THYSTAME]);
	      nbr_log("bct sent to", i, "get_cell", TYPE_INFO);
	    }
	}
    }
  else
    wrong_cmd(server);
}

/*
** @brief send all cases' informations to the graphic's client
**
** @param server our server's structure
*/
void		get_all_cells(t_server *server)
{
  unsigned int	i;

  for (i = 0; i < server->map.width * server->map.height; ++i)
    get_cell(server, i);
}
