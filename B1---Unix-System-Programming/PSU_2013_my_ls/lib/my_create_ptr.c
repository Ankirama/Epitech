/*
** my_create_ptr.c for my_printf in /home/mar_b/rendu/PSU_2014_my_printf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Apr 16 13:48:42 2014 Fabien Martinez
** Last update Sun Apr 20 22:48:13 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "my_printf.h"

/*
** This function'll create our array with our "basics" flags
*/
char	*my_create_tab_flags()
{
  char	*tab;

  if ((tab = malloc(sizeof(char) * 17)) == NULL)
    return (NULL);
  tab[0] = 'd';
  tab[1] = 'i';
  tab[2] = 'o';
  tab[3] = 'X';
  tab[4] = 'x';
  tab[5] = 'b';
  tab[6] = 'u';
  tab[7] = 'n';
  tab[8] = 's';
  tab[9] = 'c';
  tab[10] = 'S';
  tab[11] = 'p';
  tab[12] = '%';
  tab[13] = 'f';
  tab[14] = 'e';
  tab[15] = 'm';
  tab[16] = '\0';
  return (tab);
}

/*
** This function'll create our array with our option (like # etc...)
*/
char	*my_create_tab_options()
{
  char	*tab;

  if ((tab = malloc(sizeof(char) * 7)) == NULL)
    return (NULL);
  tab[0] = ' ';
  tab[1] = '#';
  tab[2] = '0';
  tab[3] = '+';
  tab[4] = '-';
  tab[5] = '.';
  tab[6] = '\0';
  return (tab);
}

/*
** This function will create our functions pointer
*/
my_flags	*create_ptr_fun()
{
  my_flags	*ptr_fun;

  if ((ptr_fun = malloc(sizeof(*ptr_fun) * 15)) == NULL)
    return (NULL);
  ptr_fun[0] = &my_putnbr_int;
  ptr_fun[1] = &my_putnbr_int;
  ptr_fun[2] = &my_putnbr_base_oct;
  ptr_fun[3] = &my_putnbr_base_hex_M;
  ptr_fun[4] = &my_putnbr_base_hex_m;
  ptr_fun[5] = &my_putnbr_base_bin;
  ptr_fun[6] = &my_putnbr_un;
  ptr_fun[7] = &my_count_print;
  ptr_fun[8] = &my_putstr;
  ptr_fun[9] = &my_putchar;
  ptr_fun[10] = &my_showstr;
  ptr_fun[11] = &my_putnbr_base_p;
  ptr_fun[12] = &my_putmod;
  ptr_fun[13] = &my_putnbr_double;
  ptr_fun[14] = &my_putnbr_sci;
  return (ptr_fun);
}

my_flags	*create_ptr_fun_long()
{
  my_flags	*ptr_fun;

  if ((ptr_fun = malloc(sizeof(*ptr_fun) * 7)) == NULL)
    return (NULL);
  ptr_fun[0] = &my_putnbr_long;
  ptr_fun[1] = &my_putnbr_long;
  ptr_fun[2] = &my_putnbr_base_oct_long;
  ptr_fun[3] = &my_putnbr_base_hex_M_long;
  ptr_fun[4] = &my_putnbr_base_hex_m_long;
  ptr_fun[5] = &my_putnbr_base_bin_long;
  ptr_fun[6] = &my_putnbr_un_long;
  return (ptr_fun);
}

/*
** Sort of my_getnbr
*/
int	my_create_nbr(const char *str, int *i)
{
  int	nbr;

  nbr = 0;
  while (str[*i] != 0 && str[*i] >= '0' && str[*i] <= '9')
    {
      nbr = nbr * 10 + str[*i] - '0';
      *i += 1;
    }
  *i -= 1;
  return (nbr);
}
