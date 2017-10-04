/*
** tp1_print_event.c for print in /home/mar_b/perso/c/minilibx
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Apr 15 10:38:03 2014 Fabien Martinez
** Last update Fri May  9 11:17:51 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "my_str_to_wordtab.h"
#include "mlx.h"
#include "fdf.h"
#include "my_pixel.h"
#include "my_convert.h"
#include "my_tab.h"
#include "get_next_line.h"

int	my_keyboard(int keycode, t_ptr *param)
{
  if (keycode == 65307)
    {
      free(param->mlx);
      free(param->win);
      free(param->img);
      free(param);
      exit(0);
    }
}

int		my_create_img(t_ptr *param)
{
  t_pixel	*pix;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
  unsigned int	color;

  data = mlx_get_data_addr(param->img, &bpp, &sizeline, &endian);
  color = mlx_get_color_value(param->mlx, 0x00FFA500);
  pix = fill_my_pixel(0, 0, bpp / 8, (unsigned char *)&color);
  while (param->tab)
    {
      pix->x = 0;
      while (param->tab->data[pix->x])
	{
	  my_put_pixel_to_img(pix, &data, sizeline,
			      my_get_nbr(param->tab->data[pix->x]));
	  pix->x += 1;
	}
      pix->y += 1;
      param->tab = param->tab->next;
    }
  free(pix);
  mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}

int		main(int argc, char **argv)
{
  t_ptr		*ptr;
  char		*s;
  int		fd;
  t_my_tab	*tab;

  tab = NULL;
  if ((ptr = malloc(sizeof(*ptr))) == NULL)
    my_puterror(0, 0);
  if (argc < 2)
    my_puterror(2, 0);
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    my_puterror(1, errno);
  while (s = get_next_line(fd))
    tab = my_append_elt(tab, my_str_to_wordtab(s));
  if (close(fd) == -1)
    my_puterror(1, errno);
  ptr->tab = tab;
  ptr->mlx = mlx_init();
  ptr->win = mlx_new_window(ptr->mlx, 1000, 1000, "FDF");
  ptr->img = mlx_new_image(ptr->mlx, 1000, 1000);
  mlx_expose_hook(ptr->win, my_create_img, ptr);
  mlx_key_hook(ptr->win, my_keyboard, ptr);
  mlx_loop(ptr->mlx);
  return (0);
}
