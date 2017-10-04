/*
** white_rabbit.c for piscine in /home/mar_b/rendu/piscine_cpp_d01
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jan  7 09:13:58 2015 Fabien Martinez
** Last update Wed Jan  7 13:28:49 2015 Fabien Martinez
*/

#include <stdlib.h>
#include <stdio.h>

int	follow_the_white_rabbit(void)
{
  int	result;
  char	rabbit_found;
  char	dice;

  rabbit_found = 0;
  result = 0;
  while (!rabbit_found)
    {
      dice = (random() % 37) + 1;
      if ((dice >= 4 && dice <= 6) || dice == 28 || (dice >= 17 && dice <= 21))
	printf("gauche\n");
      else if (dice == 13 || (dice >= 34 && dice < 37))
	printf("droite\n");
      else if (dice == 15 || dice == 23 || dice == 10)
	printf("devant\n");
      else if (dice == 26 || dice % 8 == 0)
	printf("derriere\n");
      result += dice;
      if (dice == 1 || dice == 37 || result >= 397)
	{
	  printf("LAPIN !!!\n");
	  rabbit_found = 1;
	}
    }
  return (result);
}
