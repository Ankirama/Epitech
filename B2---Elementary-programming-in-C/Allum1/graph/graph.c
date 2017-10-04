/*
** graph.c for graph in /home/mar_b/rendu/Allum1/graph
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul  8 23:19:19 2014 mar_b mar_b
** Last update Wed Jul  9 23:04:46 2014 mar_b mar_b
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "graph.h"
#include "ia.h"
#include "list.h"
#include "utils.h"

/*
** brief: initialize our structs
** @game: main struct
** @input: struct with keys
*/
static void	_init(t_manage *game, t_input *input)
{
  game->on_menu = 1;
  game->player = 1;
  game->position = 0;
  input->down = 0;
  input->up  = 0;
  input->space = 0;
  input->enabled = 0;
  input->enter = 0;
  input->pos = 0;
}

/*
** brief: it will display the game and calls the right funct like ai, or player
** @game: main struct
** @input: struct with keys
** @map: struct with img
** @lst: our pyramid list
*/
static	void	_each_turn(t_manage *game, t_input *input, t_map *map,
			   t_list *lst)
{
  if (lst->nbr_ele == 1 && lst->next->nbr_ele == 1)
    {
      draw_img(game, map->bg_game, 0, 0);
      if (game->player == 0)
	draw_str(game, "IMPOSSIBLE ! the player won", S_WIDTH / 2 - 108, 50);
      else
	draw_str(game, "IA WON", S_WIDTH / 2 - 24, 50);
      if (SDL_Flip(game->screen) == -1)
	my_puterror("error: problem to flip img in graph.c\n");
    }
  else
    {
      if (game->player)
	update_game(game, input, lst);
      else
	{
	  game->player = 1;
	  ia_game(lst, 0, 0, 0);
	}
      draw_game(game, input, map, lst);
    }
}

/*
** brief: main function for graphic part
** @lst: our pyramid
** @frameLimit: just a variable for set FPS
** return: wait it's a void !!!
*/
void	main_graph(t_list *lst, unsigned int frameLimit)
{
  t_manage	game;
  t_map		map;
  t_input	input;

  _init(&game, &input);
  init("Allum1", &game);
  load_ressource(&map);
  if (atexit(cleanup) != 0)
    exit(EXIT_FAILURE);
  while (1)
    {
      getInput(&game, &map, &input, lst);
      if (lst->nbr_ele == 1 && lst->next->nbr_ele == 1 && input.enter)
	my_exit_graph(&game, &map, lst);
      if (game.on_menu)
	{
	  update_start(&game, &input, &map, lst);
	  draw_start(&game, &map);
	}
      else
	_each_turn(&game, &input, &map, lst);
      frameLimit = SDL_GetTicks() + 16;
      (void)delay(frameLimit);
    }
}
