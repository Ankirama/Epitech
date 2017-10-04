/*
** utils.h for utils in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul 11 18:14:37 2014 mar_b mar_b
** Last update Wed Jul 16 22:13:56 2014 mar_b mar_b
*/

#ifndef UTILS_H_
# define UTILS_H_

# include "rtv1.h"

/*
** free.c
*/
void		let_it_go(t_window *param);

/*
** error.c
*/
void		my_puterror(char *error);

/*
** str.c
*/
int		my_strlen(const char *str);
char		*my_strdup(const char *str);
int		my_getnbr(const char *str);
void		my_write(char *str);
void		display_progession(char i);

/*
** conv.c
*/
float		char_to_float(const char *str, int end);
int		char_to_int(const char *str, int end);
unsigned int	conv_color(const char *color, const char *base);
void		put_nbr(char nbr);
#endif /* !UTILS_H_ */
