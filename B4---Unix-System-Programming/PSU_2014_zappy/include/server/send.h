/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

#ifndef SEND_H_
# define SEND_H_

# include "server.h"
# include "close.h"

char	*create_error_msg(char *value, char *msg);
int	send_msg(t_server *server, int fd, char *message);
int	send_nbrs(t_server *server, int fd, int val1, int val2);
void	write_client(t_server *server, int fd);

#endif /* !SEND_H_ */
