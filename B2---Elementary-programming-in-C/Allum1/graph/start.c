/*
** start.c for start in /home/mar_b/rendu/Allum1/graph
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jul  7 21:33:34 2014 mar_b mar_b
** Last update Wed Jul  9 23:02:55 2014 mar_b mar_b
*/

#include "graph.h"
#include "utils.h"

/*
** brief: used to check key etc during the start menu
** @game: our struct with position etc...
** @input: our struct with keys
** @map: our texutres
** @lst: our list
*/
void	update_start(t_manage *game, t_input *input, t_map *map,
		     t_list *lst)
{
  if (input->down)
    {
      game->position = !game->position;
      input->down = 0;
    }
  else if (input->up)
    {
      game->position = !game->position;
      input->up = 0;
    }
  else if (input->enter)
    {
      if (!game->position)
	game->on_menu = 0;
      else if (game->position)
	my_exit_graph(game, map, lst);
      input->enter = 0;
    }
}

/*
** brief: draw our start menu
** @game: our struct with SDL_Surface
** @map: our textures
*/
void	draw_start(t_manage *game, t_map *map)
{
  draw_img(game, map->bg_title, 0, 0);
  draw_str(game, "Le jeu des allumettes", 110, 20);
  if (game->position)
    {
      draw_str(game, "START", 110, 60);
      draw_str(game, "-> EXIT <-", 110, 100);
    }
  else
    {
      draw_str(game, "-> START <-", 110, 60);
      draw_str(game, "EXIT", 110, 100);
    }
  if (SDL_Flip(game->screen) == -1)
    my_puterror("error: Problem to Flip the screen in start.c\n");
}
