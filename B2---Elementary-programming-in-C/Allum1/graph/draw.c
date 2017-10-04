/*
** draw.c for draw in /home/mar_b/rendu/Allum1/graph
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul  4 14:24:11 2014 mar_b mar_b
** Last update Wed Jul  9 22:22:45 2014 mar_b mar_b
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "graph.h"
#include "utils.h"

/*
** brief: used to draw on the SDL_Surface screen our img
** @game: struct with our screen
** @img: our img we want to load
** @x: x position in our screen
** @y: y position in our screen
*/
void		draw_img(t_manage *game, SDL_Surface *img, int x, int y)
{
  SDL_Rect	dest;

  dest.x = x;
  dest.y = y;
  dest.w = img->w;
  dest.h = img->h;
  SDL_BlitSurface(img, NULL, game->screen, &dest);
}

/*
** brief: used to convert our img file in SDL_Surface
** @name: the path + name of our file
** return: return the SDL_Surface created
*/
SDL_Surface	*load_img(const char *name)
{
  SDL_Surface	*tmp;
  SDL_Surface	*img;

  if ((tmp = IMG_Load(name)) == NULL)
    {
      my_error("error: problem to load img in draw.c\n");
      return (NULL);
    }
  SDL_SetColorKey(tmp, (SDL_SRCCOLORKEY | SDL_RLEACCEL),
		  SDL_MapRGB(tmp->format, COLOR_R, COLOR_G, COLOR_B));
  if ((img = SDL_DisplayFormat(tmp)) == NULL)
    {
      my_error("error: problem with SDL_DisplayFormat in draw.c\n");
      return (NULL);
    }
  SDL_FreeSurface(tmp);
  return (img);
}

/*
** brief: used to manage(wait) our FPS, 16 : 1s = 1000 ms, 1000 / 60 ~= 16.6
** @frameLimit: our number
** return 0 if any "pb" or if frameLimit < ticks
** (SDL_GetTicks return the nbr since SDL started)
*/
char		delay(unsigned int frameLimit)
{
  unsigned int ticks;

  ticks = SDL_GetTicks();
  if (frameLimit < ticks)
    return (1);
  if (frameLimit > ticks + 16)
    SDL_Delay(16);
  else
    SDL_Delay(frameLimit - ticks);
  return (0);
}
