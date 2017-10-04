/*
** save_file.c for save_file in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat Oct 11 11:54:18 2014 mar_b mar_b
** Last update Mon Oct  6 04:59:44 2014
*/

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "save_file.h"
#include "rtracer.h"

/*
** brief: convert ./scenes/scene1 by scene1
** @file: current name ./scenes/scene1
** return: return the good name
*/
static char	*_good_name(char *file)
{
  int		i;
  char		*name;

  i = my_strlen(file) - 1;
  while (i >= 0 && file[i] != '/')
    --i;
  if (file[i] == '/')
    ++i;
  name = my_strdup(&file[i]);
  return (name);
}

/*
** brief: it will write our pixels into our file (fuck it bmp format !)
** @data: our data with all pixels
** @sizeline: nbr pixels by line
** @file: our file
*/
static void	_write_data(char *data, int sizeline, FILE *file)
{
  int		i;
  int		j;
  int		h;
  unsigned char	*dest;
  unsigned char	color;

  j = -1;
  h = HEIGHT - 1;
  dest = my_malloc(sizeof(char) * (sizeline * HEIGHT));
  while (h >= 0)
    {
      i = -1;
      while (++i < sizeline)
	{
	  color = data[sizeline * h + i];
	  dest[++j] = color;
	}
      --h;
    }
  fwrite(dest, 1, sizeline * HEIGHT, file);
  free(dest);
}

/*
** brief: it will write our entire file
** @name: the name for our file (we'll change it)
** @img: our img with data like pixels, bpp, sizeline..
*/
void	save_file(char *name, t_img *img)
{
  FILE	*file;
  char	*dest;
  char	*tmp;

  tmp = _good_name(name);
  dest = my_malloc(my_strlen("./saved/") + my_strlen(tmp) +
		   my_strlen(".bmp") + 1);
  dest[0] = '\0';
  dest = my_strcat(dest, "./saved/");
  dest = my_strcat(dest, tmp);
  dest = my_strcat(dest, ".bmp");
  if ((file = fopen(dest, "wb")) == NULL)
    my_puterror(ERR_OPEN);
  create_header(file, WIDTH * HEIGHT * img->bpp / 8 + 54, img->bpp);
  _write_data(img->data, img->sizeline, file);
  if (fclose(file) == -1)
    my_puterror(ERR_CLOSE);
  my_write(1, "Scene ", my_strlen("Scene "));
  my_write(1, tmp, my_strlen(tmp));
  my_write(1, " saved.\n", my_strlen(" saved.\n"));
  free(dest);
  free(tmp);
}
