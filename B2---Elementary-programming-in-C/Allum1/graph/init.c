/*
** init.c for init in /home/mar_b/rendu/Allum1/graph
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul  4 13:55:33 2014 mar_b mar_b
** Last update Wed Jul  9 23:05:28 2014 mar_b mar_b
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "graph.h"
#include "list.h"
#include "utils.h"

/*
** brief: initialize our SDL game, screen and font, set a title and dis. mouse
** @title: our window title
** @game: main struct
*/
void	init(char *title, t_manage *game)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    my_puterror("error: unable to initialize SDL in init.c\n");
  game->screen =
    SDL_SetVideoMode(S_WIDTH, S_HEIGHT, 0, SDL_HWPALETTE | SDL_DOUBLEBUF);
  if (game->screen == NULL)
    my_puterror("error: problem to set the video mode in init.c\n");
  SDL_WM_SetCaption(title, NULL);
  SDL_ShowCursor(SDL_DISABLE);
  if (TTF_Init() < 0)
    my_puterror("error: problem to initialize the font in init.c\n");
  game->font = load_font("./graph/fonts/font.ttf", 32);
}

/*
** brief: function to free for atexit (SDL fun)
*/
void	cleanup()
{
  TTF_Quit();
  SDL_Quit();
}

/*
** brief: load all ressources for map
** @map: our struct with img
*/
void	load_ressource(t_map *map)
{
  map->bg_title = load_img("./graph/img/title.png");
  map->bg_game = load_img("./graph/img/game.png");
  map->allum = load_img("./graph/img/allumette.png");
}

/*
** brief: exit function to free all like surface, lst etc...
** @game: main struct
** @map: img struct
** @lst: our list
*/
void	my_exit_graph(t_manage *game, t_map *map, t_list *lst)
{
  if (atexit(cleanup) == -1)
    my_error("error: unable to use atexit in init.c");
  if (map->bg_title != NULL)
    SDL_FreeSurface(map->bg_title);
  if (map->bg_game != NULL)
    SDL_FreeSurface(map->bg_game);
  if (map->allum != NULL)
    SDL_FreeSurface(map->allum);
  close_font(game->font);
  free_lst(lst);
  exit(EXIT_SUCCESS);
}
