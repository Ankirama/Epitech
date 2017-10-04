/*
** my_builtin.h for my_builtin in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jun 17 02:26:44 2014 mar_b mar_b
** Last update Sun Jun 22 15:13:38 2014 mar_b mar_b
*/

#ifndef MY_BUILTIN_H_
# define MY_BUILTIN_H_

# include "my_list.h"

char	my_exit(t_list *env, char **arr);
int	my_cd(char **arr);
void	my_setenv(t_list *env, char **arr);
void	my_unsetenv(t_list *env, char **arr);
void	my_env(t_list *env, char **options);

#endif /* !MY_BUILTIN_H_ */
