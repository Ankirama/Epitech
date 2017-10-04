/*
** utils.h for utils in /home/mar_b/rendu/CPE_2014_corewar/utils
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul 15 15:06:25 2014 mar_b mar_b
** Last update Wed Aug  6 10:36:17 2014
*/

#ifndef UTILS_H_
# define UTILS_H_

#include <sys/types.h>

/*
** str.c
*/
void	my_write(int fd, const char *str, int size);
int	my_strlen(const char *str);
char	*my_strdup(const char *str);

/*
** nbr.c
*/
void	my_putnbr(const int nbr);
int	my_getnbr(const char *str);

/*
** error.c
*/
void	my_puterror(char *);

/*
** signal.c
*/
void	my_signal(int signum, void (*fun)(int));
void	my_kill(pid_t pid, int sig);
void	call_signal(void (*fun)(int));

#endif /* !UTILS_H_ */
