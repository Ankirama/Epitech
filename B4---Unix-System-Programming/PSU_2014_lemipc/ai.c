/*
** ai.c for  in /home/viterb_c/rendu/PSU_2014_lemipc
** 
** Made by CHARLES VITERBO
** Login   <viterb_c@epitech.net>
** 
** Started on  Sat Mar  7 16:27:59 2015 CHARLES VITERBO
** Last update Sun Mar  8 17:01:42 2015 CHARLES VITERBO
*/

#include "lemipc.h"

static void	_where_to_move(t_player *player, t_game *game)
{
  int		where;

  where = random() % 4;
  if (where == 0 &&
      is_pos_ok(game->map, player->x - 1, player->y, player) == 1)
    set_pos(player, game, player->x - 1, player->y);
  else if (where == 1 &&
	   is_pos_ok(game->map, player->x + 1, player->y, player) == 1)
    set_pos(player, game, player->x + 1, player->y);
  else if (where == 2 &&
	   is_pos_ok(game->map, player->x, player->y - 1, player) == 1)
    set_pos(player, game, player->x, player->y - 1);
  else if (where == 3 &&
	   is_pos_ok(game->map, player->x, player->y + 1, player) == 1)
    set_pos(player, game, player->x, player->y + 1);

}

void	move(t_player *player, t_game *game)
{
  if ((player->x > SIZE_AREA / 2) &&
      is_pos_ok(game->map, player->x - 1, player->y, player) == 1)
    set_pos(player, game, player->x - 1, player->y);
  else if ((player->x < SIZE_AREA / 2) &&
	   is_pos_ok(game->map, player->x + 1, player->y, player) == 1)
    set_pos(player, game, player->x + 1, player->y);
  else if ((player->y > SIZE_AREA / 2) &&
	   is_pos_ok(game->map, player->x, player->y - 1, player) == 1)
    set_pos(player, game, player->x, player->y - 1);
  else if ((player->y < SIZE_AREA / 2) &&
	   is_pos_ok(game->map, player->x, player->y + 1, player) == 1)
    set_pos(player, game, player->x, player->y + 1);
  else
    _where_to_move(player, game);
}
