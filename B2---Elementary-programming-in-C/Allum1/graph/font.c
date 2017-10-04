/*
** font.c for font in /home/mar_b/rendu/Allum1/graph
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul  8 18:48:05 2014 mar_b mar_b
** Last update Wed Jul  9 22:25:04 2014 mar_b mar_b
*/

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "graph.h"
#include "utils.h"

/*
** brief: it will load / convert our .ttf into TTF_Font
** @fontpath: the path
** @size: the size for our font
** return: return our new TTF_Font
*/
TTF_Font	*load_font(const char *fontpath, int size)
{
  TTF_Font	*font;

  if ((font = TTF_OpenFont(fontpath, size)) == NULL)
    my_puterror("error: problem to open the font in font.c\n");
  return (font);
}

/*
** brief: it will close proprely our font
** @font: our font
*/
void	close_font(TTF_Font *font)
{
  if (font != NULL)
    TTF_CloseFont(font);
}

/*
** brief: it will draw our string into the screen
** @game: our struct with screen
** @str: our string
** @x: x position in the screen
** @y: y position in the screen
*/
void		draw_str(t_manage *game, const char *str, int x, int y)
{
  SDL_Rect	dest;
  SDL_Surface	*surface;
  SDL_Color	fg;
  char		*tmp;

  fg.r = 0;
  fg.g = 0;
  fg.b = 0;
  tmp = my_strdup(str);
  if ((surface = TTF_RenderUTF8_Blended(game->font, str, fg)) == NULL)
    my_puterror("problem to create the SDL_Surface in font.c\n");
  dest.x = x;
  dest.y = y;
  dest.w = surface->w;
  dest.h = surface->h;
  SDL_BlitSurface(surface, NULL, game->screen, &dest);
  SDL_FreeSurface(surface);
  free(tmp);
}
