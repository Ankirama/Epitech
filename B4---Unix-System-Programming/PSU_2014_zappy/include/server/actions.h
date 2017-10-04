/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sat Jul  4 05:28:43 2015 Alexandre Chenevier
*/

#ifndef ACTIONS_H_
# define ACTIONS_H_

# include "server.h"
# include "send.h"
# include "team.h"
# include "close.h"
# include "manipulate_map.h"
# include "graphic_cmds.h"

# define UP		1
# define DG_UP_LEFT	2
# define LEFT		3
# define DG_DOWN_LEFT	4
# define DOWN		5
# define DG_DOWN_RIGHT	6
# define RIGHT		7
# define DG_UP_RIGHT	8

# define SIZE		8

# define NB_VISION	8

typedef struct	s_objects
{
  char		*name;
  int		id;
}		t_objects;

/*
** available.c
*/
int	cmd_available(t_server *server, int fd, char **argv);

/*
** broadcast.c
*/
int	cmd_broadcast(t_server *server, int fd, char **argv);
int	difference_coord(t_server *, int, unsigned int, unsigned int);

/*
** dead.c
*/
int	cmd_dead(t_server *server, int fd, char **argv);

/*
** kick.c
*/
int	cmd_fire(t_server *server, int fd, char **argv);

/*
** fork.c
*/
int	cmd_fork(t_server *server, int fd, char **argv);
int	fork_egg(t_server *server);

/*
** incantation.c
*/
int	cmd_incantation(t_server *server, int fd, char **argv);

/*
** inventory.c
*/
int	cmd_inventory(t_server *server, int fd, char **argv);

/*
** movement.c
*/
int	cmd_up(t_server *server, int fd, char **argv);
int	cmd_left(t_server *server, int fd, char **argv);
int	cmd_right(t_server *server, int fd, char **argv);

/*
** objects.c
*/
int	cmd_take_obj(t_server *server, int fd, char **argv);
int	cmd_put_obj(t_server *server, int fd, char **argv);

/*
** show.c
*/
int	cmd_show(t_server *server, int fd, char **argv);

/*
** debug.c
*/
int	cmd_debug(t_server *server, int fd, char **argv);

/*
** annexes_show.c
*/
void	send_case(t_server *server, int fd, t_case *);

#endif /* !ACTIONS_H_ */
