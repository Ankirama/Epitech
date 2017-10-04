/*
** my_getnbr.c for my_getnbr in /home/mar_b/rendu/Piscine-C-Jour_04
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Mar  6 10:46:37 2014 Fabien Martinez
** Last update Sun Mar 16 00:47:37 2014 Fabien Martinez
*/

int	my_start(char *str, int i)
{
  if (*(str) < '0' || *(str) > '9')
    return (1);
  if (str[0] == '-')
    return (1);
  return (0);
}

int		my_getnbr(char *str)
{
  int		i;
  unsigned int	nbr;
  char		bool;

  bool = 0;
  nbr = 0;
  if (my_start(str, 0) == 1)
    return (0);
  i = 0;
  while (i < my_strlen(str) && (*(str + i) >= '0' && *(str + i) <= '9'))
    {
      nbr = nbr * 10 + (*(str + i) - '0');
      if (nbr >= 2147483647)
	return (2147483647);
      i+= 1;
    }
  return (nbr);
}
