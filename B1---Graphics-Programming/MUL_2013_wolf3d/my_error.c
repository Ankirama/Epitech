/*
** my_error.c for my_error in /home/mar_b/rendu/MUL_2013_wolf3d
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat Jun  7 03:00:25 2014 mar_b mar_b
** Last update Sun Jun 15 17:49:50 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_fun.h"

/*
** brief: if there is any error this function will print a message and exit
** @error: it will display this message
*/
void	my_puterror(char *error)
{
  (void)write(2, error, my_strlen(error));
  exit(EXIT_FAILURE);
}
