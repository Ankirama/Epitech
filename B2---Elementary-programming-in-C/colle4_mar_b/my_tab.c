/*
** my_tab.c for my_tab in /home/lefebv_1/rendu/colle4_mar_b
**
** Made by lefebv_1 lefebv_1
** Login   <lefebv_1@epitech.net>
**
** Started on  Tue Sep 16 20:06:37 2014 lefebv_1 lefebv_1
** Last update Tue Sep 16 22:51:40 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "utils.h"
#include "game_of_life.h"

static char	**_first_last_line(int y, char *patt, const int xmax,
				   char **tab)
{
  int		x;

  x = 0;
  tab[y][x] = patt[0];
  while (++x < xmax)
    tab[y][x] = patt[1];
  tab[y][x] = patt[0];
  tab[y][x + 1] = '\0';
  return (tab);
}

static char	**_create_tab(const int xmax, const int ymax, char **arr)
{
  int		y;

  y = -1;
  while (++y < ymax)
    {
      if (y == 0 || y == ymax - 1)
	arr = _first_last_line(y, "+-", xmax - 2, arr);
      else
	arr = _first_last_line(y, "| ", xmax - 2, arr);
    }
  arr[y] = NULL;
  return (arr);
}

char	**main_tab(const int xmax, const int ymax, int nbr_cell)
{
  char	**tab;
  int	i;

  if ((tab = malloc(sizeof(char *) * (ymax + 3))) == NULL)
    my_puterror(ERR_MALLOC);
  i = -1;
  while (++i < (ymax + 3))
    {
      if ((tab[i] = malloc(sizeof(char) * (xmax * 3))) == NULL)
	my_puterror(ERR_MALLOC);
    }
  tab = _create_tab(xmax + 3, ymax + 2, tab);
  tab = my_put_cell(tab, xmax, ymax, nbr_cell);
  my_aff_tab(tab);
  return (tab);
}

void	let_it_go(char **arr)
{
  int	i;

  i = -1;
  while (arr[++i] != NULL)
    free(arr[i]);
  free(arr);
}

char	check_my_tab(char **arr)
{
  int	i;
  int	j;

  j = -1;
  while (arr[++j] != NULL)
    {
      i = -1;
      while (arr[j][++i] != '\0')
	if (arr[j][i] == '*')
	  return (1);
    }
  return (0);
}
