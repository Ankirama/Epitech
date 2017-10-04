/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 17:26:54 2015 CHARLES VITERBO
*/

/*
** @file check_fd.c
** @brief some functions about file decsriptor
** @author ankirama
** @version 1.0
*/

#include "check_fd.h"

/*
** @brief set server's fd
**
** @param server our server's structure
** @param fd our server's fd
*/
static int	_set_server_fd(t_server *server, int fd)
{
  FD_SET(fd, &(server->fd_read));
  FD_SET(fd, &(server->fd_write));
  server->fd_max = fd + 1;
  return (1);
}

/*
** @brief set client's fd
**
** @param server our server's structure
** @param fd our client's fd
*/
static void	_set_client_fd(t_server *server, int fd)
{
  int		ret_val;

  fork_egg(server);
  if (cmd_dead(server, fd, NULL) != 0)
    {
      if ((ret_val = interpret_message(server, fd)) == 0)
	{
	  server->fd_max = fd + 1;
	  FD_SET(fd, &(server->fd_read));
	  FD_SET(fd, &(server->fd_write));
	}
    }
}

/*
** @brief set graphic client's fd
**
** @param server our server's structure
** @param fd our client's fd
*/
static void	_set_gfx_fd(t_server *server, int fd)
{
  FD_SET(fd, &(server->fd_read));
  FD_SET(fd, &(server->fd_write));
  server->fd_max = fd + 1;
}

/*
** @brief: it will set our fd for select
**
** set fd_max to max fd + 1 (man select(2))
** It will check the death too for each client
**
** @param server our structure
** @param server_available 0 if no server available, else 1
** @param fd all fd, set to -1
** @return return -1 if no FD_SERVER, else 0
*/
int	set_fd(t_server *server, int server_available, int fd)
{
  server->fd_max = -1;
  FD_ZERO(&(server->fd_read));
  FD_ZERO(&(server->fd_write));
  while (++fd <= server->curr_max)
    {
      if (server->type_fd[fd] == FD_SERVER)
	server_available = _set_server_fd(server, fd);
      else if (server->type_fd[fd] == FD_CLIENT)
	_set_client_fd(server, fd);
      else if (server->type_fd[fd] == FD_GFX)
	_set_gfx_fd(server, fd);
    }
  if (server_available == 0)
    my_printf(2, "Error: no server opened.\n");
  return (server_available == 0 ? -1 : 0);
}
