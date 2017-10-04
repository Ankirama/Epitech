/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/mar_b/rendu/Piscine-C-Jour_08/ex_04
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Mar 12 17:14:49 2014 Fabien Martinez
** Last update Thu Mar 13 19:34:33 2014 Fabien Martinez
*/

#include <stdlib.h>

char    my_is_alphanumeric(int i, char *str)
{
  if (str[i] >= 'a' && str[i] <= 'z')
    return (1);
  if (str[i] >= 'A' && str[i] <= 'Z')
    return (1);
  if (str[i] >= '0' && str[i] <= '9')
    return (1);
  return (0);
}

int	my_size_to_tab(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      if (my_is_alphanumeric(i, str))
	{
	  while (str[i] != '\0' && my_is_alphanumeric(i, str))
	    {
	      i += 1;
	    }
	  count += 1;
	}
      i += 1;
    }
  return (count);
}

int	my_answer(char **arr, char *str, int i, int count)
{
  int	j;

  j = 0;
  while (str[i] != '\0' && my_is_alphanumeric(i, str))
    {
      arr[count][j] = str[i];
      i += 1;
      j += 1;
    }
  arr[count][j] = '\0';
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
  arr = malloc(my_size_to_tab(str) * sizeof(str));
  if (arr == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (my_is_alphanumeric(i, str))
	{
	  arr[count] = malloc(sizeof(*str));
	  i = my_answer(arr, str, i, count);
 	  count += 1;
	  i -= 1;
	}
      i += 1;
    }
  arr[count] = 0;
  return (arr);
}
