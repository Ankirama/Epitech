/*
** my_set_var.h for my_set_var in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jun 17 01:44:11 2014 mar_b mar_b
** Last update Sun Jun 22 06:31:46 2014 mar_b mar_b
*/

#ifndef MY_SET_VAR_H_
# define MY_SET_VAR_H_

# include "my_list.h"

char	*set_my_var(t_list *env, char *code);
char	*set_my_pwd(t_list *env);
void	my_init_env(t_list *lst);

#endif /* !MY_SET_VAR_H_ */
