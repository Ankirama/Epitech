/*
** function_fast.c for  in /home/teyssa_r/rendu/PSU_2013_42sh/src/bonus
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Tue Sep  9 16:27:43 2014 teyssa_r teyssa_r
** Last update Thu Oct  2 22:19:40 2014 chenev_d chenev_d
*/

#include <termios.h>
#include <term.h>
#include <stdlib.h>
#include <ncurses/curses.h>
#include <unistd.h>
#include "mini.h"
#include "utils.h"
#include "bonus.h"

static void	_key_end(int *x, char *str, char const *nd)
{
  while (*x >= 2 && *x < my_strlen(str) + 2)
    {
      tputs(nd, 0, putschar);
      *x += 1;
    }
}

int	my_key_end(int *x, t_hst **hst, char *cmd, t_string *str)
{
  char	*nd;

  if ((nd = tgetstr("nd", NULL)) == 0)
    return (-1);
  if ((*hst)->name == NULL)
    _key_end(x, cmd, nd);
  else if (str->tmp != NULL)
    _key_end(x, str->tmp, nd);
  else
    _key_end(x, (*hst)->name, nd);
  return (0);
}

static void	_key_start(int *x, char *str, char const *le)
{
  while (*x > 2 && *x <= my_strlen(str) + 2)
    {
      tputs(le, 0, putschar);
      *x -= 1;
    }
}

int	my_key_start(int *x, t_hst **hst, char *cmd, t_string *str)
{
  char	*le;

  if ((le = tgetstr("le", NULL)) == 0)
    return (-1);
  if ((*hst)->name == NULL)
    _key_start(x, cmd, le);
  else if (str->tmp != NULL)
    _key_start(x, str->tmp, le);
  else
    _key_start(x, (*hst)->name, le);
  return (0);
}
