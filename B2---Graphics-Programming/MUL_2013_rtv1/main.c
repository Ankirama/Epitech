/*
** main.c for main in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul 11 16:59:24 2014 mar_b mar_b
** Last update Tue Jul 22 14:49:12 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "mlx.h"
#include "rtv1.h"
#include "utils.h"
#include "calc.h"
#include "img.h"
#include "objects.h"
#include "parser.h"

/*
** brief: will display our image if the expose is used
** @param: the struct used to define the move, each ptr like the img etc...
** return: will return 0, a classical value for mlx_epose_hook
*/
static int	_my_expose(t_window *param)
{
  mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
  return (0);
}

/*
** brief: this function will create/initialize our struct
** @prt: the struct used to define the move, each ptr like the img etc...
*/
static void	_my_load_ptr(t_window *ptr)
{
  if ((ptr->mlx = mlx_init()) == NULL)
    my_puterror("error: problem with mlx_init!\n");
  if ((ptr->win = mlx_new_window(ptr->mlx, WIDTH, HEIGHT, "rtv1")) == NULL)
    my_puterror("error: problem with mlx_new_window!\n");
  if ((ptr->img = mlx_new_image(ptr->mlx, WIDTH, HEIGHT)) == NULL)
    my_puterror("error: problem with mlx_new_image!\n");
  ptr->pic = my_initimg(ptr->img);
}

int		main(int argc, char **argv)
{
  t_window	*ptr;
  t_scene	*scene;

  if ((ptr = malloc(sizeof(*ptr))) == NULL ||
      (scene = malloc(sizeof(*scene))) == NULL)
    my_puterror("error: problem to malloc in main.c\n");
  scene->spheres = NULL;
  scene->planes = NULL;
  scene->cones = NULL;
  scene->spots = NULL;
  scene->cylinders = NULL;
  if (argc > 1)
    my_get_file(argv[1], scene);
  else
    my_get_file("./scenes/scene", scene);
  ptr->scene = scene;
  _my_load_ptr(ptr);
  my_fill_img(ptr->pic, scene, 0);
  (void)mlx_expose_hook(ptr->win, _my_expose, ptr);
  (void)mlx_key_hook(ptr->win, my_keyboard, ptr);
  (void)mlx_loop(ptr->mlx);
  return (0);
}
