/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sat Feb 21 22:46:02 2015 Fabien Martinez
*/

#include "server.h"
#include "my_printf.h"
#include "utils.h"

static char	*_root_pwd(char *str, char *ignored)
{
  char		*pwd;

  if (!(pwd = my_malloc(sizeof(char) * (strlen(str) + strlen(ignored) + 2))))
    return (NULL);
  memset(pwd, 0, strlen(str) + strlen(ignored) + 2);
  pwd = strcat(pwd, ignored);
  pwd = strcat(pwd, "/");
  pwd = strcat(pwd, str);
  return (pwd);
}

static char	*_validate_pwd(char *str, char *ignored)
{
  char		*dest;
  char		*pwd;

  if (str[0] == '/')
    {
      if (!(pwd = _root_pwd(str, ignored)))
	return (NULL);
    }
  else
    pwd = strdup(str);
  if (!(dest = realpath(pwd, NULL)))
    {
      perror("./server realpath");
      free(pwd);
      return (NULL);
    }
  if (strncmp(dest, ignored, strlen(ignored)) != 0)
    {
      free(dest);
      free(pwd);
      return (NULL);
    }
  free(pwd);
  return (dest);
}

int	my_cd(char **arr, int socket, char *ignored)
{
  char	*pwd;

  if (arr[1] != NULL)
    {
      if (!(pwd = _validate_pwd(arr[1], ignored)))
	my_printf(socket, "550 %s: No such file or directory\n", arr[1]);
      else if (access(pwd, F_OK) == -1)
	my_printf(socket, "550 %s/: No such file or directory\n",
		  &pwd[strlen(ignored)]);
      else if (access(pwd, R_OK) == -1)
	my_printf(socket, "550 %s/: Permission Denied\n", &pwd[strlen(ignored)]);
      else if (chdir(pwd) == -1)
	my_printf(socket, "550 %s/: %s\n", &pwd[strlen(ignored)], strerror(errno));
      else
	my_printf(socket, "250 CWD command successful\n");
      free(pwd);
    }
  my_printf(socket, "%s\n", END_READ);
  free_wordtab(arr);
  return (0);
}

int	my_pwd(char **arr, int socket, char *ignored)
{
  char	pwd[SIZE_BUFF];

  (void)arr;
  if (getcwd(pwd, SIZE_BUFF) == NULL)
    my_printf(socket, "550: %s\n", strerror(errno));
  else
    my_printf(socket, "227 \"%s/\" is the current directory\n",
	      &pwd[strlen(ignored)]);
  my_printf(socket, "%s\n", END_READ);
  free_wordtab(arr);
  return (0);
}
