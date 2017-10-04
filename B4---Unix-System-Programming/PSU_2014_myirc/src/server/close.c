/*
** main.c<2> for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Apr 12 21:24:11 2015 Alexandre Chenevier
*/

#include "server.h"

/*
** brief: it will close ouf fd opened from server (FD_SERVER)
** @server: our structure
*/
void		close_server(int *ports)
{
  int		i;
  int		ok_server;

  i = -1;
  ok_server = 0;
  while (++i < MAX_FD)
    {
      if (ports[i] == FD_SERVER)
	{
	  ok_server = 1;
	  my_close(ports[i]);
	}
    }
  if (ok_server)
    my_printf(1, "Server(s) IRC closed\n");
}
