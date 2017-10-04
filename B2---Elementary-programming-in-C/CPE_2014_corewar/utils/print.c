/*
** print.c for  in /home/teyssa_r/rendu/CPE_2014_corewar/utils
**
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
**
** Started on  Sat Aug 16 16:37:05 2014 teyssa_r teyssa_r
** Last update Sat Aug 16 22:08:50 2014 mar_b
*/

#include "utils.h"

void	my_putchar(const int fd, const char c)
{
  my_write(fd, &c, 1);
}
