/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 15:35:15 2015 CHARLES VITERBO
*/

/*
** @file egg.c
** @brief functions about egg gfx
** @author ankirama
** @version 1.0
*/

#include "graphic_cmds.h"

/*
** @brief send eht at all the graphic client
**
** @param server our server's structure
** @param idx our client's fd
*/
void	egg_hatched(t_server *server, int idx)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg_nb(server, i, "eht ", idx);
	  nbr_log("eht sent to", i, "egg_hatched", TYPE_INFO);
	}
    }
}

/*
** @brief send ebo when a client replaces an egg
**
** @param server our server's structure
** @param idx ou client's fd
*/
void	egg_connected(t_server *server, int idx)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg_nb(server, i, "ebo ", idx);
	  nbr_log("ebo sent to", i, "egg_connected", TYPE_INFO);
	}
    }
}

/*
** @brief send edi when a egg died (not use)
**
** @param server our server's structure
** @param idx our client's fd
*/
void	egg_died(t_server *server, int idx)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg_nb(server, i, "edi ", idx);
	  nbr_log("edi sent to", i, "egg_died", TYPE_INFO);
	}
    }
}

/*
** @brief send enw and others infos when an egg is created
**
** @param server our server's structure
** @param idx our client's fd
** @param fork egg's informations
*/
void	egg_created(t_server *server, int idx, t_fork *fork)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg_nbs(server, i, "enw ", idx);
	  send_msg_nbs(server, i, " ", fork->father);
	  send_msg_nbs(server, i, " ", fork->position % server->map.width);
	  send_msg_nb(server, i, " ", fork->position / server->map.width);
	  nbr_log("enw sent to", i, "egg_created", TYPE_INFO);
	}
    }
}
