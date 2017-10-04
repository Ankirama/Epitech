/*
** img.c for img in /home/mar_b/rendu/MUL_2013_rtv1/calc
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul 11 18:45:41 2014 mar_b mar_b
** Last update Wed Jul 16 22:06:30 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "rtv1.h"
#include "utils.h"
#include "img.h"
#include "calc.h"

/*
** brief: will initialize our char *data
** @ptr: the struct used to define img (void *img)
** return: it will return our new struct
*/
t_img	*my_initimg(void *ptr)
{
  t_img	*img;

  if ((img = malloc(sizeof(*img))) == NULL)
    my_puterror("error: problem to malloc!\n");
  img->data = mlx_get_data_addr(ptr, &(img->bpp), &(img->sizeline),
				&(img->endian));
  return (img);
}

/*
** brief: it will fill our img with the calc fun
** @img: our img struct with data, bpp, sizeline...
*/
void		my_fill_img(t_img *img, t_scene *scene, char percent)
{
  int		i;
  int		j;
  unsigned int	clr;
  unsigned char *color;

  j = -1;
  (void)write(1, "Please wait...\n", 15);
  while (++j < HEIGHT)
    {
      if (j * 100 / HEIGHT != percent && (j * 100 / HEIGHT) % 10 == 0)
	display_progession(j * 100 / HEIGHT);
      percent = j * 100 / HEIGHT;
      i = -1;
      while (++i < WIDTH)
	{
	  clr = my_calc(i, j, scene);
	  color = (unsigned char *)&clr;
	  (void)my_put_pixel_to_img(img, color, j * img->sizeline + i
				    * img->bpp / 8);
	}
    }
  my_write("\033[1;32mProgression... 100%\033[0m\ndone\n");
}
