/*
** main.c<2> for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

#include "server.h"

/*
** brief: set our timeout used by select(2) AND the hostname...
** @server: our structure
*/
static void	_set_values(t_server *server)
{
  server->timeout.tv_sec = TIMEOUT_SEC;
  server->timeout.tv_usec = 0;
  server->hostname = strdup(HOSTNAME);
  server->channels = NULL;
}

/*
** brief: it will set our server
** @server: our structure we will set
** @port: argv[1] like 42:500 (range port)
** @i: index used to travel array of port
** @s: socket fd
** BRIEF: we will check every fd form our range ports and set good function
** BRIEF: for read and write.
** BRIEF: we weill set our timeout and our ports too
** BRIEF: if we try to set more than max fd then we will stop to set them
** BRIEF: and warn the user
*/
void		create_server(t_server *server, char *port, int i, int s)
{
  t_sockaddr_in	sin;

  set_ports(server, port);
  _set_values(server);
  memset(server->type_fd, FD_FREE, sizeof(int) * MAX_FD);
  while (s < MAX_FD && server->ports[++i] != -1)
    {
      if ((s = my_s(AF_INET, SOCK_STREAM, my_name("TCP")->p_proto)) >= MAX_FD)
	break;
      sin.sin_family = AF_INET;
      sin.sin_port = htons(server->ports[i]);
      sin.sin_addr.s_addr = INADDR_ANY;
      if (my_bind(s, (const t_sockaddr *)&sin, sizeof(sin),
		  server->ports[i]) == -1)
	continue;
      my_printf(1, "Server IRC started on port %d\n", server->ports[i]);
      my_listen(s, MAX_CLIENTS);
      server->type_fd[s] = FD_SERVER;
      server->fct_read[s] = read_server;
      server->fct_write[s] = 0;
    }
  if (s >= MAX_FD)
    my_printf(2, "You cannot create more than %d servers!\n", MAX_FD);
  if (s >= MAX_FD)
    my_close(s);
}
