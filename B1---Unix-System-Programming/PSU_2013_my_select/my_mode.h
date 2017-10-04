/*
** my_mode.h for my_mode in /home/mar_b/rendu/PSU_2013_my_select
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu May 15 17:18:14 2014 mar_b mar_b
** Last update Mon May 19 11:21:34 2014 mar_b mar_b
*/

#ifndef MY_MODE_H_
# define MY_MODE_H_

void	my_exit(t_termios *t, t_position *pos, t_list *lst);
void	my_space(t_list *lst, t_position *pos);
void	my_remove(t_termios *t, t_position *pos, t_list *lst);
void	my_enter(t_termios *t, t_position *pos, t_list *lst);

#endif /* !MY_MODE_H_ */
