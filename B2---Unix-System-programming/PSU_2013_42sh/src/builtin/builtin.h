/*
** builtin.h for 42sh in /home/zighed_a/rendu/PSU_2013_42sh/src/builtin
** 
** Made by zighed_a zighed_a
** Login   <zighed_a@epitech.net>
** 
** Started on  Wed Sep 17 13:03:15 2014 zighed_a zighed_a
** Last update Fri Oct  3 00:02:18 2014 teyssa_r teyssa_r
*/

#ifndef BUILTIN_H_
# define BUILTIN_H_

# include "list.h"

# define ID_IGNORE	0
# define ID_NULL	1
# define ID_UN		2
# define ID_HELP	3
# define ID_VER		4

# define UNSET(c)	(c != '\0' && c != '\'')

/*
** MY_CD_C_
*/
char	my_cd(t_list *env, char **arr);

/*
** MY_ENV_C
*/
void	my_env_opt(t_list *env, char **arr);

/*
** MY_PWD_C_
*/
char	*my_charpwd();

/*
** MY_BUILTIN_C_
*/
char	my_exit(t_list *env, char **arr);
char	my_pwd(t_list *env, char **arr);
char	my_setenv(t_list *env, char **arr);
char	my_unsetenv(t_list *env, char **arr);
char	my_env(t_list *env, char **arr);

#endif /* !BUILTIN_H_ */
