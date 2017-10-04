/*
** function_two_key.c for  in /home/teyssa_r/rendu/PSU_2013_42sh/src/bonus
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Sun Sep  7 16:07:06 2014 teyssa_r teyssa_r
** Last update Thu Oct  2 22:19:23 2014 chenev_d chenev_d
*/

#include <termios.h>
#include <term.h>
#include <stdlib.h>
#include <ncurses/curses.h>
#include <unistd.h>
#include <string.h>
#include "mini.h"
#include "utils.h"
#include "bonus.h"

static void	_realloc(t_hst **hst, char *cmd, t_string *str)
{
  char		*tmp;

  cmd[str->i] = 0;
  tmp = my_strdup(cmd);
  if (tmp[0])
    {
      if (((*hst)->prev->name && !my_strcmp((*hst)->prev->name, tmp, 0)) ||
	  (*hst)->prev->name == NULL)
	add_before(hst, tmp);
    }
  str->i = 0;
  free(tmp);
}

static void	on_start(t_hst **hst)
{
  while ((*hst)->root != 1)
    *hst = (*hst)->prev;
}

char	*my_key_enter(t_hst **hst, t_string *str, char *cmd)
{
  if ((*hst)->name != NULL && str->i != BUFF)
    {
      if (str->tmp != NULL)
	{
	  free(cmd);
	  cmd = my_strdup(str->tmp);
	  _realloc(hst, cmd, str);
	}
      else
	{
	  free(cmd);
	  cmd = my_strdup((*hst)->name);
	}
    }
  else
    _realloc(hst, cmd, str);
  (void)write(1, "\n", 1);
  on_start(hst);
  free_string(str);
  return (cmd);
}
