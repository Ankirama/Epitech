/*
** main.c<2> for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

#include "server.h"

/*
** brief: it will set our fd for select(2)
** @server: our structure
** return: return -1 if no FD_SERVER, else 0
** BRIEF: set fd_max to max fd + 1 (man select(2))
*/
static int	_set_fd(t_server *server, int server_available)
{
  int		fd;

  fd = -1;
  server->fd_max = -1;
  FD_ZERO(&(server->fd_read));
  FD_ZERO(&(server->fd_write));
  while (++fd < MAX_FD)
    {
      if (server->type_fd[fd] == FD_SERVER)
	{
	  FD_SET(fd, &(server->fd_read));
	  FD_SET(fd, &(server->fd_write));
	  server->fd_max = fd + 1;
	  server_available = 1;
	}
      else if (server->type_fd[fd] == FD_CLIENT)
	{
	  FD_SET(fd, &(server->fd_read));
	  FD_SET(fd, &(server->fd_write));
	  server->fd_max = fd + 1;
	}
    }
  if (server_available == 0)
    my_printf(2, "Error: no server opened.\n");
  return (server_available == 0 ? -1 : 0);
}

static void	_check_fd(t_server *server)
{
  int		i;

  i = -1;
  while (++i < MAX_FD)
    {
      if (FD_ISSET(i, &(server->fd_read)))
	server->fct_read[i](server, i);
      if (server->type_fd[i] == FD_CLIENT && FD_ISSET(i, &(server->fd_write)))
	server->fct_write[i](server, i);
    }
}

/*
** brief: main function, it'll init our server and loop
** @argc: nb arguments
** @argv: array of arguments
** return: 0 (EXIT_SUCCESS)
*/
int		main(int argc, char **argv)
{
  t_server	server;
  int		error;

  create_server(&server, argc == 2 ? argv[1] : NULL, -1, 0);
  check_signal(server.type_fd);
  while ((error = _set_fd(&server, 0)) != -1)
    {
      if (select(server.fd_max, &(server.fd_read), &(server.fd_write), NULL,
		 &(server.timeout)) == -1)
	{
	  my_printf(2, "select: %s\n", strerror(errno));
	  break;
	}
      _check_fd(&server);
    }
  if (error != -1)
    close_server(server.type_fd);
  free(server.ports);
  free_channels(&(server.channels));
  return (EXIT_SUCCESS);
}
