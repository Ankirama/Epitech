/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 18:40:33 2015 CHARLES VITERBO
*/

/*
** @file broadcast.c
** @brief actions from client (only broadcast)
** @author ankirama
** @version 0.1
*/

# include "actions.h"

/*
** @brief difference x coordinates
**
** @param x_org client who send the message
** @param x_dst client who receive the message
** @param width our map's width
**
** @return RIGHT or LEFT / 0 if nothing
*/
static int	_diff_x(int x_org, int x_dst, int width)
{
  if ((x_dst < x_org &&
       abs(x_dst - x_org) > abs(x_dst + width - x_org))
      || (x_dst > x_org &&
	  abs(x_dst - x_org) < abs(x_dst - (x_org + width))))
    return (LEFT);
  else if ((x_dst < x_org &&
	    abs(x_dst - x_org) < abs(x_dst + width - x_org))
	   || (x_dst > x_org &&
	       abs(x_dst - x_org) > abs(x_dst - (x_org + width))))
    return (RIGHT);
  else
    return (RIGHT);
  return (0);
}

/*
** @brief differnce y coordinate
**
** @param y_org client who send the message
** @param y_dst client who receive the message
** @param height our map's height
**
** @return UP or DOWN / 0 if nothing
*/
static int	_diff_y(int y_org, int y_dst, int height)
{
  if ((y_dst < y_org &&
       abs(y_dst - y_org) > abs(y_dst + height - y_org))
      || (y_dst > y_org &&
	  abs(y_dst - y_org) < abs(y_dst - (y_org + height))))
    return (UP);
  else if ((y_dst < y_org &&
	    abs(y_dst - y_org) < abs(y_dst + height - y_org))
	   || (y_dst > y_org &&
	       abs(y_dst - y_org) > abs(y_dst - (y_org + height))))
    return (DOWN);
  else
    return (DOWN);
  return (0);
}

/*
** @brief difference x and y
**
** @param server our server's structure
** @param org client who send the message
** @param dst client who receive the message
**
** @return the direction
*/
static int	_diff_diagonale(t_server *server, unsigned int org,
				unsigned int dst)
{
  int		x_org;
  int		y_org;
  int		x_dst;
  int		y_dst;

  x_org = org % server->map.width;
  x_dst = dst % server->map.width;
  y_org = org / server->map.width;
  y_dst = dst / server->map.width;
  if (_diff_x(x_org, x_dst, server->map.width) == LEFT &&
      _diff_y(y_org, y_dst, server->map.height) == UP)
    return (DG_UP_LEFT);
  else if (_diff_x(x_org, x_dst, server->map.width) == LEFT &&
	   _diff_y(y_org, y_dst, server->map.height) == DOWN)
    return (DG_DOWN_LEFT);
  else if (_diff_x(x_org, x_dst, server->map.width) == RIGHT &&
	   _diff_y(y_org, y_dst, server->map.height) == UP)
    return (DG_UP_RIGHT);
  else if (_diff_x(x_org, x_dst, server->map.width) == RIGHT &&
	   _diff_y(y_org, y_dst, server->map.height) == DOWN)
    return (DG_DOWN_RIGHT);
  return (0);
}

/*
** brief it will calculate the message's direction
**
** @param server our server's structure
** @param org the client who send the message
** @param dst the client who receive the message
**
** @return the direction
*/
int	difference_coord(t_server *server, int fd,
			 unsigned org, unsigned int dst)
{
  int	x_org;
  int	y_org;
  int	x_dst;
  int	y_dst;
  int	direction;

  x_org = org % server->map.width;
  x_dst = dst % server->map.width;
  y_org = org / server->map.width;
  y_dst = dst / server->map.width;
  if (x_org == x_dst && y_org == y_dst)
    return (0);
  else if (abs(x_org - x_dst) == 1 && abs(y_org - y_dst) > 2)
    direction = _diff_y(y_org, y_dst, server->map.height);
  else if (abs(y_org - y_dst) == 1 && abs(x_org - x_dst) > 2)
    direction = _diff_x(x_org, x_dst, server->map.width);
  else if (x_org == x_dst && y_org != y_dst)
    direction = _diff_y(y_org, y_dst, server->map.height);
  else if (x_org != x_dst && y_org == y_dst)
    direction = _diff_x(x_org, x_dst, server->map.width);
  else
    direction = _diff_diagonale(server, org, dst);
  direction = direction + 2 * server->client[fd].orientation;
  return (direction == 8 ? direction : direction % 8);
}

/*
** brief will send to all our client, except whom send it
**
** @param server our server's structure
** @param fd our client's fd
** @param argv our message
**
** @return 1
*/
int	cmd_broadcast(t_server *server, int fd, char **argv)
{
  int	i;
  int	direction;

  i = -1;
  if (argv != NULL && argv[0] != NULL)
    {
      while (++i <= server->curr_max)
	{
	  if (server->type_fd[i] == FD_CLIENT && i != fd)
	    {
	      direction = difference_coord(server, i, server->client[fd].pos,
					   server->client[i].pos);
	      send_msg_nbs(server, i, "message ", direction);
	      send_msg(server, i, my_strdup(","));
	      send_msg(server, i, my_strdup(argv[0]));
	      send_msg(server, i, my_strdup("\n"));
	    }
	}
      player_broadcast(server, fd);
      send_msg(server, fd, my_strdup("ok\n"));
    }
  else
    send_msg(server, fd, my_strdup("ko\n"));
  return (1);
}
