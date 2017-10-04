/*
** my_create_ptr2.c for my_create_2 in /home/mar_b/rendu/PSU_2013_my_printf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sun Apr 20 22:33:44 2014 Fabien Martinez
** Last update Sun Apr 20 22:53:50 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "my_printf.h"

my_flags	*create_ptr_fun_short()
{
  my_flags	*ptr_fun;

  if ((ptr_fun = malloc(sizeof(*ptr_fun) * 7)) == NULL)
    return (NULL);
  ptr_fun[0] = &my_putnbr_short;
  ptr_fun[1] = &my_putnbr_short;
  ptr_fun[2] = &my_putnbr_base_oct_short;
  ptr_fun[3] = &my_putnbr_base_hex_M_short;
  ptr_fun[4] = &my_putnbr_base_hex_m_short;
  ptr_fun[5] = &my_putnbr_base_bin_short;
  ptr_fun[6] = &my_putnbr_un_short;
  return (ptr_fun);
}
