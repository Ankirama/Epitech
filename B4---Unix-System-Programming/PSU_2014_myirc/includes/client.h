/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Thu Apr 16 08:51:15 2015 Alexandre Chenevier
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include "utils.h"

#define	FUNC	7
#define USA_CL	"/server hostname [:port]\n"

typedef struct		s_client
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  int			s;
  char			*port;
  int			error;
  char			to_serv[MAX_BUFF + 1];
  char			buffer[MAX_BUFF + 1];
  char			*func[8];
  char			*func_serv[8];
  char			*message;
  char			*curr_channel;
  char			*host;
  char			*nick;
  fd_set		fd_read;
  fd_set		fd_write;
  int			fd_max;
  t_timeval		timeout;
  char			*by_serv;
}			t_client;

int	set_from_hostname(char *, char *, struct protoent *, t_client *);

void	set_fd(t_client *client);
void	check_fd(t_client *client);
void	fill_nick(t_client *, char *, char *, char *);
void	fill_word(t_client *, char *, char *, char *);
void	fill_for_msg(t_client *, char *, char *);
void	fill_for_privmsg(t_client *, char *, char *, char *);
void	fill_connect(t_client *);
void	loop_write(t_client *);
void	next_loop(t_client *);
void	loop_func(t_client *);
void	to_rw(t_client *);
void	for_select(t_client *);
void	init_connection(t_client *);
void	fill_channel(t_client *);
void	empty_channel(t_client *);
void	fill_for_user(t_client *, char *);

#endif /* !CLIENT_H_ */
