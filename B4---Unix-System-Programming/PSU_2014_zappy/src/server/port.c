/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

/*
** @file port.h
** @brief functions to load / create ports
** @author ankirama
** @version 1.0
*/

#include "port.h"

/*
** @brief it will set our ports from range min_port to max_port
**
** @param server our structure
** @param min_port the first port we will set (ex for 42:500 42 is min_port)
** @param max_port the last port we will set (ex for 42:500 500 is max_port)
** @return 0 if no problem, else -1
*/
static int	_default_port(t_server *server, int min_port, int max_port)
{
  int		i;

  if (!(server->ports = my_malloc(sizeof(int) * (max_port - min_port + 2))))
    return (-1);
  i = -1;
  while (min_port + ++i <= max_port)
    server->ports[i] = min_port + i;
  server->ports[i] = -1;
  return (0);
}

/*
** @brief try to set a range, port need to be like 42:500
**
** if port is wrong (like 42:, :42, :, 100:1 ...) then default port used
**
** @param server our structure
** @param port our port which contains a ':'
** @param sep index of ':'
** return: return 0 or -1 if any error
*/
static int	_range_port(t_server *server, char *port, int sep)
{
  char		*min;
  char		*max;
  int		min_p;
  int		max_p;

  if (!(min = strndup(port, sep)))
    {
      cmd_log(strerror(errno), "_range_port", xdate(), TYPE_ERROR);
      return (-1);
    }
  min_p = atoi(min);
  if (!(max = my_strdup(&port[sep + 1])))
    {
      cmd_log(strerror(errno), "_range_port", xdate(), TYPE_ERROR);
      return (-1);
    }
  max_p = atoi(max);
  if (strlen(min) == 0 || strlen(max) == 0 || max_p < min_p
      || min_p < 0)
    {
      nbr_log("Bad range used. Default port used",
	      DEFAULT_PORT, "_range_port", TYPE_ERROR);
      return (_default_port(server, DEFAULT_PORT, DEFAULT_PORT));
    }
  return (_default_port(server, min_p, max_p));
}

/*
** @brief set our port(s) for start the server
**
** if port contains another char than 0 - 9 or : then default port used
** @param server our structure
** @param port argv[1] or NULL
** @return 0 or -1 if any error
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
      nbr_log("Wrong port used. Default port used",
	      DEFAULT_PORT, "set_ports", TYPE_ERROR);
      return (_default_port(server, DEFAULT_PORT, DEFAULT_PORT));
    }
  return (_default_port(server, atoi(port), atoi(port)));
}
