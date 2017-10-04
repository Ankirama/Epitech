/*
** str.c for str in /home/mar_b/minishell/str
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jun 24 17:32:20 2014 mar_b mar_b
** Last update Sun Aug  3 14:30:31 2014 mar_b
*/

#ifndef UTILS_H_
# define UTILS_H_

# include "list.h"
# include "parser.h"

/*
** my_error.c
*/
void		my_puterror(const char *error);
char		my_error(const char *error, const char *var);
char		my_env_error(char *env, char type, int pos);
void		my_cnf(char *cmd, char **env);
t_parser	*my_parserror(char *str, char quote, t_parser *lst);

/*
** my_str.c
*/
char		my_strcmp(const char *s1, const char *s2, char equal);
int		my_strlen(const char *str);
char		*my_strdup(const char *str);
char		*my_strcat(char *dest, const char *src);
int		my_arrlen(char **arr);

/*
** my_free.c
*/
void		free_arr(char **arr);
void		free_lst(t_list *list);
void		free_parser(t_parser *lst);

/*
** my_write.c
*/
void		my_write(const char *str, const char *color);
void		my_w(const char *str);

/*
** my_set.c
*/
char		*set_my_var(t_list *env, char *code);
char		*set_my_pwd(t_list *env);
void		my_init_env(t_list *env);

/*
** my_nbr.c
*/
int		my_get_nbr(char *str);

/*
** my_conv.c
*/
char		**my_conv_lst(t_list *env);

/*
** my_fun.c
*/
void		my_init(char *str);
void		my_wait();
void		my_dup(int oldfd, int newfd);
void		my_pipe(int pipes[2]);

#endif /* !UTILS_H_ */
