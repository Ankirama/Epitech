/*
** input.c for input in /home/mar_b/rendu/Allum1/graph
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul  4 14:15:17 2014 mar_b mar_b
** Last update Wed Jul  9 22:42:14 2014 mar_b mar_b
*/

#include <SDL/SDL.h>
#include <stdlib.h>
#include "graph.h"

/*
** brief: set key if pressed or released (pressed -> value = 1, released = 0)
** @input: key struct
** @event: used to catch key
** @value: pressed -> 1, released -> 0
** return: return 1 to exit or 0
*/
static char	_key_pressed(t_input *input, SDL_Event *event, char value)
{
  if (event->key.keysym.sym == SDLK_ESCAPE)
    return (1);
  else if (event->key.keysym.sym == SDLK_SPACE)
    input->space = value;
  else if (event->key.keysym.sym == SDLK_DOWN)
    input->down = value;
  else if (event->key.keysym.sym == SDLK_RETURN)
    input->enter = value;
  else if (event->key.keysym.sym == SDLK_UP)
    input->up = value;
  return (0);
}

/*
** brief: check if any event appears and set the good key into our input struct
** @game: main struct
** @map: img struct
** @input: key struct
** @lst: pyramid list
*/
void		getInput(t_manage *game, t_map *map, t_input *input,
			 t_list *lst)
{
  SDL_Event	event;

  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	my_exit_graph(game, map, lst);
      else if (event.type == SDL_KEYDOWN)
	{
	  if (_key_pressed(input, &event, 1) == 1)
	    my_exit_graph(game, map, lst);
	}
      else if (event.type == SDL_KEYUP)
	(void)_key_pressed(input, &event, 0);
    }
}
