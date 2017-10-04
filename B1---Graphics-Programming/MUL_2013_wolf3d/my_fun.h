/*
** my_fun.h for my_fun in /home/user/rendu/MUL_2013_wolf3d
**
** Made by 
** Login   
**
** Started on  Fri Jun 13 16:01:38 2014 
** Last update Fri Jun 13 19:35:20 2014 
*/

#ifndef MY_FUN_H_
# define MY_FUN_H_

# include "wolf3d.h"

int	my_strlen(const char *str);
char	*my_strdup(const char *str);
int	my_getnbr(char *str);
void	my_find_pos(t_ptr *pr, char map);

#endif /* !MY_FUN_H_ */
