/*
** my_display.c for my_display.c in /home/mar_b/rendu/MUL_2013_fdf
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon May  5 16:50:40 2014 mar_b mar_b
** Last update Thu May  8 10:09:06 2014 mar_b mar_b
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void	my_puterror(int i, int error)
{
  errno = error;
  if (i == 0)
    write(2, "ERROR: malloc problem!\n", 23);
  else if (i == 1)
    perror("");
  else
    write(2, "Usage: ./fdf my_file\n", 21);
  exit(EXIT_FAILURE);
}
