/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

#ifndef GRAPHIC_CMDS_H_
# define GRAPHIC_CMDS_H_

# include "server.h"
# include "send.h"

/*
** map.c
*/
void	map_size(t_server *server);
void	get_cell(t_server *server, int idx);
void	get_all_cells(t_server *server);

/*
** error.c
*/
void	unknown_cmd(t_server *server);
void	wrong_cmd(t_server *server);

/*
** player.c
*/
void	player_new(t_server *server, int idx);
void	player_pos(t_server *server, int idx);
void	player_level(t_server *server, int idx);
void	player_inventory(t_server *s, int idx);
void	player_kick(t_server *s, int idx);

/*
** player2.c
*/
void	player_broadcast(t_server *server, int idx);
void	player_egg(t_server *server, int idx);
void	player_put(t_server *server, int idx, int id_obj);
void	player_take(t_server *server, int idx, int id_obj);
void	player_dead(t_server *server, int idx);

/*
** player3.c
*/
void	player_start_incant(t_server *server, int idx);
void	player_end_incant(t_server *server, int idx, int success);

/*
** team.c
*/
void	team_names(t_server *server);

/*
** egg.c
*/
void	egg_hatched(t_server *server, int idx);
void	egg_connected(t_server *server, int idx);
void	egg_died(t_server *server, int idx);
void	egg_created(t_server *server, int idx, t_fork *fork);

/*
** server.c
*/
void	server_get_time(t_server *server, int time);
void	server_winner(t_server *server, char *team);
void	server_message(t_server *server, char *msg);

/*
** graphic.c
*/
int	set_graphic_client(t_server *server, int fd, int i, int j);

#endif /* !GRAPHIC_CMDS_H_ */
