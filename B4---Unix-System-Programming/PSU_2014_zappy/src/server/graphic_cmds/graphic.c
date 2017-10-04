/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 16:08:54 2015 CHARLES VITERBO
*/

/*
** @file graphic.c
** @brief some functions about graphic client
** @author ankirama
** @version 1.0
*/

#include "graphic_cmds.h"

/*
** @brief send pnw, positio, orientation, level and team when
** a client connects
**
** @param s our server's structure
** @param idx our client's fd
** @prama fd_gfx our client graphic fd
*/
static void	_player_new(t_server *s, int idx, int fd_gfx)
{
  send_msg_nbs(s, fd_gfx, "pnw ", idx);
  send_msg_nbs(s, fd_gfx, " ", s->client[idx].pos % s->map.width);
  send_msg_nbs(s, fd_gfx, " ", s->client[idx].pos / s->map.width);
  send_msg_nbs(s, fd_gfx, " ", s->client[idx].orientation);
  send_msg_nbs(s, fd_gfx, " ", s->client[idx].level);
  send_msg_str(s, fd_gfx, " ", s->client[idx].team);
  nbr_log("pnw sent to", fd_gfx, "_player_new", TYPE_INFO);
}

/*
** @brief send pin and the player's inventory
**
** @param s our server's structure
** @param idx our client's fd
** @param fd_gfx our client graphic fd
*/
static void	_player_inventory(t_server *s, int idx, int fd_gfx)
{
  int		j;

  send_msg_nbs(s, fd_gfx, "pin ", idx);
  send_msg_nbs(s, fd_gfx, " ", s->client[idx].pos % s->map.width);
  send_msg_nbs(s, fd_gfx, " ", s->client[idx].pos / s->map.width);
  send_msg_nbs(s, fd_gfx, " ", s->client[idx].food);
  for (j = 0; j < NB_OBJ - 1; ++j)
    send_msg_nbs(s, fd_gfx, " ", s->client[idx].inventaire[j]);
  send_msg_nb(s, fd_gfx, " ", s->client[idx].inventaire[ID_THYSTAME]);
  nbr_log("pin sent to", fd_gfx, "player_inventory", TYPE_INFO);
}

/*
** @brief set and send welcome graphic client
**
** It will send basics message to help graphic client to get some informations
** @param server main structure
** @param fd current client file descriptor
** @return 1
*/
int	set_graphic_client(t_server *s, int fd, int i, int j)
{
  nbr_log("GRAPHIC client:", fd, "set_graphic_client", TYPE_INFO);
  s->type_fd[fd] = FD_GFX;
  s->client[fd].graphic = 1;
  s->client[fd].fd = fd;
  s->client[fd].created = 1;
  map_size(s);
  server_get_time(s, s->time);
  get_all_cells(s);
  team_names(s);
  for (j = 0; j <= s->curr_max; ++j)
    {
      if (s->type_fd[j] == FD_GFX)
	{
	  for (i = 0; i <= s->curr_max; ++i)
	    {
	      if (s->type_fd[i] == FD_CLIENT && s->client[i].team)
		{
		  _player_new(s, i, j);
		  _player_inventory(s, i, j);
		}
	    }
	}
    }
  return (0);
}
