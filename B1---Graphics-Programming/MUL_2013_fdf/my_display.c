/*
** my_display.c for my_display.c in /home/user/rendu/MUL_2013_fdf
**
** Made by 
** Login   
**
** Started on  Mon May  5 16:50:40 2014 
** Last update Thu May  8 10:09:06 2014 
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
