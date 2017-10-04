/*
** game.c<2> for game in /home/mar_b/rendu/Allum1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jul  9 01:53:48 2014 mar_b mar_b
** Last update Thu Jul 10 11:44:36 2014 mar_b mar_b
*/

#include <SDL/SDL.h>
#include "utils.h"
#include "graph.h"
#include "list.h"

/*
** brief: we will traver our list until pos and substract our nbr
** @lst: our list
** @pos: our line
** @nbr: number of lucifer
** BRIEF: if the new nbr = 0 then we will remove the link.
** we will change the binary operation too
** return: return 1 if line removed else 0
*/
static char	_reset_lst(t_list *lst, int pos, int nbr)
{
  t_list	*tmp;
  int		i;

  i = pos;
  tmp = lst;
  while (--pos >= 0)
    tmp = tmp->next;
  tmp->nbr_ele -= nbr;
  if (tmp->nbr_ele == 0)
    {
      remove_ele(lst, i);
      free(lst->bin);
      lst->bin = operation_xor(lst->next);
      return (1);
    }
  else
    {
      free(tmp->bin);
      tmp->bin = int_to_bin(tmp->nbr_ele);
    }
  free(lst->bin);
  lst->bin = operation_xor(lst->next);
  return (0);
}

/*
** brief: it will check keys and do an action, used during the player's turn
** @game: main struct
** @input: struct with keys value (0 / 1)
** @lst: our pyramid
*/
void		update_game(t_manage *game, t_input *input, t_list *lst)
{
  if (input->enter)
    {
      if (_reset_lst(lst, input->pos + 1, 1) == 1)
	game->player = 0;
      input->enabled = game->player == 0 ? 0 : 1;
      input->enter = 0;
    }
  else if (input->down && !input->enabled)
    {
      input->pos = (input->pos == lst->nbr_ele - 1) ? 0 : input->pos + 1;
      input->down = 0;
    }
  else if (input->up && !input->enabled)
    {
      input->pos = (input->pos == 0) ? lst->nbr_ele - 1 : input->pos - 1;
      input->up = 0;
    }
  else if (input->space && input->enabled)
    {
      input->enabled = 0;
      game->player = 0;
      input->space = 0;
    }
}

/*
** brief: will draw our pyramid
** @game: our main struct
** @map: struct with img
** @nbr_ele: nbr of element on the line
** @j: the line
*/
static void	_loop_draw(t_manage *game, t_map *map, int nbr_ele, int j)
{
  int		i;
  int		height;
  int		mid;

  height = 100;
  mid = S_WIDTH / 2 - (map->allum->w / 2) - (nbr_ele - 1) * map->allum->w;
  i = 0;
  while (i < nbr_ele)
    {
      draw_img(game, map->allum, mid + (i * map->allum->w * 2),
	       height + (j != 0 ? 5 : 0) + (j * map->allum->h));
      ++i;
    }
}

/*
** brief: it will draw during the game mode
** @game: main struct
** @input: struct with keys
** @map: struct with img
** @lst: pyramid list
*/
void		draw_game(t_manage *game, t_input *input, t_map *map,
			  t_list *lst)
{
  t_list	*tmp;
  int		j;

  tmp = lst->next;
  draw_img(game, map->bg_game, 0, 0);
  j = 0;
  while (tmp != NULL)
    {
      _loop_draw(game, map, tmp->nbr_ele, j);
      ++j;
      tmp = tmp->next;
    }
  if (game->player)
    draw_str(game, "Player's turn...", S_WIDTH / 2 - 64, 50);
  else
    draw_str(game, "IA's turn...", S_WIDTH / 2 - 48, 50);
  input->pos = (input->pos >= lst->nbr_ele) ? lst->nbr_ele - 1 : input->pos;
  draw_str(game, "XXX",
	   50, 100 + input->pos * map->allum->h + map->allum->h / 2);
  if (SDL_Flip(game->screen) == -1)
    my_puterror("error: problem to flip the img in game.c");
}
