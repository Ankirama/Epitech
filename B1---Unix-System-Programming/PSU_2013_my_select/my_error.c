/*
** my_error.c for my_error in /home/mar_b/rendu/PSU_2013_my_select
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue May 13 12:04:26 2014 mar_b mar_b
** Last update Mon May 19 15:04:20 2014 mar_b mar_b
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
