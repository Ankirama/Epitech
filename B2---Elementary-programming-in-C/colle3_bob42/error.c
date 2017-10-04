/*
** error.c for error in /home/mar_b/rendu/colle3_bob42
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep  9 19:26:12 2014 mar_b mar_b
** Last update Tue Sep  9 19:33:40 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "utils.h"

void	my_puterror(const char *str)
{
  my_write(2, str, my_strlen(str));
  exit(EXIT_FAILURE);
}
