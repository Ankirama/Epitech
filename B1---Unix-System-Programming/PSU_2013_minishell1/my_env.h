/*
** my_env.h for my_env.h in /home/user/rendu/PSU_2013_minishell1
**
** Made by 
** Login   
**
** Started on  Tue Jun 17 03:46:54 2014 
** Last update Sat Jun 21 03:23:38 2014 
*/

#ifndef MY_ENV_H_
# define MY_ENV_H_

# define ID_IGNORE	0
# define ID_NULL	1
# define ID_UN		2
# define ID_HELP	3
# define ID_VER		4

# include "my_list.h"

# define UNSET(c)	(c != '\0' && c != '\'')

char	my_env_opt(t_list *env, char **var);

#endif /* !MY_ENV_H_ */
