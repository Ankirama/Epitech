/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 17:24:11 2015 CHARLES VITERBO
*/

/*
** @file server.c
** @brief functions about server gfx
** @author ankirama
** @version 1.0
*/

#include "graphic_cmds.h"

/*
** @brief send sgt and the time's unit
**
** @param server server's structure
** @param time time's unit
*/
void	server_get_time(t_server *server, int time)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg_nb(server, i, "sgt ", time);
	  nbr_log("sgt sent to", i, "server_get_time", TYPE_INFO);
	}
    }
}

/*
** @brief send seg and the team's name of the winner
**
** @param server our server's structure
** @param winning team's name
*/
void	server_winner(t_server *server, char *team)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg_str(server, i, "seg ", team);
	  nbr_log("seg sent to", i, "server_winner", TYPE_INFO);
	}
    }
}

/*
** @brief send smg and the message
**
** @param server our server's structure
** @param msg the message to send
*/
void	server_message(t_server *server, char *msg)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg_str(server, i, "smg ", msg);
	  nbr_log("smg sent to", i, "server_message", TYPE_INFO);
	}
    }
}
