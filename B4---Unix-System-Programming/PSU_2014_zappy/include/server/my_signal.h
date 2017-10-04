/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

#ifndef MY_SIGNAL_H_
# define MY_SIGNAL_H_

# include "server.h"
# include "close.h"

void	sig_handler(int sig);
void	check_signal(t_server *server);

#endif /* !MY_SIGNAL_H_ */
