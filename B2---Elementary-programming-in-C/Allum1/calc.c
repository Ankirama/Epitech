/*
** calc.c for calc in /home/mar_b/rendu/Allum1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul  1 13:00:10 2014 mar_b mar_b
** Last update Thu Jul  3 15:36:21 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "utils.h"
#include "list.h"

/*
** brief: it will convert our number (<= 255) in binary
** @nbr: our number
** return: return our array with 0 and 1 like 00101010
*/
char	*int_to_bin(int nbr)
{
  char		*bin;
  int		i;

  if (nbr > 255)
    my_puterror("error: nbr too big!\n");
  if ((bin = malloc(sizeof(char) * ID_OCTET)) == NULL)
    my_puterror("error: problem to malloc in calc.c\n");
  i = -1;
  while (++i < ID_OCTET)
    bin[i] = 0;
  i = 8;
  while (nbr >= 2)
    {
      bin[--i] = nbr % 2;
      nbr = nbr / 2;
    }
  bin[--i] = nbr;
  return (bin);
}

/*
** brief: convert binary to decimal
** @bin: our binary array
** return: return our decimal
*/
int	bin_to_int(const char *bin)
{
  int	i;
  int	nbr;

  i = -1;
  nbr = 0;
  while (++i < ID_OCTET)
    {
      if (bin[i] == 1)
	nbr += my_pow(2, ID_OCTET - i - 1);
    }
  return (nbr);
}

/*
** brief: return nbr ^ pow
** @nbr: our number
** @pow: our power
** return: return our nbr ^ pow
*/
int	my_pow(const int nbr, int pow)
{
  if (pow == 0)
    return (1);
  else
    return (nbr * my_pow(nbr, pow -1));
}

/*
** brief: it will return the octet with the operation XOR
** @lst: our list, we will add each element
** return: return our char[8]
*/
char		*operation_xor(t_list *lst)
{
  t_list	*tmp;
  char		*bin;
  int		i;

  if ((bin = malloc(sizeof(char) * 8)) == NULL)
    my_puterror("error: problem to malloc in calc.c\n");
  i = -1;
  while (++i < ID_OCTET)
    bin[i] = 0;
  i = -1;
  tmp = lst;
  while (tmp != NULL)
    {
      i = -1;
      while (++i < ID_OCTET)
	bin[i] = (bin[i] != tmp->bin[i] &&
		  (bin[i] == 1 || tmp->bin[i] == 1)) ? 1 : 0;
      tmp = tmp->next;
    }
  return (bin);
}

/*
** brief: convert char * -> integer
** @str: our char*
** return: return our converted number
*/
int	my_get_nbr(const char *str)
{
  int	i;
  int	nbr;

  i = -1;
  nbr = 0;
  while (str[++i] != '\0' && str[i] >= '0' && str[i] <= '9' && nbr >= 0)
    nbr = nbr * 10 + str[i] - '0';
  return (nbr < 0 ? -1 : nbr);
}
