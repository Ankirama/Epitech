/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 17:33:58 2015 CHARLES VITERBO
*/

/*
** @file create_client.c
** @brief some functions about client creation
** @author ankirama
** @version 1.0
*/

#include "create_client.h"


/*
** @brief set a position (random) for our new client
**
** @param s our server's structure
** @param idx our client's fd
**
** @return position
*/
static unsigned int	_set_position(t_server *s, int idx)
{
  unsigned int		position;
  t_fork		*tmp;
  t_list		*del;

  position = random_number(s->map.width * s->map.height);
  if (s->teams[idx].forks->size > 0)
    {
      --(s->teams[idx].forks->size);
      tmp = s->teams[idx].forks->next->data;
      egg_connected(s, tmp->id);
      position = tmp->position;
      del = s->teams[idx].forks->next;
      s->teams[idx].forks->next = s->teams[idx].forks->next->next;
      free(tmp->team);
      free(del);
    }
  return (position);
}

/*
** @brief add a new client to our server
**
** @param s our server's structure
** @param fd our client's fd
** @param arr team's name
** @param idx team's number
**
** @return -1 if error or 0
*/
int		add_client(t_server *s, int fd, char **arr, int idx)
{
  unsigned int	position;

  ++(s->teams[idx].nb_players);
  s->client[fd].playerId = s->teams[idx].nb_players;
  if (!(s->client[fd].team = my_strdup(arr[0])) ||
      add_element(&(s->teams[idx].players), &(s->client[fd]), 1) ||
      send_nbrs(s, fd, s->map.width, s->map.height) == -1)
    return (-1);
  s->client[fd].created = 1;
  gettimeofday(&s->client[fd].start_life, NULL);
  position = _set_position(s, idx);
  s->client[fd].pos = position;
  if (add_element(&s->map.map[position].players, &s->client[fd],
		  1) == 1)
    return (-1);
  nbr_log("Player new position:", s->client[fd].pos, "add_client", TYPE_INFO);
  player_new(s, fd);
  return (0);
}
