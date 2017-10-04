/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 16:08:30 2015 CHARLES VITERBO
*/

/*
** @file objects.c
** @brief actions from client (only objects)
** @author viterb_c
** @version 0.2
*/

# include "actions.h"

static t_objects	g_my_items[SIZE] =
  {
    {"linemate", ID_LINEMATE},
    {"deraumere", ID_DERAUMERE},
    {"sibur", ID_SIBUR},
    {"mendiane", ID_MENDIANE},
    {"phiras", ID_PHIRAS},
    {"thystame", ID_THYSTAME},
    {"nourriture", ID_MEAT},
    {NULL, -1}
  };

/*
** @brief find in our tab of t_objects the good type
**
** @param argv our command (type of object to find)
**
** @return on failure returns -1 otherwise returns the object's type
*/
static int	_find_type(char **argv)
{
  int		i;

  i = 0;
  if (argv != NULL && argv[0] != NULL)
    {
      while (g_my_items[i].name != NULL &&
	     strcmp(argv[0], g_my_items[i].name) != 0)
	++i;
      return (g_my_items[i].id);
    }
   return (-1);
}

/*
** @brief the player take an object on the map
**
** @param server our structure server
** @param fd the player's fd
** @param argv our command = object's type
**
** @return there is no failure or success so return 1 everytime
*/
int		cmd_take_obj(t_server *server, int fd, char **argv)
{
  int		type;
  unsigned int	quantity;
  int		pos;

  if ((type = _find_type(argv)) != -1 &&
      take_object(&server->map, server->client[fd].pos, type) == 1)
    {
      quantity = 1;
      if (type <= ID_THYSTAME)
	server->client[fd].inventaire[type]++;
      else
	server->client[fd].food++;
      pos = generate_object(&server->map,
			    server->map.height * server->map.width,
			    type, &quantity);
      get_cell(server, pos);
      send_msg(server, fd, my_strdup("ok\n"));
      player_take(server, fd, type);
      player_inventory(server, fd);
      get_cell(server, server->client[fd].pos);
    }
  else
    send_msg(server, fd, my_strdup("ko\n"));
  return (1);
}

/*
** @brief send to our graphic client the good instructions
** -> player's movement to take object
** -> player's inventory
** -> what is in the cell
**
** @param server our structure server
** @param fd player's fd
** @param type which stones' type the player has taken
*/
static void	_gfx_put_obj(t_server *server, int fd, int type)
{
  player_put(server, fd, type);
  player_inventory(server, fd);
  get_cell(server, server->client[fd].pos);
}

/*
** @brief the player put an object on the map
**
** @param server our structure server
** @param fd player's fd
** @param argv our command = object's type
**
** @return there is no failure or succes so return 1 everytime
*/
int	cmd_put_obj(t_server *server, int fd, char **argv)
{
  int	type;

  if ((type = _find_type(argv)) != -1)
    {
      if ((type <= ID_THYSTAME) &&
	  server->client[fd].inventaire[type] != 0)
	{
	  server->client[fd].inventaire[type]--;
	  send_msg(server, fd, my_strdup("ok\n"));
	  drop_object(&server->map, server->client[fd].pos, type);
	  _gfx_put_obj(server, fd, type);
	}
      else if (type == ID_MEAT && server->client[fd].food != 0)
	{
	  server->client[fd].food--;
	  send_msg(server, fd, my_strdup("ok\n"));
	  drop_object(&server->map, server->client[fd].pos, type);
	  _gfx_put_obj(server, fd, type);
	}
      else
	send_msg(server, fd, my_strdup("ko\n"));
    }
  else
    send_msg(server, fd, my_strdup("ko\n"));
  return (1);
}
