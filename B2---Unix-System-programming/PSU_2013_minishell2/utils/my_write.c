/*
** my_write.c for my_write in /home/user/minishell/builtin
**
** Made by 
** Login   
**
** Started on  Wed Jun 25 00:28:21 2014 
** Last update Wed Jun 25 00:29:28 2014 
*/

#include <unistd.h>
#include "utils.h"

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
