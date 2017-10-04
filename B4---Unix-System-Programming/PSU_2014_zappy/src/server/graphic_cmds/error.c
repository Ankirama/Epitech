/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 15:40:23 2015 CHARLES VITERBO
*/

/*
** @file error.c
** @brief functions about error gfx
** @author ankirama
** @version 1.0
*/

#include "graphic_cmds.h"

/*
** @brief send suc when an unknown command is send
**
** @param server our server's structure
*/
void	unknown_cmd(t_server *server)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg(server, i, my_strdup("suc\n"));
	  nbr_log("suc sent to", i, "unknown_cmd", TYPE_INFO);
	}
    }
}

/*
** @brief send sbp when a command is invalid
**
** @param server our server's structure
*/
void	wrong_cmd(t_server *server)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg(server, i, my_strdup("sbp\n"));
	  nbr_log("sbp sent to", i, "wrong_cmd", TYPE_INFO);
	}
    }
}
