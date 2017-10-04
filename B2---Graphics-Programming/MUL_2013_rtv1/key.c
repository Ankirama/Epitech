/*
** key.c for key in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul 11 18:05:36 2014 mar_b mar_b
** Last update Mon Jul 21 16:12:27 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "utils.h"
#include "rtv1.h"

/*
** brief: used to check each key to move or to exit
** @keycode: each key has a int value and we used it
** @pr: the struct used to define the move, each ptr like the img etc...
** return: we return just 0 like the prototype
*/
int	my_keyboard(int keycode, t_window *pr)
{
  if (keycode == ID_ESCAPE)
    let_it_go(pr);
  return (0);
}
