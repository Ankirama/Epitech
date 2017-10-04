/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 16:18:25 2015 CHARLES VITERBO
*/

/*
** @file player2.c
** @brief functions about player gfx
** @author ankirama
** @version 1.0
*/

#include "graphic_cmds.h"

/*
** @brief send pbc when a client broadcast
**
** @param server our server's structure
** @param idx our client's fd
*/
void	player_broadcast(t_server *server, int idx)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg_nb(server, i, "pbc ", idx);
	  nbr_log("pbc sent to", i, "player_broadcast", TYPE_INFO);
	}
    }
}

/*
** @brief send pfk when a client create an egg
**
** @param server our server's structure
** @param idx our client's fd
*/
void	player_egg(t_server *server, int idx)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg_nb(server, i, "pfk ", idx);
	  nbr_log("pfk sent to", i, "player_egg", TYPE_INFO);
	}
    }
}

/*
** @brief send pdr when a client put an object on the ground
**
** @param server our server's structure
** @param idx our client's fd
** @param id_obj our object's name
*/
void	player_put(t_server *server, int idx, int id_obj)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg_nbs(server, i, "pdr ", idx);
	  send_msg_nb(server, i, " ", id_obj);
	  nbr_log("pdr sent to", i, "player_put", TYPE_INFO);
	}
    }
}

/*
** @brief send pgt when a client take an object on the ground
**
** @param server our server's structure
** @param idx our client's fd
*/
void	player_take(t_server *server, int idx, int id_obj)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg_nbs(server, i, "pgt ", idx);
	  send_msg_nb(server, i, " ", id_obj);
	  nbr_log("pgt sent to", i, "player_take", TYPE_INFO);
	}
    }
}

/*
** @brief send pdi when a client died
**
** @param server our server's structure
** @param our client's fd
*/
void	player_dead(t_server *server, int idx)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg_nb(server, i, "pdi ", idx);
	  nbr_log("pdi sent to", i, "player_dead", TYPE_INFO);
	}
    }
}
