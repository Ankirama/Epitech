/*
** main.c for  in /home/teyssa_r/rendu/MUL_2013_rtracer
**
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
**
** Started on  Tue Sep  9 14:17:57 2014 teyssa_r teyssa_r
** Last update Sun Oct 12 21:12:41 2014 teyssa_r teyssa_r
*/

#include <unistd.h>
#include "objects.h"
#include "rtracer.h"
#include "utils.h"
#include "parser.h"
#include "mlx.h"
#include "noise.h"
#include "save_file.h"

/*
** brief : it will initialize our scene
** return: return our initialized scene
*/
static t_scene	*_init_scene()
{
  t_scene	*scene;

  scene = my_malloc(sizeof(*scene));
  scene->list_eye = NULL;
  scene->list_light = NULL;
  scene->list_orb = NULL;
  scene->list_plan = NULL;
  scene->list_cone = NULL;
  scene->list_cyl = NULL;
  scene->list_para = NULL;
  scene->ambiance = 0;
  return (scene);
}

static t_img	*_init_img(void *ptr)
{
  t_img		*img;

  img = my_malloc(sizeof(*img));
  img->data = mlx_get_data_addr(ptr, &img->bpp, &img->sizeline, &img->endian);
  return (img);
}

/*
** brief : it will create/load our img, and ptr for mlx
** @ptr : our struct with each t_img and other ptr
** @name: the name for the background
** @w, @h: width/height for name
*/
static void	_load_ptr(t_window *ptr, char *name, int w, int h)
{
  if ((ptr->mlx = mlx_init()) == NULL)
    my_puterror(ERR_MLX_INIT);
  if ((ptr->win = mlx_new_window(ptr->mlx, WIDTH, HEIGHT, NAME)) == NULL)
    my_puterror(ERR_MLX_WIN);
  if ((ptr->img = mlx_new_image(ptr->mlx, WIDTH, HEIGHT)) == NULL)
    my_puterror(ERR_MLX_IMG);
  if ((ptr->loading = mlx_new_image(ptr->mlx, WIDTH, HEIGHT)) == NULL)
    my_puterror(ERR_MLX_WIN);
  if (name != NULL)
    {
      if ((ptr->background =
	   mlx_xpm_file_to_image(ptr->mlx, name, &w, &h))
	  == NULL || w != WIDTH || h != HEIGHT)
	my_puterror("error: mlx_xpm_file_to_image!\n");
      ptr->bg = my_malloc(sizeof(*(ptr->bg)));
      ptr->bg->data = mlx_get_data_addr(ptr->background,
					&ptr->bg->bpp, &ptr->bg->sizeline,
					&ptr->bg->endian);
    }
  else
    ptr->background = NULL;
  ptr->pic = _init_img(ptr->img);
  ptr->load = _init_img(ptr->loading);
}

/*
** brief : it our main MAGUEULE !
** @ac : un mec trop feignant c'est ARGC !!!!!!
** @av : Aller on continue... FEIGNASSE ! (ARGV)
** return: return 0
*/
int		main(int ac, char **av)
{
  t_scene	*scene;
  t_window	*ptr;

  ptr = my_malloc(sizeof(*ptr));
  scene = _init_scene();
  if (ac < 2)
    {
      my_write(2, USAGE, my_strlen(USAGE));
      scene = get_scene("./scenes/mandatory/mandatory1", scene);
    }
  else
    scene = get_scene(av[1], scene);
  if (ac == 3)
    _load_ptr(ptr, av[2], 0, 0);
  else
    _load_ptr(ptr, NULL, 0, 0);
  create_perlin();
  create_scene(ptr, scene);
  save_file((ac >= 2) ? av[1] : "mandatory1", ptr->pic);
  free_scene(scene);
  (void)mlx_expose_hook(ptr->win, gere_expose, ptr);
  (void)mlx_key_hook(ptr->win, gere_keyboard, ptr);
  (void)mlx_loop(ptr->mlx);
  return (0);
}
