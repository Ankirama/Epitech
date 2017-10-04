/*
** my_aff_tab.c for my_aff_tab in /home/lefebv_1/rendu/colle4_mar_b
**
** Made by lefebv_1 lefebv_1
** Login   <lefebv_1@epitech.net>
**
** Started on  Tue Sep 16 19:57:24 2014 lefebv_1 lefebv_1
** Last update Tue Sep 16 21:33:54 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "utils.h"

void	my_aff_tab(char **tab)
{
  int	x;

  x = 0;
  while (tab[x] != NULL)
    {
      my_write(1, tab[x], my_strlen(tab[x]));
      my_write(1, "\n", 1);
      x = x + 1;
    }
}
