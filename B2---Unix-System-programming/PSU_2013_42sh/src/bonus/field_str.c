/*
** field_str.c for  in /home/teyssa_r/rendu/PSU_2013_42sh/src/bonus
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Tue Sep 16 13:05:57 2014 teyssa_r teyssa_r
** Last update Thu Oct  2 16:49:41 2014 teyssa_r teyssa_r
*/

#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <term.h>
#include <ncurses/curses.h>
#include "utils.h"
#include "bonus.h"

static char	*_strdup_field(const char *str)
{
  int		i;
  char		*cpy;

  if ((cpy = malloc(sizeof(char) * BUFF + 1)) == NULL)
    return (my_puterror_null(ERR_MALLOC));
  i = -1;
  while (str[++i] != '\0')
    cpy[i] = str[i];
  cpy[i + 1] = 0;
  return (cpy);
}

static void	_add_char(char *str, char *buff, int *x)
{
  int		j;
  int		i;
  int		str_len;

  j = 0;
  str_len = my_strlen(str);
  i = (*x - 2);
  i = str_len - i;
  while (j <= i)
    {
      str[str_len + 1] = str[str_len];
      str_len--;
      j++;
    }
  str[*x - 2] = buff[0];
  write(1, "\r", 1);
  write(1, CLR_SHELL, my_strlen(CLR_SHELL));
  write(1, str, my_strlen(str));
}

static int	_left(int *x, char *str)
{
  int		i;
  char		*le;

  i = 0;
  if ((le = tgetstr("le", NULL)) == 0)
    return (-1);
  while (i < ((my_strlen(str) - (*x - 2)) - 1))
    {
      tputs(le, 0, putschar);
      i++;
    }
  *x += 1;
  return (0);
}

static void	_field_hst(t_string *str, t_hst **hst, int *x)
{
  if ((*hst)->name != NULL && str->tmp == NULL)
    {
      str->tmp = _strdup_field((*hst)->name);
      str->tmp[my_strlen((*hst)->name)] = 0;
      init_realloc(str->tmp, BUFF);
      str->i = my_strlen(str->tmp);
      _add_char(str->tmp, str->buff, x);
    }
  else if ((*hst)->name != NULL && str->tmp != NULL)
    {
      str->i = my_strlen(str->tmp);
      _add_char(str->tmp, str->buff, x);
    }
  _left(x, str->tmp);
}

int	field_str_in(t_hst **hst, t_string *str, int *x, char *cmd)
{
  if ((*hst)->name == NULL)
    {
      _add_char(cmd, str->buff, x);
      _left(x, cmd);
    }
  else if ((*hst)->name != NULL)
    _field_hst(str, hst, x);
  str->i++;
  return (0);
}
