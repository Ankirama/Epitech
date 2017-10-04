/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Fri Feb 20 03:34:39 2015 Fabien Martinez
*/

#include "lemipc.h"

void	find_free(char *area, t_player *player)
{
  player->x = rand() % SIZE_AREA;
  player->y = rand() % SIZE_AREA;
  while (area[player->x * SIZE_AREA + player->y] != 0)
    {
      player->x = rand() % SIZE_AREA;
      player->y = rand() % SIZE_AREA;
    }
  area[player->x * SIZE_AREA + player->y] = player->team;
}

char	check_team(t_game *game)
{
  int	i;
  char	ok;

  i = -1;
  ok = 0;
  while (++i < MAX_TEAMS && ok < 2)
    ok = game->teams[i] >= 2 ? ok + 1 : ok;
  return (ok >= 2);
}

int	check_winner(t_game *game)
{
  int	i;
  int	id;
  char	available;

  i = -1;
  available = 0;
  id = 0;
  while (++i < MAX_TEAMS && available < 2)
    {
      if (game->teams[i] > 0)
	{
	  ++available;
	  id = i;
	}
    }
  return (available == 1 ? id + 1: 0);
}

static char	_random_team(int *teams, t_player *player, int id)
{
  if (id == 0 || id > MAX_TEAMS || teams[id - 1] >= MAX_PLAYERS)
    return (0);
  else
    {
      ++teams[id - 1];
      player->team = id;
      return (1);
    }
}

void	choose_team(int *teams, t_player *player, int id)
{
  int	i;

  if (!_random_team(teams, player, id))
    {
      if (teams[0] > teams[1])
	player->team = 2;
      else if ((teams[0] < teams[1]) ||
	       (teams[0] == teams[1] && teams[0] < MAX_PLAYERS))
	player->team = 1;
      else
	{
	  i = 2;
	  while (i + 1 < MAX_TEAMS && teams[i] == MAX_PLAYERS)
	    ++i;
	  if (i < MAX_TEAMS)
	    player->team = i + 1;
	  else
	    print_error(ERR_TEAMS);
	}
      ++teams[player->team - 1];
    }
}
