/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Thu Jul  2 14:40:56 2015 CHARLES VITERBO
*/

/*
** @file fork.c
** @brief actions from client (only fork)
** @author ankirama
** @version 0.1
*/

#include "actions.h"

/*
** @brief create an egg and add it in server->forks
**
** @param server main structure
** @param fd current client's fd
** @param argv useless here
** @return 1
*/
int		cmd_fork(t_server *server, int fd, char **argv)
{
  t_fork	*tmp;

  (void)argv;
  if (!(tmp = my_malloc(sizeof(*tmp))))
    return (1);
  send_msg(server, fd, my_strdup("ok\n"));
  if (gettimeofday(&(tmp->time), NULL) == -1 ||
      !(tmp->team = my_strdup(server->client[fd].team)))
    {
      free(tmp);
      return (1);
    }
  tmp->position = server->client[fd].pos;
  tmp->id = server->forks->size;
  tmp->father = fd;
  egg_created(server, tmp->id, tmp);
  add_element(&(server->forks), tmp, 1);
  return (1);
}

/*
** @brief check if the egg hatched
**
** It will remove the current egg in s->forks and add it in the right team
** It will change max_players, and size of forks' list
**
** @param s main structure
** @return 1
*/
int		fork_egg(t_server *s)
{
  t_fork	*tmp;
  t_list	*del;
  int		index;

  if (s->forks == NULL || s->forks->size == 0 ||
      s->forks == s->forks->next)
    return (1);
  tmp = s->forks->next->data;
  if (is_time_elapsed(&(tmp->time), 600 * 1000 / s->time))
    {
      egg_hatched(s, tmp->id);
      index = get_team_index(s->teams, s->nb_teams, tmp->team);
      add_element(&(s->teams[index].forks), tmp, 1);
      --(s->forks->size);
      del = s->forks->next;
      s->forks->next = s->forks->next->next;
      free(del);
      ++(s->teams[index].max_players);
    }
  return (1);
}
