/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Apr 12 21:10:54 2015 Alexandre Chenevier
*/

#ifndef UTILS_H_
# define UTILS_H_

# include <netdb.h>
# include <stdlib.h>
# include <sys/types.h>
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

# define ERR_MALLOC	"unable to malloc.\n"

# define MAX_BUFF	0x1000
# define DEFAULT_PORT	6667

typedef struct sockaddr		t_sockaddr;
typedef struct protoent		t_protoent;
typedef struct sockaddr_in	t_sockaddr_in;
typedef struct timeval		t_timeval;

typedef struct	s_list
{
  void		*data;
  int		size;
  struct s_list	*next;
}		t_list;

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
void	*my_realloc(void *ptr, size_t size);

/*
** str_to_wordtab.c
*/
int	array_len(char **array);
void	free_wordtab(char **arr);
char	**str_to_wordtab(char *str, char sep1, char sep2);

/*
** get_next_line.c
*/
char	*get_next_line(const int fd);

/*
** list.c
*/
int	add_element(t_list **root, void *data);
void	remove_first(t_list **root);
t_list	*create_root();
void    let_it_go(t_list **root);
void	display_list(t_list *root, int fd);

/*
** list2.c
*/
void	remove_element(t_list **root, void *elt_dat);
void	change_element(t_list **root, void *old_data, void *new_data);
int	nb_elements(t_list *root);
t_list	*get_list(t_list *root, void *data);

/*
** nbr.c
*/
char	*int_to_str(int nb);
int	str_nbr(int nb);

#endif /* !UTILS_H_ */
