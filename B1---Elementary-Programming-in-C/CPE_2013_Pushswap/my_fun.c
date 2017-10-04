/*
** my_fun.c for my_fun in /home/mar_b/rendu/CPE_2013_Pushswap
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat May 17 20:02:01 2014 mar_b mar_b
** Last update Sun Jun  8 20:03:21 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>

/*
** it will return the lenght of the str
*/
int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i]);
  return (i);
}

/*
** It will print our error and exit(1)
*/
void	my_puterror(char *str, int size)
{
  (void)write(2, str, size);
  exit(EXIT_FAILURE);
}

void	my_putchar(char c)
{
  (void)write(1, &c, 1);
}

/*
** Like ATOI
*/
int	my_getnbr(char *str)
{
  int	i;
  long	nbr;

  i = str[0] == '-' ? 0 : -1;
  while (str[++i])
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  (void)write(2, "error: '", 8);
	  (void)write(2, &str[i], 1);
	  my_puterror("' is not valid, this world is so bad !\n", 39);
	}
    }
  i = str[0] == '-' ? 0 : -1;
  nbr = 0;
  while (str[++i])
    nbr = nbr * 10 + (str[i] - '0');
  return (str[0] == '-' ? nbr * -1 : nbr);
}

void	my_putstr(int nbr)
{
  if (nbr >= 0 && nbr < 10)
    my_putchar(nbr + '0');
  else if (nbr < 0 && nbr > -10)
    {
      my_putchar('-');
      my_putchar((nbr * -1) + '0');
    }
  else
    {
      my_putstr(nbr / 10);
      my_putchar((nbr >= 0 ? nbr % 10 : (nbr % 10) * -1) + '0');
    }
}
