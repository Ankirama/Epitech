/*
** error_close.c for error_close in /home/chenev_d/rendu/PSU_2013_42sh/PSU_2013_42sh/PSU_2013_42sh/src/utils
** 
** Made by chenev_d chenev_d
** Login   <chenev_d@epitech.net>
** 
** Started on  Thu Oct  2 22:48:10 2014 chenev_d chenev_d
** Last update Thu Oct  2 22:50:58 2014 chenev_d chenev_d
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

char	my_error_close(const char *error, const char *var)
{
  (void)write(2, var, my_strlen(var));
  (void)write(2, ": ", 3);
  (void)write(2, error, my_strlen(error));
  (void)write(2, "\n", 1);
  return (1);
}
