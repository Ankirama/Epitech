/*
** tab_fct.c for  in /home/teyssa_r/rendu/PSU_2013_42sh/src/bonus
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Sun Sep  7 16:43:48 2014 teyssa_r teyssa_r
** Last update Thu Oct  2 22:20:37 2014 chenev_d chenev_d
*/

#include "bonus.h"
#include <stdlib.h>

static char		g_tab_key[NB_FCT][NB_CHAR] = {{27, 91, 65},
						      {27, 91, 66},
						      {27, 91, 67},
						      {27, 91, 68},
						      {27, 91, 70},
						      {27, 91, 72},
						      {27, 91, 53},
						      {27, 91, 54},
						      {27, 91, 51},
						      {1, 0, 0},
						      {5, 0, 0},
						      {127, 0, 0}};
static my_tab_fct	g_tab_fct[NB_FCT] = {my_key_up, my_key_down,
					     my_key_right, my_key_left,
					     my_key_end, my_key_start,
					     my_key_up, my_key_down,
					     my_key_delete, my_key_start,
					     my_key_end, my_key_del};

int		seek_key(int *x, t_hst **hst, t_string *str, char *cmd)
{
  int		i;

  i = 0;
  while ((str->buff[0] != g_tab_key[i][0] || str->buff[1] != g_tab_key[i][1] ||
	  str->buff[2] != g_tab_key[i][2]) && i < NB_FCT)
    i++;
  if (str->buff[0] == g_tab_key[i][0] && str->buff[1] == g_tab_key[i][1]
      && str->buff[2] == g_tab_key[i][2] && i < NB_FCT)
    {
      if (g_tab_fct[i](x, hst, cmd, str) == -1)
	return (-1);
      return (1);
    }
  return (0);
}
