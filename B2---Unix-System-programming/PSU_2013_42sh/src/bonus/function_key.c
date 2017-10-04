/*
** function_key.c for  in /home/teyssa_r/rendu/PSU_2013_42sh/bonus
**
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
**
** Started on  Mon Sep  1 04:46:14 2014 teyssa_r teyssa_r
** Last update Thu Oct  2 22:20:03 2014 chenev_d chenev_d
*/

#include <termios.h>
#include <term.h>
#include <stdlib.h>
#include <ncurses/curses.h>
#include <unistd.h>
#include "mini.h"
#include "utils.h"
#include "bonus.h"

static char	*_free_tmp(char *tmp)
{
  free(tmp);
  tmp = NULL;
  return (tmp);
}
int	my_key_up(int *x, t_hst **hst, char __attribute__((__unused__)) *cmd,
		  t_string *str)
{
  char	*cb;
  char	*ce;

  if (str->tmp != NULL)
    str->tmp = _free_tmp(str->tmp);
  if ((*hst)->prev->name != NULL)
    {
      if ((cb = tgetstr("cb", NULL)) == 0)
	return (-1);
      if ((ce = tgetstr("ce", NULL)) == 0)
	return (-1);
      tputs(cb, 0, putschar);
      (void)write(1, "\r", 1);
      (void)write(1, CLR_SHELL, my_strlen(CLR_SHELL));
      *hst = (*hst)->prev;
      tputs(ce, 0, putschar);
      if ((*hst) != NULL && (*hst)->root == 1)
	(void)write(1, cmd, my_strlen(cmd));
      else if ((*hst) != NULL)
	(void)write(1, (*hst)->name, my_strlen((*hst)->name));
      str->i = my_strlen((*hst)->name);
      *x = my_strlen((*hst)->name) + 2;
    }
  return (0);
}

int	my_key_down(int *x, t_hst **hst, char __attribute__((__unused__)) *cmd,
		    t_string *str)
{
  char	*cb;
  char	*ce;

  if (str->tmp != NULL)
    str->tmp =_free_tmp(str->tmp);
  if ((*hst)->name != NULL)
    {
      if ((cb = tgetstr("cb", NULL)) == 0)
	return (-1);
      if ((ce = tgetstr("ce", NULL)) == 0)
	return (-1);
      tputs(cb, 0, putschar);
      (void)write(1, "\r", 1);
      (void)write(1, CLR_SHELL, my_strlen(CLR_SHELL));
      (*hst) = (*hst)->next;
      tputs(ce, 0, putschar);
      if ((*hst) != NULL && (*hst)->root == 1)
	(void)write(1, cmd, my_strlen(cmd));
      else
	(void)write(1, (*hst)->name, my_strlen((*hst)->name));
      str->i = my_strlen((*hst)->name);
      *x = my_strlen((*hst)->name) + 2;
    }
  return (0);
}
