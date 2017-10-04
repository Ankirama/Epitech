/*
** check.c for check in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Sat Feb 21 06:41:24 2015 Fabien Martinez
** Last update Sat Feb 21 21:06:10 2015 Fabien Martinez
*/

#include "server.h"
#include "my_printf.h"

char	check_get(int fd, char *filepath, int socket)
{
  int		i;
  char		*res;
  int		nb;

  i = strlen(filepath) - 1;
  while (i >= 0 && filepath[i] != '/')
    --i;
  if (i >= 0 || fd == -1)
    {
      my_printf(socket, "%d\n", -1);
      return (1);
    }
  my_printf(socket, "%d\n", fd);
  if (!(res = get_next_line(socket)))
    return (1);
  nb = strtol(res, NULL, 10);
  if (nb == -1)
    {
      if (fd != -1)
	my_close(fd);
      my_printf(2, "Problem with remote file\n");
      return (1);
    }
  return (0);
}

static int	_check_function(t_cmd *cmds, char *str)
{
  int		i;

  i = 0;
  while (i < NB_CMD && strcmp(str, cmds[i].name))
    ++i;
  return (i < NB_CMD ? i : NB_CMD);
}

int		check_command(char *str, int client_s, char *ignored,
			      t_log *log)
{
  char		**arr;
  int		i;
  static t_cmd	cmds[NB_CMD + 1] = {
    {"ls", my_ls},
    {"cd", my_cd},
    {"pwd", my_pwd},
    {"user", my_user},
    {"get", my_get},
    {"quit", my_quit},
    {"(null)", my_quit},
    {NULL, my_invalid}
  };

  arr = str_to_wordtab(str);
  write_log(log, str, 0);
  if (arr == NULL || arr[0] == NULL)
    {
      my_printf(client_s, "%s\n", END_READ);
      return (arr == NULL ? 1 : 0);
    }
  i = _check_function(cmds, arr[0]);
  return (cmds[i].fnc(arr, client_s, ignored));
}
