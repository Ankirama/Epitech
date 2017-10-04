/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sat Feb 21 22:37:32 2015 Fabien Martinez
*/

#include "my_printf.h"
#include "server.h"
#include "utils.h"

int	my_quit(char **arr, int socket, char *ignored)
{
  free_wordtab(arr);
  (void)ignored;
  my_printf(socket, "221 Goodbye.\n");
  my_printf(socket, "%s\n", END_READ);
  return (1);
}

int	my_invalid(char **arr, int socket, char *ignored)
{
  (void)arr;
  (void)ignored;
  my_printf(socket, "?Invalid command.\n");
  my_printf(socket, "%s\n", END_READ);
  free_wordtab(arr);
  return (0);
}

static char _check_user(char *user, char *pwd)
{
  if ((!strcmp(user, "Anonymous") && !strcmp(pwd, "")) ||
      (!strcmp(user, "root") && !strcmp(pwd, "toor")))
    return (1);
  return (0);
}

int	my_user(char **arr, int __attribute__ ((unused)) socket,
		char __attribute__ ((unused)) *ignored)
{
  char	*log[2];
  char	allow;

  if (!arr || !arr[1])
    log[0] = get_next_line(socket);
  else
    log[0] = strdup(arr[1]);
  log[1] = get_next_line(socket);
  allow = _check_user(log[0], log[1]);
  free(log[0]);
  free(log[1]);
  if (allow)
    my_printf(socket, "allow\n");
  else
    {
      my_printf(socket, "forbidden\n");
      return (1);
    }
  free_wordtab(arr);
  return (0);
}

int		my_get(char **arr, int socket, char *ignored)
{
  unsigned char	*buf;
  int		fd;
  struct stat	st;

  (void)ignored;
  if (arr[1] != NULL)
    {
      fd = stat(arr[1], &st);
      fd = fd == -1 ? -1 : open(arr[1], O_RDONLY);
      if (check_get(fd, arr[1], socket))
	return (0);
      my_printf(socket, "%ld\n", st.st_size);
      buf = my_malloc(st.st_size + 1);
      memset(buf, 0, st.st_size + 1);
      my_read(fd, buf, st.st_size);
      my_write(socket, buf, st.st_size);
      my_close(fd);
    }
  free_wordtab(arr);
  return (0);
}
