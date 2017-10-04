/*
** my_error.c for my_error in /home/user/rendu/PSU_2013_my_select
**
** Made by 
** Login   
**
** Started on  Tue May 13 12:04:26 2014 
** Last update Mon May 19 15:04:20 2014 
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_termcaps.h"
#include "my_cursor.h"

/*
** It will print our error and exit(1)
*/
void	my_puterror(char *str, int size)
{
  (void)write(2, str, size);
  exit(EXIT_FAILURE);
}
