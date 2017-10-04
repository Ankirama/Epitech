/*
** utils.h for utils in /home/mar_b/rendu/CPE_2014_corewar/utils
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul 15 15:06:25 2014 mar_b mar_b
** Last update Thu Oct  2 22:50:43 2014 chenev_d chenev_d
*/

#ifndef UTILS_H_
# define UTILS_H_

# define ERR_NBR	"' is not a valid number !\n"
# define ERR_MALLOC	"Can't permorf a malloc\n"
# define ERR_CLOSE_P	"impossible to close the fd in pipe.c\n"
# define ERR_TGETSTR	"Error: impossible to get the string entry for id.\n"
# define ERR_TGETENT_0	"Error: there no such entry. (tgetent)\n"
# define ERR_TGETENT_1	"Error: terminfo database could not be found.\n"
# define ERR_TCGETATTR	"Error: impossible to get "
# define ERR_TCSETATTR	"Error: impossible to set "
# define ERR_TERM	"'TERM' environment variable not set.\n"
# define ERR_TC		"the parameters associated with the terminal.\n"
# define ERR_FORK	"Error in fork().\n"
# define ERR_WPID	"Error in waitpid().\n"
# define ERR_PAR	"Error in parent process.\n"
# define ERR_CHD	"Error in child process.\n"
# define ERR_PIP	"Error in pipe().\n"

# include "lexer.h"
# include "list.h"

/*
** STR_C_
*/
int		my_strlen(const char *str);
char		*my_strdup(const char *str);
char		my_strcmp(const char *s1, const char *s2, const char equal);
char		*my_strcat(const char *src, char *dest);
int		my_arrlen(char **arr);

/*
** NBR_C_
*/
int		my_getnbr(const char *str, char *error);
void		my_putnbr(int nbr, const int fd);

/*
** ERROR_C_
*/
char		my_puterror(char *error);
void		*my_puterror_null(char *error);
void		*my_puterror_tc(char *error1, char *error2);
void		*my_puterror_tc(char *errorn, char *error2);

/*
** FREE_C_
*/
void		free_arr(char **arr);
void		free_lst(t_list *list);
void		free_ast(t_ast *ast);
void		free_eof(t_list *env);

/*
** FUN_C_
*/
void		my_init(char *buf, int size);

/*
** DUPARRAY_C_
*/
char		**dup_array(char **str);

/*
** ERROR_CLOSE_C_
*/
char		my_error_close(const char *error, const char *var);

#endif /* !UTILS_H_ */
