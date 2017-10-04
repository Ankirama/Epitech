/*
** signal.c for let it go in /root/rendu/PSU_2013_minitalk/client
**
** Made by mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Aug  5 22:42:10 2014 mar_b
** Last update Wed Aug  6 10:36:08 2014
*/

#include <sys/types.h>
#include <signal.h>
#include "utils.h"

void	my_signal(int signum, void (*fun)(int))
{
  if (signal(signum, fun) == SIG_ERR)
    my_puterror("error: problem with the signal !\n");
}

void	my_kill(pid_t pid, int sig)
{
  if (kill(pid, sig) == -1)
    my_puterror("error: unable to send a signal with kill!\n");
}

void	call_signal(void (*fun)(int))
{
  my_signal(SIGUSR1, fun);
  my_signal(SIGUSR2, fun);
}
