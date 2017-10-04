/*
** my_display.h for my_display in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Apr 23 20:39:16 2014 Fabien Martinez
** Last update Wed Apr 30 14:07:11 2014 Fabien Martinez
*/

#include "my_file.h"

#ifndef MY_DISPLAY_H_
# define MY_DISPLAY_H_

# define CURR_P(str) (str[0] == '.' && str[1] == '/')

void	my_putfile(char file, t_my_file *files, char *opt, char end);
void	my_puterror();
char	my_puterrno(char *str, int my_errno);

#endif /* !MY_DISPLAY_H_ */
