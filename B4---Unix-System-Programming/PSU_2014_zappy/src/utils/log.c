/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Jul  1 13:53:32 2015 CHARLES VITERBO
*/

/*
** @file log.c
** @brief log functions
** @author ankirama
** @vesion 1.0
*/

#include "utils.h"

static t_log	g_logs;

/*
** @brief
**
** @param fd our client's fd
** @param msg the message to send
** @param to_free
**
** @return 1
*/
static int	_server_connec_display(int fd, char *msg, char *to_free)
{
  char		*date;

  my_printf(fd, "______________________\n");
  date = xdate();
  if (date != NULL)
    my_printf(fd, "%s at %s\n", msg, date);
  else
    my_printf(fd, "%s\n", msg);
  free(date);
  my_printf(fd, "______________________\n");
  if (to_free != NULL)
    free(to_free);
  return (1);
}

/*
** @brief
*/
int	start_log_file()
{
  char	*log_n;
  char	*error_log;

  if (!(log_n = my_strdup("logs/zappy.log")))
    return (1);
  if (!(error_log = my_strdup("logs/error_zappy.log")))
    {
      free(log_n);
      return (1);
    }
  if ((g_logs.error = open(error_log, O_CREAT | O_WRONLY | O_APPEND, 0666))
      == -1)
    {
      my_printf(2, "Unable to create or open the error_log file\n");
      g_logs.error = 2;
    }
  _server_connec_display(g_logs.error, "SERVER STARTED", error_log);
  if ((g_logs.log = open(log_n, O_CREAT | O_WRONLY | O_APPEND, 0666)) == -1)
    {
      my_printf(g_logs.error, "Unable to create or open the log file\n");
      g_logs.log = 1;
    }
  return (_server_connec_display(g_logs.log, "SERVER STARTED", log_n));
}

/*
** @brief
**
** @return
*/
int	close_log_file()
{
  if (g_logs.log != 1)
    {
      _server_connec_display(g_logs.log, "SERVER STOPPED", NULL);
      my_close(g_logs.log);
    }
  if (g_logs.error != 2)
    {
      _server_connec_display(g_logs.error, "SERVER STOPPED", NULL);
      my_close(g_logs.error);
    }
  return (1);
}

/*
** @brief
**
** @param cmd
** @param func
** @param date
** @param type
**
** @return
*/
int	cmd_log(char *cmd, char *func, char *date, int type)
{
  int	fd;

  fd = type == TYPE_INFO ? g_logs.log : g_logs.error;
  if (func != NULL)
    {
      if (date != NULL)
	my_printf(fd, "From [%s] at %s:\n\t%s\n", func,
		  date, cmd == NULL ? "Error malloc" : cmd);
      else
	my_printf(fd, "From [%s]:\n\t%s\n", func,
		  cmd == NULL ? "Error malloc" : cmd);
    }
  else
    {
      if (date != NULL)
	my_printf(fd, "At %s:\n\t%s\n", func,
		  date, cmd == NULL ? "Error malloc" : cmd);
      else
	my_printf(fd, "%s\n", func, cmd == NULL ? "Error malloc" : cmd);
    }
  free(date);
  return (-1);
}

/*
** @brief
**
** @param cmd
** @param nb
** @param func
** @param type
*/
void	nbr_log(char *cmd, int nb, char *func, int type)
{
  int	fd;
  char	*date;

  date = xdate();
  fd = type == TYPE_INFO ? g_logs.log : g_logs.error;
  if (func != NULL)
    {
      if (date != NULL)
	my_printf(fd, "From [%s] at %s:\n\t%d %s\n", func,
		  date, nb, cmd == NULL ? "Error malloc" : cmd);
      else
	my_printf(fd, "From [%s]:\n\t%d %s\n", func, nb,
		  cmd == NULL ? "Error malloc" : cmd);
    }
  else
    {
      if (date != NULL)
	my_printf(fd, "At %s:\n\t%d: %s\n", date,
		  nb, cmd == NULL ? "Error malloc" : cmd);
      else
	my_printf(fd, "%d %s\n", nb, cmd == NULL ? "Error malloc" : cmd);
    }
  free(date);
}
