/*
** my_key.c for my_key in /home/mar_b/rendu/MUL_2013_wolf3d
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat Jun  7 16:14:32 2014 mar_b mar_b
** Last update Sun Jun 15 17:56:52 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "wolf3d.h"
#include "my_error.h"
#include "my_calc.h"
#include "my_img.h"
#include "my_free.h"
#include "my_init.h"

/*
** brief: used to check each key to move or to exit
** @keycode: each key has a int value and we used it
** @pr: the struct used to define the move, each ptr like the img etc...
** return: we return just 0 like the prototype
*/
int		my_keyboard(int keycode, t_ptr *pr)
{
  t_vector	*pos;
  char		key;

  pos = my_init_pos();
  key = 1;
  if (keycode == ID_UP || keycode == 'w')
    my_move_xy(pr, 1, &pos);
  else if (keycode == ID_DOWN || keycode == 's')
    my_move_xy(pr, 0, &pos);
  else if (keycode == ID_LEFT || keycode == 'a')
    pr->move->id_ang = pr->move->id_ang == 24 ? 1 : pr->move->id_ang + 1;
  else if (keycode == ID_RIGHT || keycode == 'd')
    pr->move->id_ang = pr->move->id_ang == 0 ? 23 : pr->move->id_ang - 1;
  else
    key = 0;
  if (keycode == ID_ESCAPE)
    let_it_go(pr);
  if (key)
    my_wall(pr, pos);
  my_free_vec(pos);
  return (0);
}
