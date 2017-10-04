/*
** main.c for main in /home/mar_b/rendu/piscine_cpp_d01/ex01
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jan  7 11:13:37 2015 Fabien Martinez
** Last update Wed Jan  7 22:03:25 2015 Fabien Martinez
*/

#include <stdlib.h>
#include <stdio.h>

void menger(int x, int y, int p, int n);

int	my_get_nbr(char *str)
{
  int	nbr;
  int	i;

  i = -1;
  nbr = 0;
  while (str[++i] != '\0' && str[i] >= '0' && str[i] <= '9' && nbr >= 0)
    nbr = nbr * 10 + str[i] - '0';
  if (str[i] != '\0')
    return (-1);
  return (nbr);
}

int	main(int argc, char **argv)
{
  int	square_size;
  int	level;
  int	i;
  int	occur;

  if (argc != 3)
    return (EXIT_FAILURE);
  if ((square_size = my_get_nbr(argv[1])) < 3 || square_size % 3 != 0)
    return (EXIT_FAILURE);
  if ((level = my_get_nbr(argv[2])) < 0 || level > square_size)
    return (EXIT_FAILURE);
  i = square_size;
  occur = 1;
  while (i > 3)
    {
      i /= 3;
      ++occur;
    }
  if (i != 3)
    return (EXIT_FAILURE);
  if (level > occur)
    return (EXIT_FAILURE);
  menger(square_size, square_size, square_size, level);
}
