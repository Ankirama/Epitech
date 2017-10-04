/*
** function_side.c for  in /home/teyssa_r/rendu/PSU_2013_42sh/src/bonus
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Sun Sep  7 16:30:12 2014 teyssa_r teyssa_r
** Last update Thu Oct  2 22:20:14 2014 chenev_d chenev_d
*/

#include <termios.h>
#include <term.h>
#include <stdlib.h>
#include <ncurses/curses.h>
#include <unistd.h>
#include "mini.h"
#include "utils.h"
#include "bonus.h"

static void	_key_right(int *x, char *str, char *nd)
{
  if (*x >= 2 && *x < my_strlen(str) + 2)
    {
      tputs(nd, 0, putschar);
      *x += 1;
    }
}

int	my_key_right(int *x, t_hst **hst, char *cmd, t_string *str)
{
  char	*nd;

  str = str;
  if ((nd = tgetstr("nd", NULL)) == 0)
    return (-1);
  if ((*hst)->name == NULL)
    _key_right(x, cmd, nd);
  else if (str->tmp != NULL)
    _key_right(x, str->tmp, nd);
  else
    _key_right(x, (*hst)->name, nd);
  return (0);
}

static void	_key_left(int *x, char *str, char *le)
{
  if (*x > 2 && *x <= my_strlen(str) + 2)
    {
      tputs(le, 0, putschar);
      *x -= 1;
    }
}

int	my_key_left(int *x, t_hst **hst, char *cmd, t_string *str)
{
  char	*le;

  str = str;
  if ((le = tgetstr("le", NULL)) == 0)
    return (-1);
  if ((*hst)->name == NULL)
    _key_left(x, cmd, le);
  else if (str->tmp != NULL)
    _key_left(x, str->tmp, le);
  else
    _key_left(x, (*hst)->name, le);
  return (0);
}
