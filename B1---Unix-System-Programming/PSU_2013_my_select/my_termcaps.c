/*
** my_termcaps.c for my_termcaps in /home/mar_b/rendu/PSU_2013_my_select
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue May 13 10:39:39 2014 mar_b mar_b
** Last update Wed May 28 14:48:07 2014 mar_b mar_b
*/

#include <ncurses.h>
#include <term.h>
#include <stdlib.h>
#include "my_fun.h"
#include "my_cursor.h"
#include "my_list.h"
#include "my_error.h"

void	my_clear_shell()
{
  char	*my_clear;
  char	*str;

  my_clear = tgetstr("clear", NULL);
  if ((str = tgoto(my_clear, 0, 0)) == NULL)
    my_puterror("error: problem with tgoto!\n", 27);
  if (tputs(str, 1, my_putchar) == -1)
    my_puterror("error: problem with tputs!\n", 27);
}

void		my_clear_list(t_list *lst, int position)
{
  int		i;
  t_list	*tmp;

  tmp = lst;
  i = -1;
  while (++i < position)
    tmp = tmp->next;
  while (i <= lst->size)
    {
      my_move_cursor(i);
      my_delete_char(i, tmp->size);
      tmp = tmp->next;
      i += 1;
    }
}

void	my_end_underline()
{
  char	*my_es;
  char	*my_me;
  char	*str;

  my_es = tgetstr("ue", NULL);
  my_me = tgetstr("me", NULL);
  if ((str = tgoto(my_es, 0, 0)) == NULL)
    my_puterror("error: problem with tgoto!\n", 27);
  if (tputs(str, 1, my_putchar) == -1)
    my_puterror("error: problem with tputs!\n", 27);
  str = tgoto(my_me, 0, 0);
  if (tputs(str, 1, my_putchar) == -1)
    my_puterror("error: problem with tputs!\n", 27);
}

void	my_start_underline(int y)
{
  char	*my_us;
  char	*my_str;

  my_us = tgetstr("us", NULL);
  if ((my_str = tgoto(my_us, 0, y)) == NULL)
    my_puterror("error: problem with tgoto!\n", 27);
  if (tputs(my_str, 1, my_putchar) == -1)
    my_puterror("error: problem with tputs!\n", 27);
}

void	my_start_reverse(int y)
{
  char	*my_us;
  char	*my_str;

  my_us = tgetstr("mr", NULL);
  if ((my_str = tgoto(my_us, 0, y)) == NULL)
    my_puterror("error: problem with tgoto!\n", 27);
  if (tputs(my_str, 1, my_putchar) == -1)
    my_puterror("error: problem with tputs!\n", 27);
}
