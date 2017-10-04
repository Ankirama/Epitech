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

static int	*g_ports;

/*
** brief: allow us to handle signal like ctlr^C  and do something like close
** @sig: macro like SIGINT
*/
void	sig_handler(int sig)
{
  if (sig == SIGINT)
    {
      my_printf(1, "\n");
      close_server(g_ports);
      exit(EXIT_SUCCESS);
    }
}

/*
** brief: check signals like SIGINT
** @ports: array of ports used to close FD_SERVER port
*/
void	check_signal(int *ports)
{
  g_ports = ports;
  if (signal(SIGINT, sig_handler) == SIG_ERR)
    {
      perror("signal");
      close_server(ports);
      exit(EXIT_FAILURE);
    }
}
