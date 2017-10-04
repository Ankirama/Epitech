/*
** main.c for let it go in /home/mar_b/rendu/PSU_2013_minitalk/client
**
** Made by mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Aug  5 10:15:25 2014 mar_b
** Last update Thu Aug  7 18:27:32 2014
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <signal.h>
#include <unistd.h>
#include "utils.h"

static char	g_received = 1;

static void	_handle(int sig)
{
  my_signal(SIGUSR1, _handle);
  if (sig == SIGUSR1)
    g_received = 1;
}

static void	_signals(char sig, int pid_serv)
{
  if (sig == 0)
    my_kill(pid_serv, SIGUSR1);
  else if (sig == 1)
    my_kill(pid_serv, SIGUSR2);
}

static void	_send_pid(int my_pid, int pid_serv)
{
  char		i;
  int		tmp;

  i = 0;
  tmp = my_pid;
  while (i < 32)
    {
      _signals(tmp & 1, pid_serv);
      tmp = tmp >> 1;
      usleep(1000);
      ++i;
    }
}

static void	_send_char(char c, int pid)
{
  char		i;
  static int	timeout = 0;

  i = 0;
  while (i < 8)
    {
      printf("DEBUG --> c : %d\n", c & 1);
      _signals(c & 1, pid);
      while (!g_received && timeout < 10000)
	{
	  usleep(20);
	  ++timeout;
	}
      c = c >> 1;
      if (timeout >= 10000)
	my_puterror("error: timeout with the server!\n");
      timeout = 0;
      g_received = 0;
      ++i;
    }
}

int	main(int argc, char **argv)
{
  int	pid;
  int	my_pid;
  int	i;

  if (argc != 3)
    my_puterror("Usage: ./client PID_SERVER YOUR_MESSAGE\n");
  pid = my_getnbr(argv[1]);
  i = -1;
  my_signal(SIGUSR1, _handle);
  my_pid = getpid();
  printf("MY PID : %d\n", my_pid);
  _send_pid(my_pid, pid);
  while (argv[2][++i] != '\0')
    _send_char(argv[2][i], pid);
  _send_char('\0', pid);
  return (0);
}
