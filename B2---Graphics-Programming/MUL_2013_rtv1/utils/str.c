/*
** str.c for str in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul 11 18:15:56 2014 mar_b mar_b
** Last update Wed Jul 16 22:14:29 2014 mar_b mar_b
*/

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

/*
** brief: will calculate the numbers of char
** @str: this is the string
** return: will return the number of char
*/
int	my_strlen(const char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (0);
  while (str[++i]);
  return (i);
}

/*
** brief: it will copy each char into the new string
** @str: the string we will copy
** return: return the new string
*/
char	*my_strdup(const char *str)
{
  int	i;
  char	*cpy;

  if ((cpy = malloc(sizeof(char) * my_strlen(str))) == NULL)
    my_puterror("error: problem to malloc!\n");
  i = -1;
  while (str[++i])
    cpy[i] = str[i];
  cpy[i] = '\0';
  return (cpy);
}

/*
** brief: Like ATOI
** @str: we will convert this string to an integer
** return: it will return the new integer
*/
int	my_getnbr(const char *str)
{
  int	i;
  int	nbr;

  i = -1;
  while (str[++i])
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  (void)write(2, "error: '", 8);
	  (void)write(2, &str[i], 1);
	  my_puterror("' is not valid, this world is so bad !\n");
	}
    }
  i = -1;
  nbr = 0;
  while (str[++i] && nbr >= 0)
    nbr = nbr * 10 + (str[i] - '0');
  return (nbr);
}

void	my_write(char *str)
{
  (void)write(1, str, my_strlen(str));
}

void	display_progession(char i)
{
  if (i <= 30)
    {
      my_write("\033[1;31mprogression... ");
      put_nbr(i);
      my_write("%\033[0m\n");
    }
  else if (i <= 70)
    {
      my_write("\033[1;33mprogression... ");
      put_nbr(i);
      my_write("%\033[0m\n");
    }
  else
    {
      my_write("\033[1;32mprogression... ");
      put_nbr(i);
      my_write("%\033[0m\n");
    }
}
