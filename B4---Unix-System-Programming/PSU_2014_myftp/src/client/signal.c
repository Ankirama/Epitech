/*
** signal.c for signal in /home/ankirama
** 
** Made by 
** Login   <ankirama@ubuntu>
** 
** Started on  Sat Feb 21 19:04:06 2015 
** Last update Sat Feb 21 22:42:02 2015 
*/

#include "utils.h"
#include "my_printf.h"

static int	g_socket;

void	sig_handler(int sig)
{
  if (sig == SIGINT)
    {
      my_close(g_socket);
      my_printf(1, "221 Goodbye.\n");
      exit(EXIT_SUCCESS);
    }
}

void	check_signal(int socket)
{
  g_socket = socket;
  if (signal(SIGINT, sig_handler) == SIG_ERR)
    perror("signal");
}
