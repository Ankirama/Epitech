/*
** error.c for error in /home/user/rendu/colle3_bob42
**
** Made by 
** Login   
**
** Started on  Tue Sep  9 19:26:12 2014 
** Last update Tue Sep  9 19:33:40 2014 
*/

#include <stdlib.h>
#include "utils.h"

void	my_puterror(const char *str)
{
  my_write(2, str, my_strlen(str));
  exit(EXIT_FAILURE);
}
