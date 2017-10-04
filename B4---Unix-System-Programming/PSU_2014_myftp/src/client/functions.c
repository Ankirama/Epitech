/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sat Feb 21 22:43:52 2015 Fabien Martinez
*/

#include "my_printf.h"
#include "utils.h"

static char	*_get_filename(char *filepath, char *localpath)
{
  int		i;
  char		*filename;

  i = strlen(filepath) - 1;
  while (i >= 0 && filepath[i] != '/')
    --i;
  filename = strdup(&filepath[i < 0 ? 0 : i + 1]);
  if (localpath == NULL || localpath[strlen(localpath) - 1] == '/')
    {
      localpath = my_realloc(localpath, (!localpath ? 0 : strlen(localpath)) +
			     strlen(filename) + 1);
      localpath[0] = '\0';
      localpath = strcat(localpath, filename);
    }
  free(filename);
  return (localpath);
}

static int	_check_fds(int fd, int socket, char **arr, int nb)
{
  char		*res;

  arr[2] = _get_filename(arr[1], arr[2]);
  if (!(res = get_next_line(socket)))
    return (-1);
  nb = strtol(res, NULL, 10);
  free(res);
  if (nb == -1)
    {
      my_printf(2, "550 %s: No such file or directory\n", arr[1]);
      arr[2] = NULL;
      return (-1);
    }
  if ((fd = open(arr[2], O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
    {
      my_printf(socket, "%d\n", -1);
      my_printf(2, "local: %s: %s\n", arr[2], strerror(errno));
      arr[2] = NULL;
      return (-1);
    }
  free(arr[2]);
  arr[2] = NULL;
  my_printf(socket, "%d\n", fd);
  my_printf(1, "150 Opening BINARY mode data connection for %s\n", arr[1]);
  return (fd);
}

int		my_get(char **arr, int s, int fd, char *size_buf)
{
  unsigned char	*buf;
  long int	len;
  long int	size;

  if ((fd = _check_fds(fd, s, arr, 0)) == -1)
    return (0);
  len = -2;
  if (!(size_buf = get_next_line(s)))
    {
      my_close(fd);
      return (0);
    }
  size = strtol(size_buf, NULL, 10);
  free(size_buf);
  buf = my_malloc(size + 1);
  while (size > 10 || len == -2)
    {
      memset(buf, 0, size + 1);
      size = !(len = my_read(s, buf, size)) ? size : size - len;
      len = my_write(fd, buf, len);
    }
  free(buf);
  my_close(fd);
  my_printf(1, "226 Transfer complete\n");
  return (0);
}

int	user(int socket, char **arr, char *user, char *pwd)
{
  if (!arr || !arr[1])
    my_printf(1, "Name : ");
  if (!arr || !arr[1])
    {
      user = get_next_line(0);
      my_printf(socket, "%s\n", user != NULL ? user : arr[1]);
    }
  else
    user = strdup(arr[1]);
  my_printf(1, "331 Password required for %s\nPassword: ", user);
  pwd = get_next_line(0);
  my_printf(socket, "%s\n", pwd);
  pwd = get_next_line(socket);
  if (strcmp(pwd, "allow") == 0)
    {
      my_printf(1, "230 User %s logged in\n", user ? user : arr[1]);
      free(user);
      return (0);
    }
  else
    {
      my_printf(2, "530 Login incorrect.\nLogin Failed.\n");
      free(user);
      return (1);
    }
}
