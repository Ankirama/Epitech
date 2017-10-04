/*
** server.h for server in /root/rendu/PSU_2013_minitalk/server
**
** Made by
** Login   <-n@epitech.net>
**
** Started on  Wed Aug  6 10:07:30 2014
** Last update Wed Aug  6 10:12:22 2014
*/

#ifndef SERVER_H_
# define SERVER_H_

#include <sys/types.h>

typedef struct	s_server
{
  char		letter;
  char		i;
  int		pid_client;
  char		done;
}		t_server;

#endif /* !SERVER_H_ */
