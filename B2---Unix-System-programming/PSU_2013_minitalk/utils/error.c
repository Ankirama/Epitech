/*
** error.c for error in /home/user/rendu/MUL_2013_rtv1
**
** Made by 
** Login   
**
** Started on  Fri Jul 11 18:13:39 2014 
** Last update Tue Jul 22 23:50:58 2014 
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
