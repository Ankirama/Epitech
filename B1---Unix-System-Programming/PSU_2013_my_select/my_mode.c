/*
** my_mode.c for my_mode in /home/mar_b/rendu/PSU_2013_my_select
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu May 15 16:48:04 2014 mar_b mar_b
** Last update Wed May 28 14:48:53 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_select.h"
#include "my_cursor.h"
#include "my_termcaps.h"
#include "my_check.h"
#include "my_fun.h"
#include "my_list.h"
#include "my_error.h"
#include "my_free.h"
#include "my_list2.h"

void	my_exit(t_termios *t, t_position *pos, t_list *lst)
{
  my_visible_cursor();
  my_clear_shell();
  my_free_all(t, pos, lst);
  if (close(pos->fd) == -1)
    my_puterror("error: problem to close the tty!\n", 33);
  exit(EXIT_SUCCESS);
}

void	my_space(t_list *lst, t_position *pos)
{
  lst->active = !my_ret_elt(lst, pos->y)->active == 0 ? lst->active - 1 :
    lst->active + 1;
  my_ret_elt(lst, pos->y)->active =
    !my_ret_elt(lst, pos->y)->active;
  my_mode_line(my_ret_elt(lst, pos->y)->data,
	       pos->y, my_ret_elt(lst, pos->y)->active, 0);
  pos->y = pos->y < lst->size ? pos->y + 1 : 0;
  my_mode_line(my_ret_elt(lst, pos->y)->data,
	       pos->y, my_ret_elt(lst, pos->y)->active, 1);
}

void		my_remove(t_termios *t, t_position *pos, t_list *lst)
{
  t_list	*after;
  int		j;
  char		*last;

  j = -1;
  if (lst->size == 0)
    my_exit(t, pos, lst);
  last = my_ret_elt(lst, pos->y)->next == lst ? lst->prec->data : NULL;
  my_clear_list(lst, pos->y);
  my_remove_elt(lst, pos->y);
  after = lst->next;
  while (++j < pos->y)
    after = after->next;
  while (after != lst)
    {
      my_mode_line(after->data, j, after->active, j == pos->y ? 1 : 0);
      after = after->next;
      j += 1;
    }
  if (last)
    {
      my_delete_char(j, my_strlen(last));
      my_mode_line(lst->prec->data, j - 1, lst->prec->active, 1);
    }
  pos->y = last ? pos->y - 1 : pos->y;
}

void		my_enter(t_termios *t, t_position *pos, t_list *lst)
{
  t_list	*tmp;

  tmp = lst->next;
  my_visible_cursor();
  my_clear_shell();
  while (tmp != lst)
    {
      if (tmp->active)
	{
	  (void)write(1, tmp->data, tmp->size);
	  if (lst->active > 1)
	    (void)write(1, " ", 1);
	  lst->active -= 1;
	}
      tmp = tmp->next;
    }
  my_free_all(t, pos, lst);
  exit(EXIT_SUCCESS);
}
