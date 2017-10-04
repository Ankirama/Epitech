/*
** utils.h for utils in /home/mar_b/rendu/colle3_bob42
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep  9 19:28:14 2014 mar_b mar_b
** Last update Tue Sep  9 22:22:45 2014 mar_b mar_b
*/

#ifndef UTILS_H_
# define UTILS_H_

# include <sys/types.h>

/*
** FUN_C_
*/
int	my_strlen(const char *str);
void	my_write(int fd, const void *buf, size_t count);
char	*my_strncat(char *s1, char *s2, int len);
void	*my_malloc(size_t size);
char	*my_put_in_str(int nbr);

/*
** NBR_C_
*/
void	my_put_nbr(int nb);
int	my_getnbr(const char *str, int limit);
int	size_nbr(int nbr);

/*
** ERROR_C_
*/
void	my_puterror(const char *str);

/*
** MY_OP_C_
*/
int	my_add(const int nb1, const int nb2);
int	my_sub(const int nb1, const int nb2);
int	my_mul(const int nb1, const int nb2);
int	my_div(const int nb1, const int nb2);
int	my_mod(const int nb1, const int nb2);

/*
** STR_C_
*/
char	*convert_minus(char *str);
char	*my_new_str(char *str, int rslt, int start, int end);

#endif /* !UTILS_H_ */
