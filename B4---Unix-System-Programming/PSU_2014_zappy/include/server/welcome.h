/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

#ifndef WELCOME_H_
# define WELCOME_H_

# include "server.h"
# include "team.h"
# include "send.h"
# include "graphic_cmds.h"
# include "create_client.h"

int	check_creation_client(t_server *server, int fd, char **arr, char *msg);
void	welcome(t_server *server, int fd);

#endif /* !WELCOME_H_ */
