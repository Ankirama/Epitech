/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sat Feb 21 19:10:10 2015 Fabien Martinez
*/

#ifndef UTILS_H_
# define UTILS_H_

# include <netdb.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
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

# define ERR_MALLOC	"unable to malloc.\n"

# ifndef PATH_MAX
#  define PATH_MAX	4096
# endif

# define SIZE_BUFF	4096
# define MAX_BUFF	10
# define END_READ	"c4e959444d9fd5c7daa675b89865f1d6"

typedef struct sockaddr		t_sockaddr;
typedef struct protoent		t_protoent;
typedef struct sockaddr_in	t_sockaddr_in;

/*
** check_functions.c
*/
t_protoent	*my_getprotobyname(const char *str);
int		my_socket(int domain, int type, int protocol);
void		my_bind(int s, const t_sockaddr *sin, socklen_t addrlen);
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
void	free_wordtab(char **arr);
char	**str_to_wordtab(char *str);

/*
** get_next_line.c
*/
char	*get_next_line(const int fd);

#endif /* !UTILS_H_ */
