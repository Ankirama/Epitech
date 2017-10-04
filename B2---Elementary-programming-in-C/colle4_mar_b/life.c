/*
** life.c for let it go in /home/mar_b/rendu/colle4_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep 16 19:27:58 2014 mar_b mar_b
** Last update Tue Sep 16 22:56:16 2014 mar_b mar_b
*/

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

static char	_my_check_square(char **arr, const int x, const int y)
{
  int		i;
  int		j;
  char		nbr_cell;

  nbr_cell = 0;
  j = (y == 0) ? 0 : y - 1;
  while (arr[j] != NULL && j <= y + 1)
    {
      i = (x == 0) ? 0 : x - 1;
      while (arr[j][i] != '\0' && i <= x + 1)
	{
	  if (arr[j][i] == '*' && !(j == y && i == x))
	    ++nbr_cell;
	  ++i;
	}
      ++j;
    }
  if (nbr_cell == 3)
    return (1);
  return ((nbr_cell < 2 || nbr_cell >= 4) ? -1 : 0);
}

char	**my_put_cell(char **arr, const int xmax, const int ymax, int nbr_cell)
{
  int	max;
  int	x;
  int	y;

  max = xmax * ymax;
  while (--nbr_cell >= 0)
    {
      y = my_rand_nbr(max);
      x = y % xmax;
      y = y / ymax;
      while (arr[y + 1][x + 1] == '*' || x == xmax || y == ymax)
	{
	  y = my_rand_nbr(max);
	  x = y % xmax;
	  y = y / ymax;
	}
      arr[y + 1][x + 1] = '*';
    }
  return (arr);
}

void	my_game_of_life(char **arr, int iter, const int x_max,
			const int y_max)
{
  int	i;
  int	j;
  char	res;

  while (--iter >= 0 && check_my_tab(arr))
    {
      j = 0;
      while (++j < y_max)
	{
	  i = 0;
	  while (++i < x_max)
	    {
	      if ((res = _my_check_square(arr, i, j)) == 1)
		arr[j][i] = '*';
	      else if (res == -1)
		arr[j][i] = ' ';
	    }
	}
      if (system("clear") != 0)
	my_puterror(ERR_SYSTEM);
      my_aff_tab(arr);
      sleep(1);
    }
  let_it_go(arr);
}
