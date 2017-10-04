/*
** utils.h for utils.h in /home/lefebv_1/rendu/colle5_mar_b
**
** Made by lefebv_1 lefebv_1
** Login   <lefebv_1@epitech.net>
**
** Started on  Tue Sep 23 19:10:05 2014 lefebv_1 lefebv_1
** Last update Tue Sep 23 22:44:55 2014 mar_b mar_b
*/

#ifndef UTILS_H_
# define UTILS_H_

# include <sys/types.h>

# define ERR_ARG "Usage: ./my_boogle [-s SIZE] [-g GRIP] [-w WORLD] --color\n"
# define ERR_MALLOC "malloc error\n"
# define ERR_ARG_TAB "arg_tab error\n"
# define ERR_GRID "syntax error for [-g GRID]\n"
# define ERR_GRID_LITTLE "syntax error: [-g GRID] is to little\n"
# define ERR_GRID_BIG "syntax error: [-g GRID] is to big\n"
# define ERR_WORD "syntax error for [-w WORD]\n"
# define ERR_SIZE "syntax error for [-s SIZE]\n"

# define ARG_SIZE "-s"
# define ARG_GRID "-g"
# define ARG_WORD "-w"
# define ARG_COLOR "--color"

typedef struct	s_option
{
  int		size;
  char		*grid;
  char		*word;
  char		color;
}		t_option;

/*
** MY_SIZE
*/
void	my_size(char *, t_option *);

/*
** MY_WORD
*/
void	my_word(char *, t_option *);

/*
** MY_GRID
*/
void	my_grid(char *, t_option *);

/*
** MY_COLOR
*/
void	my_color(char *, t_option *);


/*
** MY_CHECK_OPTIONS
*/
void	my_check_option(int, char **, t_option *);

/*
** MY_FUN
*/
int	my_strlen(const char *);
void	my_write(const int, const char *, size_t);
void	my_putstr(const char *, const int);
void	my_puterror(const char *);

/*
** MY_STRCMP
*/
int	my_strcmp(const char *, const char *);

/*
** NBR_C_
*/
int	my_getnbr(const char *str);

#endif /* !UTILS_H_ */
