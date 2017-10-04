
/*
** utils.c for  in /home/viterb_c/rendu/209sondage/C
** 
** Made by CHARLES VITERBO
** Login   <viterb_c@epitech.net>
** 
** Started on  Thu Jun  4 20:04:19 2015 CHARLES VITERBO
** Last update Sat Jun  6 07:31:01 2015 CHARLES VITERBO
*/

#include "209sondage.h"

int	nbr(char *str)
{
  int	nbr;
  int	i;

  i = -1;
  nbr = 0;
  while (str[++i] != '\0')
    {
      if ('0' <= str[i] && str[i] <= '9')
	nbr = nbr * 10 + (str[i] - '0');
      else
	return (-1);
    }
  return (nbr);
}

float	nbr_float(char *str)
{
  float	nbr;
  float	div;
  int	i;

  i = -1;
  div = 1.0;
  nbr = 0;
  while (str[++i] != '\0')
    {
      if (('0' <= str[i] && str[i] <= '9') && div == 1.0)
	nbr = nbr * 10.0 + (str[i] - '0');
      else if (str[i] == '.')
	div = div * 0.1;
      else if (('0' <= str[i] && str[i] <= '9') && div != 1.0)
	{
	  nbr = nbr + (str[i] - '0') * div;
	  div = div * 0.1;
	}
      else
	return (-1.0);
    }
  return (nbr);
}

int	my_error(char *str)
{
  (void)write(2, str, strlen(str));
  return (1);
}
