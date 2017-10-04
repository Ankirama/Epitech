/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sat Jul  4 16:21:55 2015 CHARLES VITERBO
*/

/*
** @file show.c
** @brief actions from client (only show)
** @author ankirama
** @version 0.1
*/

#include "actions.h"

/*
** @brief it will browse the map, depending the character's level,
** when the character
** is looking at the top of the map
**
** @param server our structure server
** @param fd our client's fd
*/
static void	_check_top(t_server *server, int fd)
{
  int		i;
  int		j;
  int		x;
  int		y;

  send_msg(server, fd, my_strdup("{"));
  for (j = 0; j <= server->client[fd].level; ++j)
    {
      y = server->client[fd].pos / server->map.width - j;
      y = restrain_number(y, server->map.height);
      for (i = -j; i <= j; ++i)
	{
	  x = server->client[fd].pos % server->map.width + i;
	  x = restrain_number(x, server->map.width);
	  if (server->debug_mode)
	    send_msg_nbs(server, fd, "pos : ", x + y * server->map.width);
          send_case(server, fd, &server->map.map[x + y * server->map.width]);
	  if (j == server->client[fd].level && i == j)
	    send_msg(server, fd, my_strdup("}\n"));
	  else
	    send_msg(server, fd, my_strdup(","));
	}
    }
}

/*
** @brief it will browse the map, depending the character's level,
** when the character
** is looking at the low of the map
**
** @param server our structure server
** @param fd our client's fd
*/
static void	_check_bot(t_server *server, int fd)
{
  int		i;
  int		j;
  int		x;
  int		y;

  send_msg(server, fd, my_strdup("{"));
  for (j = 0; j <= server->client[fd].level; ++j)
    {
      y = server->client[fd].pos / server->map.width + j;
      y = restrain_number(y, server->map.height);
      for (i = j; i >= -j; --i)
	{
	  x = server->client[fd].pos % server->map.width + i;
	  x = restrain_number(x, server->map.width);
	  if (server->debug_mode)
	    send_msg_nbs(server, fd, "pos : ", x + y * server->map.width);
	  send_case(server, fd, &server->map.map[x + y * server->map.width]);
	  if (j == server->client[fd].level && i == -j)
	    send_msg(server, fd, my_strdup("}\n"));
	  else
	    send_msg(server, fd, my_strdup(","));
	}
    }
}

/*
** @brief it will browse the map, depending the character's level,
** when the character
** is looking at the left of the map
**
** @param server our structure server
** @param fd our client'fd
*/
static void	_check_left(t_server *server, int fd)
{
  int		i;
  int		j;
  int		x;
  int		y;

  send_msg(server, fd, my_strdup("{"));
  for (i = 0; i <= server->client[fd].level; ++i)
    {
      x = server->client[fd].pos % server->map.width - i;
      x = restrain_number(x, server->map.width);
      for (j = i; j >= -i; --j)
	{
	  y = server->client[fd].pos / server->map.width + j;
	  y = restrain_number(y, server->map.height);
	  if (server->debug_mode)
	    send_msg_nbs(server, fd, "pos : ", x + y * server->map.width);
	  send_case(server, fd, &server->map.map[x + y * server->map.width]);
	  if (i == server->client[fd].level && j == -i)
	    send_msg(server, fd, my_strdup("}\n"));
	  else
	    send_msg(server, fd, my_strdup(","));
	}
    }
}

/*
** @brief it will browse the map, depending the character's level,
** when the character
** is looking at the right of the map
**
** @param server our structure server
** @param fd our client's fd
*/
static void	_check_right(t_server *server, int fd)
{
  int		i;
  int		j;
  int		x;
  int		y;

  send_msg(server, fd, my_strdup("{"));
  for (i = 0; i <= server->client[fd].level; ++i)
    {
      x = server->client[fd].pos % server->map.width + i;
      x = restrain_number(x, server->map.width);
      for (j = -i; j <= i; ++j)
	{
	  y = server->client[fd].pos / server->map.width + j;
	  y = restrain_number(y, server->map.height);
	  if (server->debug_mode)
	    send_msg_nbs(server, fd, "pos : ", x + y * server->map.width);
	  send_case(server, fd, &server->map.map[x + y * server->map.width]);
	  if (j == server->client[fd].level && i == j)
	    send_msg(server, fd, my_strdup("}\n"));
	  else
	    send_msg(server, fd, my_strdup(","));
	}
    }
}

/*
** @brief command show, will send to the client what is
** infront of him. The vision depends of the IA's level and
** orientation
**
** @param server our structure server
** @param fd our client'fd
** @param argv to ignore
** @return 1
*/
int		cmd_show(t_server *server, int fd, char **argv)
{
  static fct	func[4] = {_check_top, _check_right, _check_bot, _check_left};

  (void)argv;
  func[server->client[fd].orientation](server, fd);
  return (1);
}
