/*
** rtracer.h for  in /home/viterb_c/rendu/MUL_2013_rtracer
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Fri Oct  3 17:15:56 2014 charles viterbo
** Last update Sun Oct 12 16:32:07 2014 mar_b mar_b
*/

#ifndef RTRACER_H_
# define RTRACER_H_

# define USAGE	"Usage : ./rt [scene].\n"
# define END	"\033[1;32mProgression... 100%\033[0m\ndone\n"
# define NAME	"Wow such rtracer many colors"

# define WIDTH	800
# define HEIGHT	640

# define ESC	65307

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
  void		*background;
  void		*win;
  void		*img;
  void		*loading;
  t_img		*pic;
  t_img		*bg;
  t_img		*load;
}		t_window;

/*
** EXPOSE_C_
*/
int	gere_expose(t_window *ptr);

/*
** KEYBOARD_C_
*/
int	gere_keyboard(int key_code, t_window *pr);

/*
** PICTURE_C_
*/
void	create_scene(t_window *ptr, t_scene *scene);

#endif /* !RTRACER_H_ */
