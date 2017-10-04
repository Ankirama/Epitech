/*
** main.c<2> for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 10:32:07 2015 Fabien Martinez
*/

#ifndef SERVER_H_
# define SERVER_H_

# include "utils.h"

# define MAX_CLIENTS	255
# define MAX_FD		255

# define HOSTNAME	"log.horizon.sao"

# define DEFAULT_PORT	6667
# define NB_PORTS	0

# define FD_FREE	0
# define FD_CLIENT	1
# define FD_SERVER	2

# define TIMEOUT_SEC	20

# define LEN_NAME	255
# define BUF_SIZE	255

# define MAX_MSG	512

/*
** for channels
*/
# define MAX_CHANNELS	10
# define MAX_USERS	10

# define NB_FCT_IRC	8

# define ERR_UNKNOWNCOMMAND	421

# define RPL_LUSERCLIENT	251
# define RPL_LUSEROP		252
# define RPL_LUSERUNKNOWN	253
# define RPL_LUSERCHANNELS	254
# define RPL_LUSERME		255
# define RPL_MOTDSTART		375
# define RPL_MOTD		372
# define RPL_ENDOFMOTD		376

/*
** /nick _nickname_ messages
*/
# define ERR_NONICKNAMEGIVEN	431
# define ERR_NICKNAMEINUSE	433
# define ERR_ERRONEUSNICKNAME	432

/*
** /list [string] messages
*/
# define ERR_NOSUCHNICK		401
# define RPL_LISTSTART		321
# define RPL_LIST		322
# define RPL_LISTEND		323

/*
** /join _channel_ messages
*/
# define ERR_NEEDMOREPARAMS	461
# define ERR_CHANNELISFULL	471
# define ERR_NOSUCHCHANNEL	403
# define ERR_TOOMANYCHANNELS	405
# define RPL_NAMREPLY		353
# define RPL_ENDOFNAMES		366

/*
** /part _channel_ messages
** ERR_NEEDMOREPARAMS
** ERR_NOSUCHCHANNEL
*/
# define ERR_NOTONCHANNEL	442

/*
** /users messages
** RPL_ENDOFNAMES
** RPL_NAMREPLY
*/

/*
** _message_ messages (PRIVMSG #current_channel _message_)
*/
# define ERR_NOTEXTTOSEND	412

/*
** /msg _nicknake_ _message_ (PRIVSG _nickname_ _message_)
** ERR_NOSUCHNICK
*/
# define ERR_NORECIPIENT	411
# define ERR_CANNOTSENDTOCHAN	404

typedef void	(*fct)();
typedef int	(*irc)();

typedef struct	s_function
{
  irc		fct_irc;
  char		*name;
}		t_function;

typedef struct		s_channel
{
  char			*name;
  int			nb_users;
  t_list		*clients;
  struct s_channel	*next;
}			t_channel;

typedef struct	s_client
{
  char		*nick;
  char		*hostname;
  int		nb_channels;
  t_list	*channels;
}		t_client;

typedef struct	s_server
{
  char		*hostname;
  t_list	*write_buffer[MAX_FD];
  int		type_fd[MAX_FD];
  fct		fct_read[MAX_FD];
  fct		fct_write[MAX_FD];
  int		*ports;
  int		fd_max;
  fd_set	fd_read;
  fd_set	fd_write;
  t_timeval	timeout;
  t_channel	*channels;
  t_client	client[MAX_FD];
}		t_server;

/*
** send.c
*/
char	*create_error_msg(char *value, char *msg);
void	send_code_msg(t_server *server, int fd, int code, char *err);
void	send_info_msg(t_server *server, int fd, char *nick, char *message);
void	write_client(t_server *server, int fd);

/*
** cmd_nick.c
*/
int	cmd_nick(t_server *server, int fd, char **argv);

/*
** cmd_join.c
*/
int	cmd_join(t_server *server, int fd, char **argv);
char	*get_user_list(t_server *server, char *channel);

/*
** cmd_part.c
*/
int	cmd_part(t_server *server, int fd, char **argv);

/*
** cmd_names.c
*/
int	cmd_names(t_server *server, int fd, char **argv);

/*
** cmd_list.c
*/
int	cmd_list(t_server *server, int fd, char **argv);

/*
** cmd_privmsg.c
*/
int	cmd_privmsg(t_server *server, int fd, char **argv);

/*
** cmd_users.c
*/
int	cmd_users(t_server *server, int fd, char **argv);

/*
** cmd_quit.c
*/
int	cmd_quit(t_server *server, int fd, char **argv);

/*
** interpret_message.c
*/
int	interpret_message(t_server *server, int fd, t_list *list);

/*
** read.c
*/
void	read_server(t_server *server, int fd);

/*
** port.c
*/
int	set_ports(t_server *server, char *port);

/*
** create_server.c
*/
void	create_server(t_server *server, char *port, int i, int s);

/*
** close.c
*/
void	close_server(int *ports);

/*
** signal.c
*/
void	check_signal(int *ports);

/*
** channel.c
*/
void		add_channel(t_channel **chans, char *name);
t_channel	*get_channel(t_channel *chans, char *name);
void		free_channels(t_channel **chans);
void		remove_channel(t_channel **chan, char *name);
char		*nb_channel(t_channel *chans);

/*
** welcome.c
*/
void	welcome(t_server *server, int fd);

#endif /* !SERVER_H_ */
