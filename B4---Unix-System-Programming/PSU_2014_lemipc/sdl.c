/*
** sdl.c for  in /home/viterb_c/rendu/PSU_2014_lemipc
** 
** Made by CHARLES VITERBO
** Login   <viterb_c@epitech.net>
** 
** Started on  Fri Mar  6 13:04:55 2015 CHARLES VITERBO
** Last update Sun Mar  8 13:23:35 2015 CHARLES VITERBO
*/

#include "lemipc.h"

/*
** This function will send back the components RGB of a team
** if team >= MAX_TEAMS grey will be send back
*/
int		_color(int team, int comp)
{
  static int	color[MAX_TEAMS][3] =
    {{255, 0, 0},
     {0, 255, 0},
     {0, 0, 255},
     {255, 255, 0},
     {0, 255, 255},
     {255, 0, 255},
     {102, 51, 153},
     {153, 102, 0},
     {255, 255, 255},
     {0, 0, 0}};

  if (team >= MAX_TEAMS)
    return (127);
  return (color[team - 1][comp]);
}

/*
** This function will display a square 5 * 5 for every player in our sdl
** window
*/
static void	_print_pos(int x, int y, char team, SDL_Renderer *renderer)
{
  int		i;
  int		j;

  x = x * 3 + 2;
  y = y * 3 + 2;
  i = -3;
  if (team != 0)
    {
      SDL_SetRenderDrawColor(renderer, _color(team, 0), _color(team, 1),
			     _color(team, 2), 255);
      while (++i <= 2)
	{
	  if (0 <= x + i && x + i <= SCREEN)
	    {
	      j = -3;
	      while (++j <= 2)
		{
		  if (0 <= y + j && y + j <= SCREEN)
		    SDL_RenderDrawPoint(renderer, x + i, y + j);
		}
	    }
	}
    }
}

/*
** Our main function for sdl
** First we print grey in the window and after we print our players
*/
void		display_sdl(char *area, t_sdl *sdl)
{
  int		i;
  SDL_Event	e;

  i = -1;
  while (SDL_PollEvent(&e))
    {
      if (e.type == SDL_WINDOWEVENT_EXPOSED)
	SDL_RenderPresent(sdl->renderer);
    }
  SDL_SetRenderDrawColor(sdl->renderer, 127, 127, 127, 255);
  SDL_RenderClear(sdl->renderer);
  while (++i < AREA)
    _print_pos(i / SIZE_AREA, i % SIZE_AREA, area[i], sdl->renderer);
  SDL_RenderPresent(sdl->renderer);
}

/*
** This function will initialize our renderer
*/
t_sdl		*_init_renderer(SDL_Window *window, t_id *ids)
{
  SDL_Renderer	*renderer;
  t_sdl		*sdl;

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
				SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL)
    error_used(SDL_GetError(), ids->shm_id, ids->sem_id, -1);
  else
    {
      if ((sdl = malloc(sizeof(t_sdl *))) == NULL)
	error_used(ERR_MALLOC, ids->shm_id, ids->sem_id, -1);
      else
	{
	  sdl->window = window;
	  sdl->renderer = renderer;
	  return (sdl);
	}
    }
  return (NULL);
}

/*
** This function will initialize our SDL
*/
t_sdl		*init_sdl(t_id *ids)
{
  SDL_Window	*window;

  if (SDL_VideoInit(NULL) < 0)
    print_error(SDL_GetError());
  else
    {
      window = SDL_CreateWindow( "LemIPC", SDL_WINDOWPOS_CENTERED,
				 SDL_WINDOWPOS_CENTERED, SCREEN + 2,
				 SCREEN + 2, 0);
      if (window == NULL)
	error_used(SDL_GetError(), ids->shm_id, ids->sem_id, -1);
      else
	return (_init_renderer(window, ids));
    }
  return (NULL);
}
