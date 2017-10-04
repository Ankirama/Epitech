/*
** nbr.c<2> for nbr in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Aug 22 11:36:55 2014 mar_b mar_b
** Last update Tue Aug 26 01:03:59 2014
*/

#include "utils.h"

/*
** brief: check if the number is good
** @str: the current "nbr" like "-42"
*/
static void	_check_nbr(const char *str)
{
  int		i;

  i = (str[0] == '-') ? 0 : -1;
  if (str[0] == '-' && str[i] == '\0')
    {
      my_write(2, "error: '", my_strlen("error: '"));
      my_write(2, str, my_strlen(str));
      my_puterror("' is not valid number !\n");
    }
  while (str[++i])
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  my_write(2, "error: '", my_strlen("error: '"));
	  my_write(2, str, my_strlen(str));
	  my_puterror("' is not valid number !\n");
	}
    }
}

/*
** brief: Like ATOI
** @str: we will convert this string to an integer
** return: it will return the new integer
*/
int	my_getnbr_asm(const char *str, char *error)
{
  int	i;
  int	nbr;

  _check_nbr(str);
  i = (str[0] == '-') ? 0 : -1;
  nbr = 0;
  *error = 0;
  if (str[0] == '-')
    {
      while (str[++i])
	{
	  nbr = nbr * 10 - (str[i] - '0');
	  *error = nbr > 0 ? 1 : *error;
	}
    }
  else
    {
      while (str[++i])
	{
	  nbr = nbr * 10 + (str[i] - '0');
	  *error = nbr < 0 ? 1 : *error;
	}
    }
  return (nbr);
}
