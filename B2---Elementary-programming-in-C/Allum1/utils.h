/*
** utils.h for utils in /home/mar_b/rendu/Allum1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul  1 10:57:10 2014 mar_b mar_b
** Last update Thu Jul  3 13:14:36 2014 mar_b mar_b
*/

#ifndef UTILS_H_
# define UTILS_H_

# define ID_SIZE	4
# define ID_OCTET	8

# include "list.h"

/*
** utils.c
*/
char	same_binary(const t_list *lst, const t_list *tmp, int i);
void	my_exit(t_list *lst);
void	my_init(char *buff);

/*
** str.c
*/
int	my_strlen(const char *str);
char	*my_strdup(const char *src);

/*
** message.c
*/
void	my_puterror(const char *message);
void	my_error(const char *message);
char	my_victory(const char *player);

/*
** calc.c
*/
char	*int_to_bin(int nbr);
int	bin_to_int(const char *bin);
int	my_pow(const int nbr, int pow);
char	*operation_xor(t_list *lst);
int	my_get_nbr(const char *str);

#endif /* !UTILS_H_ */
