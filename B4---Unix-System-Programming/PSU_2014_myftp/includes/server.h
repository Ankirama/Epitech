/*
** my_check.h for my_check in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Mar 22 17:39:09 2015 Fabien Martinez
*/

#ifndef SERVER_H_
# define SERVER_H_

# include "my_ls.h"
# include "server.h"
# include "utils.h"
# include <errno.h>

# define NB_CMD	7

typedef struct	s_cmd
{
  char		*name;
  int		(*fnc)(char **, int, char *);
}		t_cmd;

typedef struct	s_log
{
  int		client;
  int		log;
  int		error;
}		t_log;

/*
** builtins.c
*/
int	my_cd(char **arr, int socket, char *ignored);
int	my_pwd(char **arr, int socket, char *ignored);

/*
** functions.c
*/
int	my_quit(char **arr, int socket, char *ignored);
int	my_invalid(char **arr, int socket, char *ignored);
int	my_user(char **arr, int socket, char *ignored);
int	my_get(char **arr, int socket, char *ignored);

/*
** log.c
*/
char	*create_root(char *path);
void	handle_client(int fd_client, const char *ip, t_log *log);
void	start_log_file(t_log *log, char *port);
void	write_log(t_log *log, char *cmd, int type);
void	close_log_file(t_log *logs);

/*
** check.c
*/
char	check_get(int fd, char *filepath, int socket);
int	check_command(char *str, int client_s, char *ignored, t_log *log);

/*
** signal.c
*/
void	sig_handler(int sig);
void	check_signal(int socket, t_log *log);

#endif /* !SERVER_H_ */
