/*
** my_free.c for my_free.c in /home/mar_b/rendu/PSU_2013_my_select
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu May 15 14:10:07 2014 mar_b mar_b
** Last update Fri May 16 16:08:29 2014 mar_b mar_b
*/

#include <termio.h>
#include <stdlib.h>
#include "my_list.h"
#include "my_select.h"
#include "my_error.h"

void	my_free_all(t_termios *t, t_position *pos, t_list *lst)
{
  free(pos);
  if (tcsetattr(0, TCSANOW, t) == -1)
    my_puterror("error: problem with tcsetattr!\n", 31);
  my_let_it_go(lst);
  free(t);
}
