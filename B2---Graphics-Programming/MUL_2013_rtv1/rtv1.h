/*
** rtv1.h for rtv1 in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul 11 17:54:02 2014 mar_b mar_b
** Last update Mon Jul 28 11:09:29 2014 mar_b mar_b
*/

#ifndef RTV1_H_
# define RTV1_H_

# define WIDTH		800
# define HEIGHT		640
# define ID_RANGE	100

# define ID_ESCAPE	65307

# include "objects.h"

typedef struct	s_img
{
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
}		t_img;

typedef struct	s_window
{
  void		*mlx;
  void		*win;
  void		*img;
  t_img		*pic;
  t_scene	*scene;
}		t_window;

/*
** key.c
*/
int	my_keyboard(int keycode, t_window *pr);

#endif /* !RTV1_H_ */
