/*
** log.c for log in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Sat Feb 21 01:49:55 2015 Fabien Martinez
** Last update Sun Mar 22 17:38:43 2015 Fabien Martinez
*/

#include "utils.h"
#include "server.h"
#include "my_printf.h"

void	handle_client(int fd_client, const char *ip, t_log *log)
{
  if (my_printf(fd_client, "Connected to the server.\n") == -1 ||
      my_printf(fd_client, "220 Connexion etablished from %s.\n", ip) == -1)
    perror("./server");
  my_printf(fd_client, "%s\n", END_READ);
  my_printf(log->log, "A client is connected with ip : %s\n", ip);
}

char	*create_root(char *path)
{
  char		*pwd;
  char		*ignored;

  if (!(pwd = realpath(path, NULL)))
    {
      perror("./server");
      exit(EXIT_FAILURE);
    }
  pwd = my_realloc(pwd, strlen(pwd) + 2);
  memset(&pwd[strlen(pwd) - strlen("serveur")], 0, strlen("serveur") + 2);
  pwd = strcat(pwd, "./jail");
  chdir(pwd);
  if (!(ignored = realpath(pwd, NULL)))
    {
      perror("./server");
      exit(EXIT_FAILURE);
    }
  free(pwd);
  return (ignored);
}

void	start_log_file(t_log *log, char *port)
{
  char	*log_n;
  char	*error_log;

  if (!(log_n = calloc(strlen("./log_") + strlen(port) + 1, 1)) ||
      !(error_log = calloc(strlen("./error_log_") + strlen(port) + 1, 1)))
    exit(EXIT_FAILURE);
  log_n = strcat(strcat(log_n, "./log_"), port);
  error_log = strcat(strcat(error_log, "./error_log_"), port);
  log->client = 0;
  if ((log->error = open(error_log, O_CREAT | O_WRONLY, 0666)) == -1)
    {
      my_printf(2, "Unable to create or open the error_log file\n");
      log->error = 2;
    }
  my_printf(log->error, "______________________\n");
  my_printf(log->error, "SERVER STARTED\n");
  my_printf(log->error, "______________________\n");
  if ((log->log = open(log_n, O_CREAT | O_WRONLY, 0666)) == -1)
    {
      my_printf(log->error, "Unable to create or open the log file\n");
      log->log = 1;
    }
  my_printf(log->log, "______________________\n");
  my_printf(log->log, "SERVER STARTED\n");
  my_printf(log->log, "______________________\n");
}

/*
** it will write on our log file, if type == 0 then it's a command, else
** it's a leave
*/
void	write_log(t_log *log, char *cmd, int type)
{
  if (type == 0)
    my_printf(log->log, "Client %d wrote : |%s|\n", log->client, cmd);
  else
    my_printf(log->log, "Client %d left the server.\n", log->client);
}

void	close_log_file(t_log *logs)
{
  if (logs->log != 1)
    {
      my_printf(logs->log, "______________________\n");
      my_printf(logs->log, "SERVER STOPPED\n");
      my_printf(logs->log, "______________________\n");
      my_close(logs->log);
    }
  if (logs->error != 2)
    {
      my_printf(logs->error, "______________________\n");
      my_printf(logs->error, "SERVER STOPPED\n");
      my_printf(logs->error, "______________________\n");
      my_close(logs->error);
    }
}
