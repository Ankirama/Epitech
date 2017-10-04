/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Mar  8 17:01:33 2015 CHARLES VITERBO
*/

#include "lemipc.h"

char	is_pos_ok(char *area, int x, int y, t_player *player)
{
  if (x < 0 || x >= SIZE_AREA || y < 0 || y >= SIZE_AREA ||
      area[x * SIZE_AREA + y] != 0 || (player->x == x && player->y == y))
    return (0);
  return (1);
}

static char	_square_ok(int x, int y, t_player *player)
{
  if (x < 0 || x >= SIZE_AREA || y < 0 || y >= SIZE_AREA ||
      (player->x == x && player->y == y))
    return (0);
  return (1);
}

void	set_pos(t_player *player, t_game *game, int i, int j)
{
  game->map[player->x * SIZE_AREA + player->y] = 0;
  game->map[i * SIZE_AREA + j] = player->team;
  player->x = i;
  player->y = j;
}

static char	_check_pos(t_player *player, t_game *game, int id, int foes)
{
  int		i;
  int		j;

  id = -1;
  while (++id < MAX_TEAMS)
    {
      i = player->x - 2;
      foes = 0;
      while (id != player->team - 1 && ++i < player->x + 2)
	{
	  j = player->y - 2;
	  while (++j < player->y + 2)
	    {
	      if (_square_ok(i, j, player) &&
		  game->map[i * SIZE_AREA + j] == id + 1)
		++foes;
	    }
	}
      if (foes >= 2)
	return (1);
    }
  return (0);
}

void	change_pos(t_player *player, t_game *game)
{
  if (player->team != 0)
    {
      if (_check_pos(player, game, 0, 0))
	{
	  game->map[player->x * SIZE_AREA + player->y] = 0;
	  --game->teams[player->team - 1];
	  player->team = 0;
	}
      else
	move(player, game);
    }
}
