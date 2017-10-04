/*
** builtin.h for builtin in /home/mar_b/minishell/builtin
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jun 23 21:44:48 2014 mar_b mar_b
** Last update Wed Jun 25 00:39:32 2014 mar_b mar_b
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
** my_cd.c
*/
char	my_cd(t_list *env, char **arr);

/*
** my_env.c
*/
void	my_env_opt(t_list *env, char **arr);

/*
** my_pwd.c
*/
char	*my_charpwd();

/*
** my_builtin.c
*/
char	my_exit(t_list *env, char **arr);
char	my_pwd(t_list *env, char **arr);
char	my_setenv(t_list *env, char **arr);
char	my_unsetenv(t_list *env, char **arr);
char	my_env(t_list *env, char **arr);

#endif /* !BUILTIN_H_ */
