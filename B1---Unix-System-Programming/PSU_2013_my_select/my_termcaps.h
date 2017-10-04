/*
** my_termcaps.h for my_termcaps in /home/user/rendu/PSU_2013_my_select
**
** Made by 
** Login   
**
** Started on  Wed May 14 23:48:28 2014 
** Last update Sun May 18 22:53:52 2014 
*/

#ifndef MY_TERMCAPS_H_
# define MY_TERMCAPS_H_

#include "my_list.h"

void	my_clear_shell();
void	my_clear_list(t_list *lst, int position);
void	my_end_underline();
void	my_start_underline(int y);
void	my_start_reverse(int y);

#endif /* !MY_TERMCAPS_H_ */
