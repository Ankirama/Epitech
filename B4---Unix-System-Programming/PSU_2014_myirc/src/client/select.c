/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Thu Apr 16 12:56:56 2015 Alexandre Chenevier
*/

#include "client.h"

void	set_fd(t_client *client)
{
  client->fd_max = client->s + 1;
  FD_ZERO(&(client->fd_read));
  FD_ZERO(&(client->fd_write));
  FD_SET(client->s, &(client->fd_read));
  FD_SET(client->s, &(client->fd_write));
  FD_SET(1, &(client->fd_read));
  FD_SET(1, &(client->fd_write));
}

void	check_fd(t_client *client)
{
  if (FD_ISSET(client->s, &(client->fd_read)))
    {
      memset(client->by_serv, '\0', MAX_BUFF + 1);
      my_read(client->s, client->by_serv, MAX_BUFF);
    }
  if (FD_ISSET(1, &(client->fd_read)))
    loop_func(client);
  if (FD_ISSET(1, &(client->fd_write)))
    {
      if (client->by_serv != NULL)
	{
	  my_printf(1, "%s\n", client->by_serv);
	  free(client->by_serv);
	  client->by_serv = NULL;
	}
    }
  if (FD_ISSET(client->s, &(client->fd_write)))
    loop_write(client);
}
