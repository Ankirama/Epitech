/*
** main.c for main in /home/mar_b/rendu/MUL_2013_wolf3d
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat Jun  7 00:51:35 2014 mar_b mar_b
** Last update Sun Jun 15 17:48:42 2014 mar_b mar_b
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_error.h"
#include "mlx.h"
#include "wolf3d.h"
#include "my_wall.h"
#include "my_img.h"
#include "my_key.h"
#include "my_init.h"

/*
** brief: we write the sky/ground and walls
** @pr: the struct used to define the move, each ptr like the img etc...
*/
static	void	_my_display_img(t_ptr *pr)
{
  my_sky_ground(pr);
  my_display_wall(pr);
}

/*
** brief: this function will create/initialize our struct
** @prt: the struct used to define the move, each ptr like the img etc...
*/
static void	_my_load_ptr(t_ptr *ptr)
{
  int	w;
  int	h;

  if ((ptr->mlx = mlx_init()) == NULL)
    my_puterror("error: problem with mlx_init!\n");
  if ((ptr->win = mlx_new_window(ptr->mlx, WIDTH, HEIGHT, "wolf3d")) == NULL)
    my_puterror("error: problem with mlx_new_window!\n");
  if ((ptr->img = mlx_new_image(ptr->mlx, WIDTH, HEIGHT)) == NULL)
    my_puterror("error: problem with mlx_new_image!\n");
  if ((ptr->mini = mlx_new_image(ptr->mlx, WIDTH_MINI, HEIGHT_MINI)) == NULL)
    my_puterror("error: problem with mlx_new_image!\n");
  if ((ptr->sky = mlx_xpm_file_to_image(ptr->mlx, "./img/sky.xpm", &w, &h))
      == NULL || w != 800 || h != 300)
    my_puterror("error: problem with mlx_xpm_file_to_image!\n");
}

/*
** brief: main function, used to initialize the window,
** the img and start the loop
*/
int	main(int argc, char **argv)
{
  t_ptr	*ptr;
  int	fd;

  if ((ptr = malloc(sizeof(*ptr))) == NULL)
    my_puterror("error: problem to malloc!\n");
  _my_load_ptr(ptr);
  if ((ptr->move = malloc(sizeof(*(ptr->move)))) == NULL)
    my_puterror("error: problem to malloc!\n");
  fd = -1;
  if (argc > 1)
    {
      if ((fd = open(argv[1], O_RDONLY)) == -1)
	my_puterror("error: unable to open the map!\n");
    }
  my_load_conf(ptr, fd);
  ptr->pic = my_initimg(ptr->img);
  ptr->mini_p = my_initimg(ptr->mini);
  ptr->sky_p = my_initimg(ptr->sky);
  _my_display_img(ptr);
  (void)mlx_expose_hook(ptr->win, my_expose, ptr);
  (void)mlx_hook(ptr->win, ID_KEYP, ID_KEYR, my_keyboard, ptr);
  (void)mlx_loop(ptr->mlx);
  return (0);
}
