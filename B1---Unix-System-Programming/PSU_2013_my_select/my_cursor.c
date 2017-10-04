/*
** my_cursor.c for my_cursor in /home/mar_b/rendu/PSU_2013_my_select
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed May 14 14:40:26 2014 mar_b mar_b
** Last update Wed May 28 14:48:19 2014 mar_b mar_b
*/

#include <ncurses.h>
#include <term.h>
#include "my_fun.h"
#include "my_error.h"

void	my_move_cursor(int j)
{
  char	*cur;
  char	*str;

  cur = tgetstr("cm", NULL);
  if ((str = tgoto(cur, 0, j)) == NULL)
    my_puterror("error: problem with tgoto!\n", 27);
  if (tputs(str, 1, my_putchar) == -1)
    my_puterror("error: problem with tputs!\n", 27);
}

void	my_hide_cursor()
{
  char	*cur;
  char	*str;

  cur = tgetstr("vi", NULL);
  if ((str = tgoto(cur, 0, 0)) == NULL)
    my_puterror("error: problem with tgoto!\n", 27);
  if (tputs(str, 1, my_putchar) == -1)
    my_puterror("error: problem with tputs!\n", 27);
}

void	my_visible_cursor()
{
  char	*cur;
  char	*str;

  cur = tgetstr("ve", NULL);
  if ((str = tgoto(cur, 0, 0)) == NULL)
    my_puterror("error: problem with tgoto!\n", 27);
  if (tputs(str, 1, my_putchar) == -1)
    my_puterror("error: problem with tputs!\n", 27);
}

void	my_delete_char(int j, int size)
{
  char	*my_del;
  char	*str;
  int	i;

  my_del = tgetstr("dc", NULL);
  i = 0;
  while (i < size)
    {
      if ((str = tgoto(my_del, i, j)) == NULL)
	my_puterror("error: problem with tgoto!\n", 27);
      if (tputs(str, 1, my_putchar) == -1)
	my_puterror("error: problem with tputs!\n", 27);
      i += 1;
    }
}
