/*
** my_fun.c for my_fun in /home/mar_b/rendu/CPE-2013-BSQ
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue May  6 15:24:15 2014 mar_b mar_b
** Last update Fri May  9 13:52:33 2014 mar_b mar_b
*/

#include <stdlib.h>
#include <unistd.h>

/*
** Will display (stderror) a specific error
*/
void	my_puterror(char *str, int size)
{
  (void)write(2, str, size);
  exit(EXIT_FAILURE);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}

/*
** convert string to int
*/
int	my_get_nbr(char *str)
{
  int	i;
  int	nbr;

  if (str[0] == '-')
    my_puterror("ERROR: negative number!\n", 24);
  nbr = 0;
  i = 0;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
      nbr = nbr * 10 + str[i++] - '0';
      if (nbr < 0)
	my_puterror("ERROR: number too big!\n", 23);
    }
  if (nbr == 0)
    my_puterror("ERROR: not enough line\n", 23);
  free(str);
  return (nbr);
}

char	my_search(char **arr, int imin, int jmin, int size)
{
  int	i;
  int	j;

  if (arr[jmin][imin] == 'o')
    return (1);
  j = 0;
  while (j < size && arr[jmin + j])
    {
      i = 0;
      while (i < size && arr[jmin + j][imin + i])
	{
	  if (arr[jmin + j][imin + i] == 'o')
	    return (1);
	  i += 1;
	}
      j += 1;
    }
  if (!arr[jmin + j])
    return (1);
  return (0);
}

void	my_display(char **arr)
{
  int	i;

  i = 0;
  while (arr[i])
    {
      (void)write(1, arr[i], my_strlen(arr[i]));
      (void)write(1, "\n", 1);
      i += 1;
    }
}
