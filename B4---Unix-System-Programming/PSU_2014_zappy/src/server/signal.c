/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

/*
** @file signal.c
** @brief handle signals like SIGINT
** @author ankirama
** @version 1.0
*/

#include "my_signal.h"

static t_server	*g_server;
/*
** @brief allow us to handle signal
**
** We can handle signal like ctlr^C and do something like close
**
** @param sig macro like SIGINT
*/
void	sig_handler(int sig)
{
  if (sig == SIGINT)
    {
      my_printf(1, "\n");
      close_server(g_server);
      exit(EXIT_SUCCESS);
    }
}

/*
** @brief check signals like SIGINT
**
** @param server main structure
*/
void	check_signal(t_server *server)
{
  g_server = server;
  if (signal(SIGINT, sig_handler) == SIG_ERR ||
      signal(SIGPIPE, SIG_IGN) == SIG_ERR)
    {
      cmd_log(strerror(errno), "signal", xdate(), TYPE_ERROR);
      close_server(server);
      exit(EXIT_FAILURE);
    }
}
