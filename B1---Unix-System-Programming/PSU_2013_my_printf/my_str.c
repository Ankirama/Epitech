/*
** my_str.c for my_str.c in /home/mar_b/rendu/PSU_2014_my_printf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Apr 14 20:10:12 2014 Fabien Martinez
** Last update Thu Apr 17 01:10:00 2014 Fabien Martinez
*/

#include <unistd.h>

/*
** print the char (used in others functions)
*/
char	my_putchar_c(char c)
{
  return (write(1, &c, 1));
}
