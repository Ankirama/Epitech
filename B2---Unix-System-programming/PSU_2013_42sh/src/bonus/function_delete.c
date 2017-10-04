/*
** function_delete.c for  in /home/teyssa_r/rendu/PSU_2013_42sh/src/bonus
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Tue Sep  9 13:57:17 2014 teyssa_r teyssa_r
** Last update Fri Oct  3 00:22:22 2014 teyssa_r teyssa_r
*/

#include <unistd.h>
#include <term.h>
#include <ncurses/curses.h>
#include <stdlib.h>
#include "utils.h"
#include "bonus.h"

static void	_key_delete(int *x, char *str, char const *ce, int i)
{
  if (*x >= 2)
    {
      tputs(ce, 0, putschar);
      if (my_strlen(str) > 1)
	{
	  while (str[i])
	    {
	      str[i] = str[i + 1];
	      (void)write(1, &str[i], 1);
	      i++;
	    }
	  str[i] = 0;
	}
      else if (my_strlen(str) == 1)
	{
	  str[0] = 0;
	  tputs(ce, 0, putschar);
	}
      while (i > (*x - 1))
	{
	  tputs(tgetstr("le", NULL), 0, putschar);
	  i--;
	}
    }
}

int	my_key_delete(int *x, t_hst **hst, char *cmd, t_string *str)
{
  char	*ce;

  if ((ce = tgetstr("ce", NULL)) == 0)
    return (-1);
  if ((*hst)->name == NULL)
    _key_delete(x, cmd, ce, *x - 2);
  else if (str->tmp != NULL)
      {
	_key_delete(x, str->tmp, ce, *x - 2);
	if (str->tmp[0] == 0)
	  str->tmp[0] = 0;
      }
  else if (str->tmp == NULL)
      {
	str->tmp = my_strdup((*hst)->name);
	_key_delete(x, str->tmp, ce, *x - 2);
      }
  if (str->i > 0)
    str->i--;
  return (0);
}

static void	_key_del(int *x, char *str, char const *le)
{
  int		i;

  i = 0;
  if (*x > 2)
    {
      tputs(le, 0, putschar);
      (void)write(1, " ", 1);
      tputs(le, 0, putschar);
      *x -= 1;
      i = *x - 2;
      while (str[i])
        {
          str[i] = str[i + 1];
          (void)write(1, &str[i], 1);
          i++;
        }
      str[i] = 0;
      (void)write(1, " ", 1);
      while (i >= (*x - 1))
        {
          tputs(le, 0, putschar);
          i--;
        }
    }
}

int	my_key_del(int *x, t_hst **hst, char *cmd, t_string *str)
{
  char	*le;

  if ((le = tgetstr("le", NULL)) == 0)
    return (-1);
  if ((*hst)->name == NULL)
    _key_del(x, cmd, le);
  else if (str->tmp != NULL)
    {
      _key_del(x, str->tmp, le);
      if (str->tmp[0] == 0)
	str->tmp[0] = 0;
    }
  else if (str->tmp == NULL)
    {
      if ((*x - 2) > 0)
	{
	  str->tmp = my_strdup((*hst)->name);
	  _key_del(x, str->tmp, le);
	}
    }
  if (str->i > 0)
    str->i--;
  return (0);
}
