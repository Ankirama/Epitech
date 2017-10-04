/*
** minishell2.h for minishell2 in /home/mar_b/minishell
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jun 25 21:27:13 2014 mar_b mar_b
** Last update Sun Aug  3 14:02:43 2014
*/

#ifndef MINISHELL2_H_
# define MINISHELL2_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "parser.h"

# define ID_EOF	0
# define BUFF	512

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define CYAN	"\033[1;36m"
# define BLUE	"\033[1;34m"
# define YELLOW	"\033[1;33m"

# define PERM	S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH

# define PATH	"/bin:/sbin:/usr/bin:/usr/sbin"
# define ENV	"/usr/bin/env"

# include "list.h"

/*
** my_check.c
*/
char	*my_path(char *path);
int	my_builtin_fun(char **arr, t_list *env);
char	my_check_fun(char **arr, t_list *env);

/*
** my_exec.c
*/
char	my_exec_pipe(t_list *env, char **exec_opt, char *path);
char	my_exec(t_list *env, char **exec_opt, char *path);

/*
** redirection.c
*/
char	dup_stdout(t_parser **lst, t_list *env);
char	dup_stdout_err(t_parser **lst, t_list *env);
char	dup_stdin_sim(t_parser **lst, t_list *env);

/*
** pipe.c
*/
char	pipe_cmd(t_parser **par, t_list *env);

#endif /* !MINISHELL2_H_ */
