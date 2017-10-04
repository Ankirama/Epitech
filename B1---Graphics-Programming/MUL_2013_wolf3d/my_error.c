/*
** my_error.c for my_error in /home/user/rendu/MUL_2013_wolf3d
**
** Made by 
** Login   
**
** Started on  Sat Jun  7 03:00:25 2014 
** Last update Sun Jun 15 17:49:50 2014 
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
