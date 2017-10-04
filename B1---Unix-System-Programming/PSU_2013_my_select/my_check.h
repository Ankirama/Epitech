/*
** my_check.h for my_check in /home/user/rendu/PSU_2013_my_select
**
** Made by 
** Login   
**
** Started on  Wed May 14 00:08:52 2014 
** Last update Sun May 18 23:00:52 2014 
*/

#ifndef MY_CHECK_H_
# define MY_CHECK_H_

void	my_check_database(char **env);
void	my_mode_line(char *str, int j, int size, char type);
void	my_check_key_list(char *str, t_position **pos, t_list *lst,
			  t_termios *t);

#endif /* !MY_CHECK_H_ */
