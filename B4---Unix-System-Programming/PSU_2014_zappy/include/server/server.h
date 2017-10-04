/*
** server.h for  in /home/viterb_c/rendu/PSU_2014_zappy
** 
** Made by CHARLES VITERBO
** Login   <viterb_c@epitech.net>
** 
** Started on  Thu Jun 18 09:30:38 2015 CHARLES VITERBO
** Last update Fri Jun 26 14:09:40 2015 CHARLES VITERBO
*/

#ifndef SERVER_H_
# define SERVER_H_

/*
** @file server.h
** @brief server
** @author ankirama
** @version 0.7
*/

# define MAX_FD		255

# define TIMEOUT_SEC	15
# define TIMEOUT_USEC	0

# define FD_FREE	0
# define FD_CLIENT	1
# define FD_SERVER	2
# define FD_GFX		3

# define MAX_PORT	65535

# define DEFAULT_PORT	4224
# define NB_PORTS	0

# define MAX_MSG	512

# define NB_FCT_ZAPPY	13

# define BUF_SIZE	255

# define LVL_MAX	8

# define MOVE_LEFT(x)	(x == 0 ? DIR_LEFT : x - 1)
# define MOVE_RIGHT(x)	(x == 3 ? DIR_UP : x + 1)

# include "utils.h"
# include "object.h"

/*
** @brief function to write/read with tcp
*/
typedef void	(*fct)();
typedef int	(*zappy)();

typedef struct	s_client
{
  int		graphic;
  int		playerId;
  char		*team;
  unsigned int	inventaire[NB_OBJ];
  int		food;
  int		level;
  int		orientation;
  unsigned int	pos;
  int		fd;
  int		created;
  t_list	*cmds;
  t_my_timeval	start_cmd;
  long		time_cmd;
  t_my_timeval	start_life;
}		t_client;

typedef struct	s_fork
{
  int		id;
  int		father;
  t_my_timeval	time;
  char		*team;
  unsigned int	position;
}		t_fork;

typedef struct	s_function
{
  char		*name;
  zappy		fct_zappy;
  int		exec_time;
}		t_function;

typedef struct	s_case
{
  int		food;
  unsigned int  stones[NB_OBJ];
  t_list	*players;
}		t_case;

typedef struct	s_map
{
  unsigned int	width;
  unsigned int	height;
  t_case	*map;
}		t_map;

typedef struct	s_team
{
  char		*name;
  t_list	*players;
  int		nb_lvl_max;
  int		nb_players;
  int		max_players;
  t_list	*forks;
}		t_team;

/*
** @struct t_server
** @brief main struct for the server
**
** It will contain our differents fd, clients and func to write and read
*/
typedef struct	s_server
{
  int		debug_mode;
  t_list	**write_buffer;
  int		*type_fd;
  fct		*fct_read;
  fct		*fct_write;
  int		*ports;
  int		fd_max;
  int		curr_max;
  int		nb_fd;
  fd_set	fd_read;
  fd_set	fd_write;
  t_client	*client;
  t_team	*teams;
  int		nb_teams;
  t_map		map;
  unsigned int	client_start;
  unsigned int	time;
  t_list	*forks;
}		t_server;

/*
** debug.c send
*/
void	send_msg_nbs(t_server *server, int fd, char *msg, int nb);
int	send_msg_nb(t_server *server, int fd, char *msg, int nb);
void	send_msg_str(t_server *server, int fd, char *msg, char *str);

#endif /* !SERVER_H_ */
