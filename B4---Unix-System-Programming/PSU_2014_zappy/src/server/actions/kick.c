/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 16:07:22 2015 CHARLES VITERBO
*/

/*
** @file kick.c
** @brief actions from client (only fire)
** @author ankirama
** @version 0.1
*/

#include "actions.h"

/*
** brief move the client kicked
**
** @param server our server's structure
** @param fd ou client's fd
** @param position where the client has been kick
*/
static void	_change_coordinates(t_server *server, int fd,
				    unsigned int *position, t_client *client)
{
  int		dir;

  dir = server->client[fd].orientation;
  if (dir == DIR_UP)
    *position =
      server->client[fd].pos < server->map.width ?
      server->map.width * (server->map.height - 1) + server->client[fd].pos :
      server->client[fd].pos - server->map.width;
  else if (dir == DIR_DOWN)
    *position =
      server->client[fd].pos >= server->map.width * (server->map.height - 1) ?
      server->client[fd].pos % server->map.width :
      server->client[fd].pos + server->map.width;
  else if (dir == DIR_RIGHT)
    *position =
      server->client[fd].pos % server->map.width == server->map.width - 1 ?
      server->client[fd].pos - (server->map.width - 1) :
      server->client[fd].pos + 1;
  else
    *position =
      server->client[fd].pos % server->map.width == 0 ?
      server->client[fd].pos + server->map.width - 1 :
      server->client[fd].pos - 1;
  client->pos = *position;
}

 /*
 ** brief this function will move the clien
 **
 ** First we calculate the new client's coordinates
 ** Second we delete and add our client kicked to his new position
 ** Finaly we send the graphic and client messages
 **
 ** @param server our server's structure
 ** @param fd our client's fd
 ** @param client client to kick / move
 **
 ** @return
 */
 static int		_kick_client(t_server *server, int fd,
				      t_client *client, t_list **tmp)
 {
   unsigned int		position;
   int			direction;

   _change_coordinates(server, fd, &position, client);
  *tmp = (*tmp)->next;
  if (server->debug_mode)
    send_msg_nb(server, fd, "DEBUG -->kick : old position: ",
		server->client[fd].pos);
  remove_client(&server->map.map[server->client[fd].pos].players, client->fd);
  add_element(&server->map.map[position].players, client, 1);
  if (server->debug_mode)
    send_msg_nb(server, fd, "DEBUG -->kick : new position: ",
	        position);
  player_pos(server, client->fd);
  direction = difference_coord(server, client->fd, server->client[fd].pos,
			       position);
  send_msg_nbs(server, client->fd, "deplacement: ", direction);
  send_msg(server, client->fd, my_strdup("\n"));
  return (0);
}

/*
** brief command "expulse"
**
** It will kick all other client from the case
** they will move forward, depending on the kicker's orientation
**
** @param server our server's structure
** @param fd our client'fd
** @param argv to ignore
**
** @return 1
*/
int		cmd_fire(t_server *server, int fd, char **argv)
{
  t_list	*tmp;

  (void)argv;
  if (server->map.map[server->client[fd].pos].players->size != 1)
    {
      player_kick(server, fd);
      tmp = server->map.map[server->client[fd].pos].players->next;
      while (tmp != server->map.map[server->client[fd].pos].players)
	{
	  if (((t_client *)tmp->data)->fd != fd)
	    _kick_client(server, fd, (t_client *)tmp->data, &tmp);
	  else
	    tmp = tmp->next;
	}
      send_msg(server, fd, my_strdup("ok\n"));
    }
  else
    send_msg(server, fd, my_strdup("ko\n"));
  return (1);
}
