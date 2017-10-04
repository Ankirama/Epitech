/*
** my_getnbr.c for my_getnbr in /home/mar_b/rendu/Piscine-C-Jour_04
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Thu Mar  6 10:46:37 2014 Fabien Martinez
** Last update Fri Mar  7 16:44:50 2014 Fabien Martinez
*/

int	my_bool_int(unsigned int nbr, char bool)
{
  int	max;
  long	min;

  max = 2147483647;
  min = 2147483648;
  if ((nbr > max && bool != 1) || (nbr > min && bool == 1))
    {
      return (1);
    }
  return 0;
}

int	my_start(char *str, int *i)
{
  int	nbr_less;

  *i = 0;
  while (*i < my_strlen(str) && (*(str + *i) < '0' || *(str + *i) > '9'))
    {
      nbr_less = 0;
      while (*i < my_strlen(str) && (*(str + *i) == '-' || *(str + *i) == '+'))
	{
	  if (*(str + *i) == '-')
	    nbr_less += 1;
	  *i += 1;
	}
      *i += 1;
    }
  *i -= 1;
  return (nbr_less % 2);
}

int		my_getnbr(char *str)
{
  int		i;
  unsigned int	nbr;
  char		bool;
  
  bool = 0;
  nbr = 0;
  if (my_start(str, &i) != 0)
    bool = 1;
  while (i < my_strlen(str) && (*(str + i) >= '0' && *(str + i) <= '9'))
    {
      nbr = nbr * 10 + (*(str + i) - '0');
      if (my_bool_int(nbr, bool) == 1)
	  return (0);
      i+= 1;
    }
  if (bool == 1 && nbr <= 2147483648)
      nbr = nbr * (-1);
  else if(bool == 1 && nbr > 2147483648)
    return (0);;
  return (nbr);
}
