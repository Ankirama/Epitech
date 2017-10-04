/*
** error.c for error in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul 11 18:13:39 2014 mar_b mar_b
** Last update Tue Jul 22 23:50:58 2014 mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

/*
** brief: if there is any error this function will print a message and exit
** @error: it will display this message
*/
void	my_puterror(char *error)
{
  my_write(2, error, my_strlen(error));
  exit(EXIT_FAILURE);
}
