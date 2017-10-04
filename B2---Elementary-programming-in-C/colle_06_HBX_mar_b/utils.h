/*
** utils.h for let it go in /home/mar_b/colle_06_HBX_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep 30 20:18:28 2014 mar_b mar_b
** Last update Tue Sep 30 22:37:57 2014 mar_b mar_b
*/

#ifndef UTILS_H_
# define UTILS_H_

# include <sys/types.h>
# include "list.h"

# define ERR_MALLOC	"can't perform a malloc!\n"
# define ERR_USAGE	"./text_count [-option] string1 [string2]\n"

# define ID_OPT_T	0
# define ID_OPT_R	1
# define ID_OPT_REV	2
# define ID_OPT_STAT	3
# define ID_OPT_FLY	4

# define OPT_T		"-t"
# define OPT_R		"-r"
# define OPT_REV	"-reverse"
# define OPT_STAT	"-fullstat"
# define OPT_FLY	"-on_the_fly"

/*
** FUN_C_
*/
void	my_putchar(char c);
int	my_strlen(const char *str);
void	*my_malloc(size_t size);
void	my_write(const int fd, const void *str, size_t size);
void	my_puterror(char *str);

/*
** MY_SORT_C_
*/
char	cmp_sup(unsigned int n1, unsigned int n2);
char	cmp_inf(unsigned int n1, unsigned int n2);
char	*my_sort_char(char *str);
void	my_sort_int(t_list **lst, char (*cmp)(unsigned int, unsigned int));

/*
** NBR_C_
*/
void	my_putnbr(unsigned int nbr);

/*
** TRAVEL_C_
*/
t_list	*travel_str(char *str);
t_list	*travel_cmp(char *str, char *cmp, t_list *lst, int i);

/*
** MY_STRCMP_C_
*/
char	my_strcmp(const char *s1, const char *s2);

/*
** MY_OPTION _C_
*/
void	check_option(int argc, char **argv);

#endif /* !UTILS_H_ */
