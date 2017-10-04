/*
** history.c for  in /home/teyssa_r/rendu/PSU_2013_42sh/bonus
**
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
**
** Started on  Mon Sep  1 04:42:12 2014 teyssa_r teyssa_r
** Last update Thu Oct  2 22:20:28 2014 chenev_d chenev_d
*/

#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <stdlib.h>
#include <ncurses/curses.h>
#include "mini.h"
#include "bonus.h"
#include "utils.h"

int	putschar(int nb)
{
  if (write(1, &nb, 1) == -1)
    return (-1);
  return (0);
}

int	field_str(t_hst **hst, t_string *str, int *x, char *cmd)
{
  int	j;

  j = 0;
  if ((*x - 2) == my_strlen(cmd) && (*hst)->name == NULL)
    {
      while (j < str->len && str->i != BUFF)
	{
	  (void)write(1, &str->buff[j], 1);
	  cmd[str->i++] = str->buff[j++];
	  str->size--;
	  *x += 1;
	}
      str->tmp = NULL;
    }
  else if ((*x - 2 < my_strlen(cmd)) || ((*hst)->name != NULL))
    field_str_in(hst, str, x, cmd);
  return (0);
}

char	*cycle_history(t_string *str, t_hst **hst, char *cmd, int *len)
{
  int	x;
  int	my_er;

  x = 2;
  my_er = 0;
  while ((str->len = read(0, str->buff, BUFF)) > 0 && str->buff[0] != 4)
    {
      if ((my_er = seek_key(&x, hst, str, cmd)) == 1 || my_er == -1)
	if (my_er == -1)
	  return (free_null(str, cmd));
	else
	  my_init(str->buff, BUFF);
      else if ((str->buff[0] == '\n' && cmd[0] != 10) || str->i == BUFF)
	return (my_key_enter(hst, str, cmd));
      else if (cmd[0] == '\n' || str->buff[0] == '\n')
	(void)write(1, CLR_SHELL, my_strlen(CLR_SHELL));
      else if (str->buff[0] >= 32 && str->buff[0] <= 126)
	field_str(hst, str, &x, cmd);
      my_init(str->buff, BUFF + 1);
    }
  *len = str->buff[0] == 4 ? -2 : 0;
  if (str->len == -1)
    return (my_puterror_null(ERR_READ));
  else
    return (free_error((*hst), str, cmd, len));
}

char			*history(t_hst *hst, int *len)
{
  char			*cmd;
  t_string		*str;

  if ((str = malloc(sizeof(*str))) == NULL)
    return (my_puterror_null(ERR_MALLOC));
  if ((cmd = malloc(sizeof(char) * (BUFF + 1))) == NULL)
    return (my_puterror_null(ERR_MALLOC));
  str->size = BUFF;
  str->i = 0;
  str->len = 0;
  str->tmp = NULL;
  my_init(str->buff, BUFF + 1);
  my_init(cmd, BUFF);
  cmd = cycle_history(str, &hst, cmd, len);
  return (cmd);
}

char			*bonus(t_hst *hst, int *len)
{
  int			err_tget;
  char			*ve;
  char			*xterm;
  struct termios	terminal;

  if ((xterm = my_strdup("xterm")) == NULL)
    return (my_puterror_null(ERR_TERM));
  if ((err_tget = tgetent(0, xterm)) == 0)
    return (my_puterror_null(ERR_TGETENT_0));
  else if (err_tget == -1)
    return (my_puterror_null(ERR_TGETENT_1));
  if ((ve = tgetstr("ve", NULL)) == 0)
    return (my_puterror_null(ERR_TGETSTR));
  if (tcgetattr(0, &terminal) == -1)
    return (my_puterror_tc(ERR_TCGETATTR, ERR_TC));
  terminal.c_lflag &= ~(ICANON | ECHO);
  if (tcsetattr(0, 0, &terminal) == -1)
    return (my_puterror_tc(ERR_TCSETATTR, ERR_TC));
  tputs(ve, 0, putschar);
  return (history(hst, len));
}
