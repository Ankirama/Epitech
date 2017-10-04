/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 17:14:31 2015 CHARLES VITERBO
*/

/*
** @file player.c
** @brief functions about player gfx
** @author ankirama
** @version 1.0
*/

#include "graphic_cmds.h"

/*
** @brief send pnw, x, y, orientation, level and team
**
** @param s our server's structure
** @param idx our client's fd
*/
void	player_new(t_server *s, int idx)
{
  int	i;

  for (i = 0; i <= s->curr_max; ++i)
    {
      if (s->type_fd[i] == FD_GFX)
	{
	  send_msg_nbs(s, i, "pnw ", idx);
	  send_msg_nbs(s, i, " ", s->client[idx].pos % s->map.width);
	  send_msg_nbs(s, i, " ", s->client[idx].pos / s->map.width);
	  send_msg_nbs(s, i, " ", s->client[idx].orientation);
	  send_msg_nbs(s, i, " ", s->client[idx].level);
	  send_msg_str(s, i, " ", s->client[idx].team);
	  nbr_log("pnw sent to", i, "player_new", TYPE_INFO);
	}
    }
}

/*
** @brief send ppo, x, y and orientation
**
** @param s our server's structure
** @param idx our client's fd
*/
void	player_pos(t_server *s, int idx)
{
  int	i;

  if (idx > 0 && s->type_fd[idx] == FD_CLIENT)
    {
      for (i = 0; i <= s->curr_max; ++i)
	{
	  if (s->type_fd[i] == FD_GFX)
	    {
	      send_msg_nbs(s, i, "ppo ", idx);
	      send_msg_nbs(s, i, " ", s->client[idx].pos % s->map.width);
	      send_msg_nbs(s, i, " ", s->client[idx].pos / s->map.width);
	      send_msg_nb(s, i, " ", s->client[idx].orientation);
	      nbr_log("ppo sent to", i, "player_pos", TYPE_INFO);
	    }
	}
    }
  else
    wrong_cmd(s);
}

/*
** @brief send plv and player level
**
** @param server our server's structure
** @param id our client's fd
*/
void	player_level(t_server *server, int idx)
{
  int	i;

  if (idx > 0 && server->type_fd[idx] == FD_CLIENT)
    {
      for (i = 0; i <= server->curr_max; ++i)
	{
	  if (server->type_fd[i] == FD_GFX)
	    {
	      send_msg_nbs(server, i, "plv ", idx);
	      send_msg_nb(server, i, " ", server->client[idx].level);
	      nbr_log("plv sent to", i, "player_level", TYPE_INFO);
	    }
	}
    }
  else
    wrong_cmd(server);
}

/*
** @brief send pin, x, y, food and inventory
**
** @brief server our server's structure
** @brief idx our client's fd
*/
void	player_inventory(t_server *s, int idx)
{
  int	i;
  int	j;

  if (idx > 0 && s->type_fd[idx] == FD_CLIENT)
    {
      for (i = 0; i <= s->curr_max; ++i)
	{
	  if (s->type_fd[i] == FD_GFX)
	    {
	      send_msg_nbs(s, i, "pin ", idx);
	      send_msg_nbs(s, i, " ", s->client[idx].pos % s->map.width);
	      send_msg_nbs(s, i, " ", s->client[idx].pos / s->map.width);
	      send_msg_nbs(s, i, " ", s->client[idx].food);
	      for (j = 0; j < NB_OBJ - 1; ++j)
		send_msg_nbs(s, i, " ", s->client[idx].inventaire[j]);
	      send_msg_nb(s, i, " ", s->client[idx].inventaire[ID_THYSTAME]);
	      nbr_log("pin sent to", i, "player_inventory", TYPE_INFO);
	    }
	}
    }
  else
    wrong_cmd(s);
}

/*
** @brief send pex when a player kick
**
** @param s our server's structure
** @param idx our client's fd
*/
void	player_kick(t_server *s, int idx)
{
  int	i;

  for (i = 0; i <= s->curr_max; ++i)
    {
      if (s->type_fd[i] == FD_GFX)
	{
	  send_msg_nb(s, i, "pex ", idx);
	  nbr_log("pex sent to", i, "player_kick", TYPE_INFO);
	}
    }
}
