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
** brief: it will set our ports from range min_port to max_port
** @server: our structure
** @min_port: the first port we will set (ex for 42:500 42 is min_port)
** @max_port: the last port we will set (ex for 42:500 500 is max_port)
** return: return 0
*/
static int	_default_port(t_server *server, int min_port, int max_port)
{
  int		i;

  if (!(server->ports = my_malloc(sizeof(int) * (max_port - min_port + 2))))
    exit(EXIT_FAILURE);
  i = -1;
  while (min_port + ++i <= max_port)
    server->ports[i] = min_port + i;
  server->ports[i] = -1;
  return (0);
}

/*
** brief: try to set a range, port need to be like 42:500
** @server: our structure
** @port: our port which contains a ':'
** BRIEF: if port is wrong (like 42:, :42, :, 100:1 ...) then default port used
** return: return 0
*/
static int	_range_port(t_server *server, char *port, int sep)
{
  char		*min;
  char		*max;
  int		min_p;
  int		max_p;

  if (!(min = strndup(port, sep)))
    {
      my_printf(2, "strdup: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  min_p = atoi(min);
  if (!(max = strdup(&port[sep + 1])))
    {
      my_printf(2, "strdup: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  max_p = atoi(max);
  if (strlen(min) == 0 || strlen(max) == 0 || max_p < min_p
      || min_p < 0)
    {
      my_printf(2, "Bad range (%s). Default port used (%d).\n", port,
		DEFAULT_PORT);
      return (_default_port(server, DEFAULT_PORT, DEFAULT_PORT));
    }
  return (_default_port(server, min_p, max_p));
}

/*
** brief: set our port(s) for start the server
** @server: our structure
** @port: argv[1] or NULL
** BRIEF: if port contains another char than 0 - 9 or : then default port used
** return: return 0
*/
int	set_ports(t_server *server, char *port)
{
  int	i;

  if (port == NULL)
    return (_default_port(server, DEFAULT_PORT, DEFAULT_PORT + NB_PORTS));
  i = 0;
  while (port[i] != '\0' && port[i] != ':' && port[i] >= '0' && port[i] <= '9')
    ++i;
  if (port[i] == ':')
    return (_range_port(server, port, i));
  if (port[i] != '\0')
    {
      my_printf(2, "Error wrong port (%s). Default port used (%d).\n", port,
		DEFAULT_PORT);
      return (_default_port(server, DEFAULT_PORT, DEFAULT_PORT));
    }
  return (_default_port(server, atoi(port), atoi(port)));
}
