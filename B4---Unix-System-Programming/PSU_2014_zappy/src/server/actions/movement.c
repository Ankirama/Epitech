/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sat Jul  4 16:11:23 2015 CHARLES VITERBO
*/

/*
** @file movement.c
** @brief actions from client (only movement)
** @author ankirama
** @version 0.1
*/

#include "actions.h"

/*
** @brief set new position in terms of current direction
**
** @param server main structure
** @param fd file descriptor
*/
static void	_move_forward(t_server *server, int fd)
{
  int		dir;

  dir = server->client[fd].orientation;
  if (dir == DIR_UP)
    server->client[fd].pos =
      server->client[fd].pos < server->map.width ?
      server->map.width * (server->map.height - 1) + server->client[fd].pos :
      server->client[fd].pos - server->map.width;
  else if (dir == DIR_DOWN)
    server->client[fd].pos =
      server->client[fd].pos >= server->map.width * (server->map.height - 1) ?
      server->client[fd].pos % server->map.width :
      server->client[fd].pos + server->map.width;
  else if (dir == DIR_RIGHT)
    server->client[fd].pos =
      server->client[fd].pos % server->map.width == server->map.width - 1 ?
      server->client[fd].pos - (server->map.width - 1) :
      server->client[fd].pos + 1;
  else
    server->client[fd].pos =
      server->client[fd].pos % server->map.width == 0 ?
      server->client[fd].pos + server->map.width - 1 :
      server->client[fd].pos - 1;
}

/*
** @brief set a new position for the client and send ok
**
** Debug mode add more informations (old/new position)
**
** @param server main structure
** @param fd file descriptor
** @param argv useless here
** @return 1
*/
int	cmd_up(t_server *server, int fd, char **argv)
{
  (void)argv;
  if (server->debug_mode)
    send_msg_nb(server, fd, "DEBUG-->old position: ", server->client[fd].pos);
  remove_client(&server->map.map[server->client[fd].pos].players, fd);
  _move_forward(server, fd);
  if (server->debug_mode)
    send_msg_nb(server, fd, "DEBUG-->new position: ", server->client[fd].pos);
  if (add_element(&server->map.map[server->client[fd].pos].players,
		  &server->client[fd], 1) == 0)
    {
      send_msg(server, fd, my_strdup("ok\n"));
      player_pos(server, fd);
    }
  else
    send_msg(server, fd, my_strdup("ko\n"));
  return (1);
}

/*
** @brief set a new direction (-90 deg) for the client and send ok
**
** Debug mode add more informations (old/new direction)
**
** @param server main structure
** @param fd file descriptor
** @param argv useless here
** @return 1
*/
int	cmd_left(t_server *server, int fd, char **argv)
{
  (void)argv;
  if (server->debug_mode)
    send_msg_nb(server, fd, "DEBUG-->old orientation: ",
		server->client[fd].orientation);
  server->client[fd].orientation = MOVE_LEFT(server->client[fd].orientation);
  if (server->debug_mode)
    send_msg_nb(server, fd, "DEBUG-->new orientation: ",
		server->client[fd].orientation);
  send_msg(server, fd, my_strdup("ok\n"));
  player_pos(server, fd);
  return (1);
}

/*
** @brief set a new direction (90 deg) for the client and send ok
**
** Debug mode add more informations (old/new direction)
**
** @param server main structure
** @param fd file descriptor
** @param argv useless here
** @return 1
*/
int	cmd_right(t_server *server, int fd, char **argv)
{
  (void)argv;
  if (server->debug_mode)
    send_msg_nb(server, fd, "DEBUG-->old orientation: ",
		server->client[fd].orientation);
  server->client[fd].orientation = MOVE_RIGHT(server->client[fd].orientation);
  if (server->debug_mode)
    send_msg_nb(server, fd, "DEBUG-->new orientation: ",
		server->client[fd].orientation);
  send_msg(server, fd, my_strdup("ok\n"));
  player_pos(server, fd);
  return (1);
}
