/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Fri Jul  3 17:29:07 2015 CHARLES VITERBO
*/

#ifndef UTILS_H_
# define UTILS_H_

# include <sys/types.h>
# include <sys/resource.h>
# include <limits.h>
# include <sys/time.h>
# include <netdb.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/select.h>
# include <fcntl.h>
# include <sys/socket.h>
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>
# include <time.h>
# include <signal.h>
# include "my_printf.h"

# define CONV_ABS(x)	((x < 0) ? (-1 * x) : x)

# define ERR_MALLOC	"unable to malloc.\n"

# define GRAPHIC_CLIENT	"GRAPHIC"

# define MAX_BUFF	0x1000

# define CLR_UNDERLINE	"\033[4m"
# define CLR_NORMAL	"\033[0m"

# define TYPE_INFO	0
# define TYPE_ERROR	1

typedef struct sockaddr		t_sockaddr;
typedef struct protoent		t_protoent;
typedef struct sockaddr_in	t_sockaddr_in;

typedef struct	s_list
{
  void		*data;
  unsigned int	size;
  struct s_list	*next;
}		t_list;

typedef struct	s_log
{
  int		log;
  int		error;
}		t_log;

typedef struct timeval	t_my_timeval;

/*
** check_functions.c
*/
t_protoent	*my_name(const char *str);
int		my_s(int domain, int type, int protocol);
int		my_bind(int s, const t_sockaddr *sin, socklen_t addrlen,
			int port);
void		my_listen(int s, int backlog);
int		my_accept(int s, t_sockaddr *sin, socklen_t *sinlen);

/*
** check_sysfunctions.c
*/
void	my_close(int fd);
ssize_t	my_read(int fd, void *buf, size_t size);
ssize_t	my_write(int fd, const void *buf, size_t size);
void	*my_malloc(size_t size);
char	*my_strdup(const char *s);

/*
** check_sysfunctions2.c
*/
void	*my_calloc(size_t count, size_t size);
int	my_open(const char *pathname, int flags);
void	my_exit(int status);

/*
** str_to_wordtab.c
*/
int	array_len(char **array);
void	*free_wordtab(char **arr);
char	**str_to_wordtab(char *str, char sep1, char sep2);

/*
** get_next_line.c
*/
char	*get_next_line(const int fd);

/*
** list.c
*/
int	add_element(t_list **root, void *data, int size);
void	remove_first(t_list **root);
t_list	*create_root();
void    let_it_go(t_list **root);
void	display_list(t_list *root, int fd);

/*
** list2.c
*/
void	remove_element(t_list **root, void *elt_dat);
int	change_element(t_list **root, void *old_data, void *new_data);
int	nb_elements(t_list *root);
t_list	*get_list(t_list *root, void *data);
void	free_cmds(t_list **root);

/*
** list3.c
*/
void	remove_client(t_list **, int);
void	free_list(t_list **);
void	free_link(t_list **);

/*
** nbr.c
*/
char	*int_to_str(int nb);
int	str_nbr(int nb);
int	random_number(int max);
int	restrain_number(int value, int max);
int	str_to_int(char *str, int *error);

/*
** conv.c
*/
int	conv_to_unint(unsigned int *value, char *str);
int	arrlen(char **arr);
char	**split_array(char **argv, int start, int size);

/*
** time.c
*/
long	time_diff(t_my_timeval *start, t_my_timeval *finish);
void	my_gettimeofday(t_my_timeval *timeval);
int	is_time_elapsed(t_my_timeval *start, long time);
char	*xdate();
void	set_timeout(struct timeval *timeval, time_t sec, suseconds_t usec);

/*
** log.c
*/
int	start_log_file();
int	cmd_log(char *cmd, char *func, char *date, int type);
void	nbr_log(char *cmd, int nb, char *func, int type);
int	close_log_file();

#endif /* !UTILS_H_ */
