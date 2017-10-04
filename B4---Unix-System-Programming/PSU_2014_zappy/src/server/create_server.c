/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 17:40:03 2015 CHARLES VITERBO
*/

#include "create_server.h"

/*
** @brief set fd limit, port(s) and init fd area
**
** @param server main structure
** @param port like 42:500 (range port)
** @return 0 if any error, else -1
*/
static int	_set_server_fd(t_server *server, char *port)
{
  struct rlimit	rl;

  if (getrlimit(RLIMIT_NOFILE, &rl) == -1)
    {
      nbr_log("getrlimit error, default value used:",
	      MAX_FD, "_set_server_fd", TYPE_ERROR);
      server->nb_fd = MAX_FD;
    }
  else
    server->nb_fd = rl.rlim_cur;
  if (!(server->write_buffer =
	my_malloc(sizeof(*server->write_buffer) * server->nb_fd)) ||
      !(server->type_fd =
	my_malloc(sizeof(server->type_fd) * server->nb_fd)) ||
      !(server->fct_read =
	my_malloc(sizeof(*server->fct_read) * server->nb_fd)) ||
      !(server->fct_write =
	my_malloc(sizeof(*server->fct_write) * server->nb_fd)) ||
      !(server->client =
	my_malloc(sizeof(*server->client) * server->nb_fd)))
    return (-1);
  memset(server->type_fd, FD_FREE, sizeof(int) * server->nb_fd);
  server->curr_max = 0;
  return (set_ports(server, port));
}

/*
** @brief change port when we can't listen
**
** @param s our server's structure
** @param i our current port
** @param sck the socket
** @param j a port
**
** @return -1 if we reached our MAX_PORT or 0
*/
static int	_change_port(t_server *s, int i, int sck, int j)
{
  t_sockaddr_in	sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(s->ports[i]);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (s->ports[i] <= 1023)
    {
      nbr_log("port to low (1 - 1023 not allowed) :", s->ports[i],
	      "_change_port", TYPE_ERROR);
      s->ports[i] = 1024;
    }
  while (s->ports[i] < MAX_PORT && my_bind(sck, (const t_sockaddr *)&sin,
					   sizeof(sin), s->ports[i]) == -1)
    {
      ++s->ports[i];
      sin.sin_port = htons(s->ports[i]);
    }
  while (s->ports[j] != -1)
    {
      s->ports[j] = s->ports[j - 1];
      ++j;
    }
  return (s->ports[i] == MAX_PORT ? -1 : 0);
}

/*
** @brief it will set our server
**
** we will check every fd form our range ports and set good function
** for read and write.
** we will set our ports
** if we try to set more than max fd then we will stop to set them
** and warn the user
**
** @param s our structure we will set
** @param port argv[1] like 42:500 (range port)
** @param i index used to travel array of port
** @param sck socket fd
** @return -1 if any problem, else 0
*/
int	create_server(t_server *s, char *port, int i, int sck)
{
  if (_set_server_fd(s, port) == -1 || !(s->forks = create_root()))
    return (-1);
  while (sck < s->nb_fd && s->ports[++i] != -1 && i < 10)
    {
      if ((sck = my_s(AF_INET, SOCK_STREAM, my_name("TCP")->p_proto))
	  >= s->nb_fd)
	break;
      if (_change_port(s, i, sck, i + 1) == -1)
	{
	  i = -1;
	  break;
	}
      nbr_log("Server started on port", s->ports[i], "create_server",
	      TYPE_INFO);
      my_printf(1, "Server started on port %d\n", s->ports[i]);
      my_listen(sck, s->nb_fd);
      s->type_fd[sck] = FD_SERVER;
      s->fct_read[sck] = read_server;
      s->fct_write[sck] = 0;
      s->curr_max = sck < s->curr_max ? s->curr_max : sck;
    }
  if (sck >= s->nb_fd || i == -1)
    my_close(sck);
  return (0);
}
