/*
** my_nbr.c for my_nbr in /home/mar_b/minishell/utils
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jun 26 15:33:50 2014 mar_b mar_b
** Last update Thu Jun 26 15:49:16 2014 mar_b mar_b
*/

#include <stdlib.h>

/*
** brief: this fun will convert our char * into integer
** @str: our char *
** return: return 0 if any pb (like neg number etc...) or our number
*/
int	my_get_nbr(char *str)
{
  int	nbr;
  int	i;

  if (str == NULL)
    return (0);
  i = -1;
  nbr = 0;
  while (str[++i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
      nbr = nbr * 10 + str[i] - '0';
      if (nbr < 0)
	return (0);
    }
  return (nbr);
}
