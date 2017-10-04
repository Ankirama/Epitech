/*
** error.c for error in /home/user/rendu/MUL_2013_rtv1
**
** Made by 
** Login   
**
** Started on  Fri Jul 11 18:13:39 2014 
** Last update Fri Jul 11 18:14:11 2014 
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
  (void)write(2, error, my_strlen(error));
  exit(EXIT_FAILURE);
}
