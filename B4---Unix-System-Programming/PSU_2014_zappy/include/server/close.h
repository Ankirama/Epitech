/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

#ifndef CLOSE_H_
# define CLOSE_H_

# include "server.h"
# include "team.h"
# include "graphic_cmds.h"

void	close_connection(t_server *server, int fd);
void	close_server(t_server *server);

#endif /* !CLOSE_H_ */
