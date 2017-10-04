/*
** graph.h for graph in /home/mar_b/rendu/Allum1/graph
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul  4 13:33:09 2014 mar_b mar_b
** Last update Thu Jul 10 11:47:50 2014 mar_b mar_b
*/

#ifndef GRAPH_H_
# define GRAPH_H_

# define S_WIDTH	800
# define S_HEIGHT	600

# define COLOR_R	0
# define COLOR_G	0
# define COLOR_B	0

# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include "list.h"

typedef struct	s_manage
{
  SDL_Surface	*screen;
  TTF_Font	*font;
  char		on_menu;
  char		position;
  char		player;
}		t_manage;

typedef struct	s_input
{
  char		down;
  char		up;
  char		space;
  char		enabled;
  char		enter;
  int		pos;
}		t_input;

typedef struct	s_map
{
  SDL_Surface	*bg_title;
  SDL_Surface	*bg_game;
  SDL_Surface	*allum;
}		t_map;

/*
** init.c
*/
void		init(char *title, t_manage *game);
void		cleanup(void);
void		load_ressource(t_map *map);
void		my_exit_graph(t_manage *game, t_map *map, t_list *lst);

/*
** input.c
*/
void		getInput(t_manage *game, t_map *map, t_input *input,
			 t_list *lst);

/*
** font.c
*/
void		close_font(TTF_Font *font);
TTF_Font	*load_font(const char *font, int size);
void		draw_str(t_manage *game, const char *str, int x, int y);

/*
** draw.c
*/
char		delay(unsigned int frameLimit);
void		draw_img(t_manage *game, SDL_Surface *img, int x, int y);
SDL_Surface	*load_img(const char *name);

/*
** start.c
*/
void		update_start(t_manage *game, t_input *input, t_map *map,
			     t_list *lst);
void		draw_start(t_manage *game, t_map *map);

/*
** graph.c
*/
void		main_graph(t_list *lst, unsigned int frameLimit);

/*
** game.c
*/
void		update_game(t_manage *game, t_input *input, t_list *lst);
void		draw_game(t_manage *game, t_input *input, t_map *map,
			  t_list *lst);

#endif /* !GRAPH_H_ */
