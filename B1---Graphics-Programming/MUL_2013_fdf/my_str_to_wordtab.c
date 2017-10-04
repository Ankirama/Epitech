/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/mar_b/rendu/Piscine-C-Jour_08/ex_04
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Mar 12 17:14:49 2014 Fabien Martinez
** Last update Wed May  7 19:18:36 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "my_convert.h"

static char    my_is_alphanumeric(int i, char *str)
{
  if (str[i] >= 'a' && str[i] <= 'f' || str[i] == 'x')
    return (1);
  if (str[i] >= 'A' && str[i] <= 'F')
    return (1);
  if (str[i] >= '0' && str[i] <= '9')
    return (1);
  return (0);
}

static int	my_size_to_tab(char *str)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      if (my_is_alphanumeric(i, str))
	{
	  while (str[i] != '\0' && my_is_alphanumeric(i, str))
	    i += 1;
	  count += 1;
	}
      i += 1;
    }
  return (count);
}

static int	my_answer(char **arr, char *str, int i, int count)
{
  int		j;

  j = 0;
  while (str[i] != '\0' && my_is_alphanumeric(i, str))
    {
      arr[count][j] = str[i];
      i += 1;
      j += 1;
    }
  arr[count][j] = '\0';
  if (arr[count][0] == '0' && arr[count][1] == 'x' && arr[count][2])
     my_conv_hexa(arr[count]);
  return (i);
}

char	**my_str_to_wordtab(char *str)
{
  char	**arr;
  int	i;
  int	j;
  int	count;

  count = 0;
  i = 0;
  if ((arr = malloc(my_size_to_tab(str) * sizeof(char *))) == NULL)
    my_puterror(0, 0);
  if (arr == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (my_is_alphanumeric(i, str))
	{
	  if ((arr[count] = malloc(sizeof(*str))) == NULL)
	    my_puterror(0,0);
	  i = my_answer(arr, str, i, count);
 	  count += 1;
	  i -= 1;
	}
      i += 1;
    }
  arr[count] = 0;
  return (arr);
}
