/*
** free.c for  in /home/teyssa_r/rendu/PSU_2013_42sh/src/bonus
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Sun Sep 28 18:50:23 2014 teyssa_r teyssa_r
** Last update Thu Oct  2 22:18:44 2014 chenev_d chenev_d
*/

#include <stdlib.h>
#include <unistd.h>
#include "bonus.h"

void	free_string(t_string *str)
{
  if (str != NULL)
    {
      free(str->tmp);
      free(str);
    }
}

void	free_hst(t_hst *hst)
{
  t_hst	*tmp;
  t_hst	*rmv;

  if (hst != NULL && hst->next != NULL)
    {
      tmp = hst->next;
      while (tmp != hst)
	{
	  rmv = tmp;
	  tmp = rmv->next;
	  free(rmv->name);
	  free(rmv);
	}
      free(hst);
    }
}

char	*free_error(t_hst *hst, t_string *str, char *cmd, int *len)
{
  free_hst(hst);
  if (str != NULL && *len >= 0)
    *len = str != NULL ? str->len : 0;
  free_string(str);
  free(cmd);
  return (NULL);
}

char	*free_null(t_string *str, char *cmd)
{
  free_string(str);
  free(cmd);
  return (NULL);
}
