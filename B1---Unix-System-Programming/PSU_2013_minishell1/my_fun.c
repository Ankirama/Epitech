/*
** my_fun.c for my_fun in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jun 16 03:02:11 2014 mar_b mar_b
** Last update Sun Jun 22 14:30:49 2014 mar_b mar_b
*/

#include <unistd.h>
#include "my_error.h"
#include "minishell1.h"
#include "my_str.h"

/*
** brief: we will write with a color
** @str: string used to write a message
** @color: color used to change the color
*/
void	my_write(const char *str, const char *color)
{
  (void)write(0, color, my_strlen(color));
  (void)write(0, str, my_strlen(str));
  (void)write(0, "\033[0m", my_strlen("\033[0m"));
}

/*
** brief: this fonction will write the str in stdout
** @str: we will write this string
*/
void	my_w(const char *str)
{
  (void)write(0, str, my_strlen(str));
}
