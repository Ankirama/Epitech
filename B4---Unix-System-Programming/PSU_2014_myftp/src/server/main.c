/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Mar 22 17:38:21 2015 Fabien Martinez
*/

#include <unistd.h>
#include "server.h"
#include "my_printf.h"

static void	_get_client(int s, char *ignored, char *ip_client, t_log *log)
{
  char		*cmd;
  int		quit;

  quit = 0;
  handle_client(s, ip_client, log);
  if (my_user(NULL, s, NULL))
    {
      write_log(log, NULL, 1);
      my_close(s);
      exit(EXIT_FAILURE);
    }
  while (!quit)
    {
      cmd = get_next_line(s);
      quit = check_command(cmd, s, ignored, log);
      free(cmd);
    }
  write_log(log, NULL, 1);
  my_close(s);
}

static int	_fork_me(int s, char *ignored, t_log *log)
{
  int		client_s;
  t_sockaddr_in	sin_client;
  socklen_t	sin_size;
  pid_t		pid;

  sin_size = sizeof(sin_client);
  client_s = my_accept(s, (t_sockaddr *)&sin_client,  &sin_size);
  ++(log->client);
  if ((pid = fork()) == -1)
    {
      perror("./server");
      return (EXIT_FAILURE);
    }
  else if (pid == 0)
    _get_client(client_s, ignored, inet_ntoa(sin_client.sin_addr), log);
  else
    {
      my_close(client_s);
      return (_fork_me(s, ignored, log));
    }
  return (0);
}

int			main(int argc, char **argv)
{
  char			*ignored;
  struct protoent	*pe;
  struct sockaddr_in	sin;
  int			s;
  t_log			log;

  if (argc < 2)
    return (my_printf(2, "Usage : ./serveur port\n") & 0x1);
  start_log_file(&log, argv[1]);
  if ((!(pe = getprotobyname("TCP"))))
    return (EXIT_FAILURE);
  s = my_socket(AF_INET, SOCK_STREAM, pe->p_proto);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(atoi(argv[1]));
  sin.sin_addr.s_addr = INADDR_ANY;
  my_bind(s, (const struct sockaddr *)&sin, sizeof(sin));
  my_listen(s, 10);
  ignored = create_root(argv[0]);
  check_signal(s, &log);
  _fork_me(s, ignored, &log);
  close_log_file(&log);
  free(ignored);
  my_close(s);
  return (EXIT_SUCCESS);
}
