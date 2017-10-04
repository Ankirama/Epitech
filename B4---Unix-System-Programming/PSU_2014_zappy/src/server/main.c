/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 14:00:00 2015 CHARLES VITERBO
*/

#include "server.h"
#include "create_server.h"
#include "my_signal.h"
#include "close.h"
#include "check_params.h"
#include "check_fd.h"

/*
** @brief call read/write function for each FD used
**
** @param server our main structure
*/
static void	_check_fd(t_server *s, int error)
{
  int		i;

  if (error > 0)
    {
      i = -1;
      while (++i <= s->curr_max)
	{
	  if (FD_ISSET(i, &(s->fd_read)))
	    s->fct_read[i](s, i);
	  if ((s->type_fd[i] == FD_CLIENT || s->type_fd[i] == FD_GFX) &&
	      FD_ISSET(i, &(s->fd_write)))
	    s->fct_write[i](s, i);
	}
    }
}

/*
** @brief display usage message
**
** @return 1
*/
static int	_usage()
{
  my_printf(1, "Usage: bin/server -p %sPORT%s[%s:RANGE%s] -x %sWIDTH%s",
	    CLR_UNDERLINE, CLR_NORMAL, CLR_UNDERLINE, CLR_NORMAL,
	    CLR_UNDERLINE, CLR_NORMAL);
  my_printf(1, " -y %sHEIGHT%s -n %sTEAM1%s [%sTEAM2%s]... -c %sCLIENTS%s",
	    CLR_UNDERLINE, CLR_NORMAL, CLR_UNDERLINE, CLR_NORMAL, CLR_UNDERLINE,
	    CLR_NORMAL, CLR_UNDERLINE, CLR_NORMAL);
  my_printf(1, " -t %sTIME%s", CLR_UNDERLINE, CLR_NORMAL);
  my_printf(1, " [%s--debug%s]\n", CLR_UNDERLINE, CLR_NORMAL);
  return (1);
}

/*
** @brief when a team is victorious
**
** @param s our server's structure
**
** @return 1 if a team is victorious else 0
*/
static int	_victory(t_server *s)
{
  int		i;

  i = -1;
  while (++i < s->nb_teams)
    if (s->teams[i].nb_lvl_max >= 6)
      {
	cmd_log(s->teams[i].name, "_victory", xdate(), TYPE_INFO);
	return (1);
      }
  return (0);
}

/*
** @brief Set variable into our main struct
**
** It will set some variables like hostname and players in our server struct
** It will set teams too, map, nb clients to start and time
** It will call create_server too
**
** @param server our structure
** @param opt_arg structure with all info from console
** @param i set to -1 (norme etc...)
** @return 1 if any problem, 0 else
*/
static int	_set_values(int argc, char **argv, t_server *s, int i)
{
  t_opt_arg	*opt_arg;

  if ((opt_arg = set_options(argc, argv)) == NULL)
    return (_usage());
  if ((s->map.width = opt_arg->x) <= 0 || (s->map.height = opt_arg->y) <= 0 ||
      (s->client_start = opt_arg->clients) <= 0 ||
      (s->time = opt_arg->time) <= 0)
    {
      my_printf(2, "-x, -y -c and -t must be > 0\n");
      return (_usage());
    }
  if (create_server(s, opt_arg->port, -1, 0) == -1 ||
      !(s->map.map = my_malloc(sizeof(t_case) * (opt_arg->x * opt_arg->y))) ||
      !(s->teams = my_malloc(sizeof(t_team) * (arrlen(opt_arg->teams) + 1))))
    return (1);
  s->debug_mode = opt_arg->debug;
  if (s->debug_mode)
    my_printf(1, "Debug mode enabled\n");
  if (generate_map(&s->map) == -1)
    return (1);
  while (++i < arrlen(opt_arg->teams))
    if (create_team(s, i, opt_arg) == -1)
      return (1);
  s->nb_teams = arrlen(opt_arg->teams);
  return (free_options(opt_arg));
}

/*
** @brief main function
**
** Main loop to user select for read and write with tcp
**
** @param argc number arguments (with binary path)
** @return EXIT_SUCCESS (0)
*/
int		main(int argc, char **argv)
{
  t_server	server;
  int		error;

  error = start_log_file();
  if (_set_values(argc, argv, &server, -1) == 1)
    return (close_log_file());
  check_signal(&server);
  while (error != 0 && (error = set_fd(&server, 0, -1)) != -1)
    {
      if ((error = select(server.fd_max, &(server.fd_read), &(server.fd_write),
			  NULL, NULL)) == -1)
	{
	  cmd_log(strerror(errno), "select", xdate(), TYPE_ERROR);
	  break;
	}
      else if (error == 0)
	cmd_log("timeout select", "main", xdate(), TYPE_INFO);
      if (_victory(&server) == 1)
	  break;
      _check_fd(&server, error);
    }
  if (error != -1)
    close_server(&server);
  return (EXIT_SUCCESS);
}
