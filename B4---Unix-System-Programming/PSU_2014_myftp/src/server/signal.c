/*
** signal.c<2> for signal in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Sat Feb 21 19:44:24 2015 Fabien Martinez
** Last update Sat Feb 21 19:50:58 2015 Fabien Martinez
*/

#include "utils.h"
#include "my_printf.h"
#include "server.h"

static int	g_socket;
static t_log	*g_log;

void	sig_handler(int sig)
{
  if (sig == SIGINT)
    {
      my_close(g_socket);
      close_log_file(g_log);
      exit(EXIT_SUCCESS);
    }
}

void	check_signal(int socket, t_log *log)
{
  g_socket = socket;
  g_log = log;
  if (signal(SIGINT, sig_handler) == SIG_ERR)
    {
      perror("signal");
      my_close(socket);
      close_log_file(log);
      exit(EXIT_FAILURE);
    }
}
