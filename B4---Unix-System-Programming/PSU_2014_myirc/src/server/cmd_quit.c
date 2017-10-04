/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Fri Mar  6 22:56:39 2015 Fabien Martinez
*/

#include "server.h"

int	cmd_quit(t_server *server, int fd, char **argv)
{
  (void)server;
  (void)fd;
  (void)argv;
  return (1);
}
