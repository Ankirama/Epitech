/*
** error.c for error in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul 11 18:13:39 2014 mar_b mar_b
** Last update Sun Aug 24 01:31:22 2014
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

/*
** brief: if there is any error this function will print a message and exit
** @error: it will display this message
** @str: our file/line where there is a problem
*/
void	my_puterror_file(char *error, char *str)
{
  my_write(2, error, my_strlen(error));
  my_write(2, " ", 1);
  my_write(2, str, my_strlen(str));
  my_write(2, "\n", 1);
  exit(EXIT_FAILURE);
}

/*
** brief: it will display a specific message for our file and exit
** @file: our file like test[.s]
** @msg: our message
*/
void	my_error(const char *file, const char *msg)
{
  my_write(2, "File ", my_strlen("File "));
  my_write(2, file, my_strlen(file));
  my_write(2, msg, my_strlen(msg));
  exit(EXIT_FAILURE);
}
