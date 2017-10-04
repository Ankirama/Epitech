/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

#ifndef CREATE_CLIENT_H_
# define CREATE_CLIENT_H_

# include "server.h"
# include "send.h"
# include "graphic_cmds.h"

int	add_client(t_server *s, int fd, char **arr, int idx);

#endif /* !CREATE_CLIENT_H_ */
