/*
** main.c for let it go in /home/mar_b/rendu/PSU_2013_minitalk/server
**
** Made by mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Aug  5 10:15:44 2014 mar_b
** Last update Thu Aug  7 21:02:28 2014
*/

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "server.h"
#include "utils.h"

static int	_pow(int nbr, char power)
{
  if (power == 0)
    return (1);
  else
    return (nbr * _pow(nbr, power - 1));
}

static void	_get_char(t_server *server, int c)
{
  if (server->i < 8 && c == 1)
    server->letter += _pow(2, server->i);
  else if (server-> i == 8)
    {
      my_write(1, &(server->letter), 1);
      if (server->letter == '\0')
	{
	  server->done = 0;
	  server->pid_client = 0;
	  my_write(1, "\n\033[32;1mConnexion closed\033[0m\n",
		   my_strlen("\n\033[32;1mConnexion closed\033[0m\n"));
	}
      server->letter = 0;
      server->i = -1;
    }
  my_kill(server->pid_client, SIGUSR1);
}

static void	_get_pid(t_server *server, int c)
{
  if (server->i < 32 && c == 1)
    {
      server->pid_client += _pow(2, server->i);
      usleep(200);
    }
  else if (server->i == 32)
    {
      server->done = 1;
      server->i = -1;
      my_write(1, "\033[32;1mConnexion etablished with PID ",
	       my_strlen("\033[32;1mConnexion etablished with PID "));
      my_putnbr(server->pid_client);
      my_write(1, "\033[0m\n", my_strlen("\033[0m\n"));
    }
}

static void		_fun(int sig)
{
  static t_server	server = {0, -1, 0, 0};
  int			c;

  my_signal(SIGUSR1, _fun);
  my_signal(SIGUSR2, _fun);
  c = (sig == SIGUSR1) ? 0 : 1;
  ++(server.i);
  if (!server.done)
    _get_pid(&server, c);
  else
    {
      printf("COMON...\n");
      _get_char(&server, c);
    }
}

int	main()
{
  my_signal(SIGUSR1, _fun);
  my_signal(SIGUSR2, _fun);
  my_write(1, "PID SERVER : ", my_strlen("PID SERVER : "));
  my_putnbr(getpid());
  my_write(1, "\n", 1);
  while (1)
    pause();
  return (0);
}
