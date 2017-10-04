/*
** my_list2.h for my_list2.h in /home/user/rendu/PSU_2013_minishell1
**
** Made by 
** Login   
**
** Started on  Thu Jun 19 11:39:38 2014 
** Last update Thu Jun 19 13:34:43 2014 
*/

#ifndef MY_LIST2_H_
# define MY_LIST2_H_

# include "my_list.h"

char	*my_find_element(t_list *lst, char *value);
void	my_setenv_lst(t_list *lst, char *var, char *value);

#endif /* !MY_LIST2_H_ */
