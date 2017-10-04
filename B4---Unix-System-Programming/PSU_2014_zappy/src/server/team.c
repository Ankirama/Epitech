/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 12:28:58 2015 CHARLES VITERBO
*/

/*
** @file team.c
** @brief functions about team
** @author ankirama
** @version 1.0
*/

#include "team.h"

/*
** @brief remove a player from his current team
**
** It will check if the client is in a team and remove it form this one.
** It will decrease number level max if the current client was level max
**
** @param server main structure
** @fd file descriptor
*/
void		remove_player(t_server *server, int fd)
{
  int		i;
  t_list	*tmp;

  i = get_team_index(server->teams, server->nb_teams, server->client[fd].team);
  if (i < server->nb_teams)
    {
      tmp = server->teams[i].players;
      while (tmp->next != server->teams[i].players &&
	     tmp->next->data != &server->client[fd])
	tmp = tmp->next;
      if (tmp->next->data == &server->client[fd])
	tmp->next = tmp->next->next;
      --(server->teams[i].nb_players);
      if (server->client[fd].level == LVL_MAX)
	--(server->teams[i].nb_lvl_max);
    }
}

/*
** @brief get index team
**
** @param teams teams array
** @param nb_teams numbeer teams in this array
** @param name_team the team we need index
** @return the index if we found the team, else -1
*/
int	get_team_index(t_team *teams, int nb_teams, char *name_team)
{
  int	i;

  i = 0;
  if (name_team == NULL)
    return (nb_teams);
  while (i < nb_teams && strcmp(teams[i].name, name_team))
    ++i;
  return (i < nb_teams ? i : -1);
}

/*
** @brief found best level in a team
**
** Currently useless
**
** @param team then team we want to find best level
** @return the best level found
*/
int		better_level_team(t_team *team)
{
  t_list	*tmp;
  t_client	*client_tmp;
  int		better_level;

  better_level = 0;
  tmp = team->players->next;
  while (tmp != team->players)
    {
      client_tmp = tmp->data;
      better_level = client_tmp->level > better_level ? client_tmp->level :
	better_level;
      tmp = tmp->next;
    }
  return (better_level);
}

/*
** @brief create a team and set default values
**
** @param s main structure
** @param i index for current team to set
** @param opt_arg options needed to set default values
** @return -1 if any error, else 0
*/
int	create_team(t_server *s, int i, t_opt_arg *opt_arg)
{
  if (!(s->teams[i].name = my_strdup(opt_arg->teams[i])) ||
      !(s->teams[i].players = create_root()))
    return (-1);
  s->teams[i].nb_lvl_max = 0;
  s->teams[i].nb_players = 0;
  s->teams[i].max_players = s->client_start;
  if (!(s->teams[i].forks = create_root()))
    return (-1);
  return (0);
}

/*
** @brief increase the number of players of max level in a team
**
** @param s server's structure
** @param cleint our client
*/
void	increase_level_max(t_server *s, t_client *client)
{
  int	team;

  if (client->level == 8 &&
      (team = get_team_index(s->teams, s->nb_teams, client->team)) != -1)
    s->teams[team].nb_lvl_max++;
}
