/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

#ifndef READ_H_
# define READ_H_

# include "server.h"
# include "interpret_message.h"
# include "send.h"
# include "welcome.h"
# include "close.h"

void	read_server(t_server *server, int fd);

#endif /* !READ_H_ */
