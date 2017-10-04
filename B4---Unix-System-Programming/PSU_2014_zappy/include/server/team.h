/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 12:27:20 2015 CHARLES VITERBO
*/

#ifndef TEAM_H_
# define TEAM_H_

# include "server.h"
# include "check_params.h"

void	remove_player(t_server *server, int fd);
int	get_team_index(t_team *teams, int nb_teams, char *nameTeam);
int	better_level_team(t_team *team);
int	create_team(t_server *s, int i, t_opt_arg *opt_arg);
void	increase_level_max(t_server *s, t_client *client);

#endif /* !TEAM_H_ */
