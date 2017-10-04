/*
** fun.h for fun in /home/mar_b/rendu/colle1_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Aug 26 20:26:48 2014 mar_b mar_b
** Last update Tue Aug 26 22:31:06 2014 mar_b mar_b
*/

#ifndef UTILS_H_
# define UTILS_H_

# include <sys/types.h>

# define ERR_MALLOC	"Can't perform a malloc\n"
# define ERR_NBR	"Your number isn't valid (nbr > 0)\n"
# define ERR_SECARG	"Wrong syntax for the second argument\n"
# define ERR_THIRARG	"Wrong syntax for the third argument\n"
# define ERR_SECTHI_ARG	"Second and first arguments are not equal.\n"
# define ERR_USAGE	"Usage: ./fractals 2 \"##@# \" \"  @  \"\n"
# define ERR_NTARGS	"Error, need 3 arguments\n"

# define DEFAULT_SHARP	"\n#\n"
# define NORMAL_USAGE	"Fractals are not implemanted\n"

/*
** fun.c
*/
int	my_strlen(const char *str);
void	my_puterror(const char *str);
void	my_write(const int fd, const void *buf, size_t count);

/*
** nbr.c
*/
int	my_getnbr(const char *str);

/*
** my_check_arg.c
*/
char	my_check_arg(const char *s1, const char *s2);

#endif /* !UTILS_H_ */
