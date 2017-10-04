/*
** sum_params.c for sum_params in /home/mar_b/rendu/Piscine-C-Jour_08/ex_03
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Mar 12 15:03:50 2014 Fabien Martinez
** Last update Thu Mar 13 19:26:52 2014 Fabien Martinez
*/

#include <stdlib.h>

int	my_tot_len(int argc, char **argv)
{
  int	i;
  int	len;

  len = 0;
  i = 0;
  while (i < argc)
    {
      len += my_strlen(argv[i]);
      i += 1;
    }
  return (len);
}

char	*sum_params(int argc, char **argv)
{
  int	length;
  int	i;
  int	j;
  char	*str;
  char	*tmp;

  i = 0;
  length = 0;
  str = malloc(argc * my_tot_len(argc, argv));
  while (i < argc)
    {
      j = 0;
      tmp = argv[i];
      while (tmp[j] != '\0')
	{
	  str[length] = tmp[j];
	  j += 1;
	  length += 1;
	}
      str[length] = '\n';
      length += 1;
      i += 1;
    }
  str[length - 1] = '\0';
  return (str);
}
