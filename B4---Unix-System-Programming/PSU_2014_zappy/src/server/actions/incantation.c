/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 12:42:53 2015 CHARLES VITERBO
*/

/*
** @file incantation.c
** @brief actions from client (only incantation)
** @author ankirama
** @version 0.1
*/

# include "actions.h"

static unsigned int	g_tab_level_up[NB_LVL][7] =
  {
    {1, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 0, 0, 2},
    {2, 0, 1, 0, 2, 0, 2},
    {1, 1, 2, 0, 1, 0, 4},
    {1, 2, 1, 3, 0, 0, 4},
    {1, 2, 3, 0, 1, 0, 6},
    {2, 2, 2, 2, 2, 1, 6}
  };

/*
** brief check the number of players and their levels
** and the number of stones
**
** @param cell where the incantation has been launch
** @param level current client's level
**
** @return 1 if conditions are not good otherwise 0
*/
static int	_check_players_and_stones(t_case *cell, int level)
{
  t_list	*tmp;
  unsigned int	nbr;

  nbr = 0;
  if (cell->players->size != g_tab_level_up[level -1][ID_PLAYER])
    return (1);
  tmp = cell->players->next;
  while (tmp != cell->players)
    {
      nbr++;
      if (((t_client *)tmp->data)->level != level)
	return (1);
      tmp = tmp->next;
    }
  if (g_tab_level_up[level - 1][ID_PLAYER] != nbr)
    return (1);
  if (cell->stones[ID_LINEMATE] != g_tab_level_up[level - 1][ID_LINEMATE] ||
      cell->stones[ID_DERAUMERE] != g_tab_level_up[level -1][ID_DERAUMERE] ||
      cell->stones[ID_SIBUR] != g_tab_level_up[level - 1][ID_SIBUR] ||
      cell->stones[ID_MENDIANE] != g_tab_level_up[level -1][ID_MENDIANE] ||
      cell->stones[ID_PHIRAS] != g_tab_level_up[level -1][ID_PHIRAS] ||
      cell->stones[ID_THYSTAME] != g_tab_level_up[level - 1][ID_THYSTAME])
    return (1);
  return (0);
}

/*
** brief delete all stones on cell
**
** @param cell our incantation's cell
*/
static void	_delete_stones(t_case *cell)
{
  cell->stones[ID_LINEMATE] = 0;
  cell->stones[ID_DERAUMERE] = 0;
  cell->stones[ID_SIBUR] = 0;
  cell->stones[ID_MENDIANE] = 0;
  cell->stones[ID_PHIRAS] = 0;
  cell->stones[ID_THYSTAME] = 0;
}

/*
** @brief check the conditions at the end of incantation
**
** If conditions are not good send "ko\n" to the client otherwise
** it will send the new level to all the clients
**
** @param server our server's structure
** @param fd our client's fd
*/
static void	_launch_incantation(t_server *server, int fd)
{
  int		level;
  t_list	*tmp;

  level = 0;
  if ( _check_players_and_stones(&server->map.map[server->client[fd].pos],
				 server->client[fd].level) == 1)
    send_msg(server, fd, my_strdup("ko\n"));
  else
    {
      player_end_incant(server, fd, level);
      level = server->client[fd].level + 1;
      _delete_stones(&server->map.map[server->client[fd].pos]);
      get_cell(server, server->client[fd].pos);
      tmp = server->map.map[server->client[fd].pos].players->next;
      while (tmp != server->map.map[server->client[fd].pos].players)
	{
	  send_msg_nbs(server, ((t_client *)tmp->data)->fd,
		       my_strdup("niveau actuel : "), level);
	  send_msg(server, ((t_client *)tmp->data)->fd, my_strdup("\n"));
	  ((t_client *)tmp->data)->level = level;
	  player_level(server, ((t_client *)tmp->data)->fd);
	  increase_level_max(server, (t_client *)tmp->data);
	  tmp = tmp->next;
	}
    }
}

/*
** @brief launch an incantation to level-up
**
** @param server our server's structure
** @param fd our client's fd
** @param argv to ignore
**
** @return 0 when conditions are not good at the beginning otherwise 1
*/
int	cmd_incantation(t_server *server, int fd, char **argv)
{
  (void)argv;
  if (server->client[fd].time_cmd == -1 &&
      (_check_players_and_stones(&server->map.map[server->client[fd].pos],
				 server->client[fd].level) == 1))
    {
      send_msg(server, fd, my_strdup("ko\n"));
      return (0);
    }
  else if (server->client[fd].time_cmd == -1)
    {
      send_msg(server, fd, my_strdup("elevation en cours\n"));
      player_start_incant(server, fd);
    }
  else
    _launch_incantation(server, fd);
  return (1);
}
