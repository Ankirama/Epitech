/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sat Feb 21 22:09:13 2015 Fabien Martinez
*/

#include "utils.h"
#include "my_printf.h"
#include "client.h"

static void	_handle_server(int s)
{
  char		*str;

  while ((str = get_next_line(s)) != NULL && strcmp(str, END_READ) != 0)
    {
      my_printf(1, "%s\n", str);
      free(str);
    }
  if (str != NULL)
    free(str);
}

static void	_getlines(int s)
{
  char		*res;

  while ((res = get_next_line(s)) &&
	 strcmp(res == NULL ? "" : res, END_READ) != 0)
    {
      my_printf(1, "%s\n", res);
      free(res);
    }
  if (res)
    free(res);
}

static int	_loop(int s)
{
  char		*cmd;
  char		**arr;

  my_printf(1, "ftp> ");
  cmd = get_next_line(0);
  my_printf(s, "%s\n", cmd);
  while (cmd && strncmp(cmd, "quit", 4) && strcmp(cmd, "(null)"))
    {
      arr = str_to_wordtab(cmd);
      if (arr && arr[0] && arr[1] && (!strcmp(arr[0], "get")))
	(void)my_get(arr, s, 0, NULL);
      else if (arr && arr[0] && !strcmp(arr[0], "user"))
	(void)user(s, arr, NULL, NULL);
      else
	_getlines(s);
      free(cmd);
      my_printf(1, "ftp> ");
      cmd = get_next_line(0);
      my_printf(s, "%s\n", cmd);
    }
  free_wordtab(arr);
  my_printf(1, "%s221 Goodbye.\n", cmd ? "" : "\n");
  return (0);
}

static int		_set_from_hostname(char *hostname, char *port,
					   struct protoent *pe)
{
  struct addrinfo	hints;
  struct addrinfo	*rp;
  int			errn;
  int			s;

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  hints.ai_protocol = pe->p_proto;
  if ((errn = getaddrinfo(hostname, port, &hints, &rp)) != 0)
    {
      fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errn));
      exit(EXIT_FAILURE);
    }
  if ((s = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
    return (-1);
  if (connect(s, rp->ai_addr, rp->ai_addrlen) == -1)
    {
      my_close(s);
      return (-1);
    }
  return (s);
}

int			main(int argc, char **argv)
{
  struct protoent	*pe;
  int			s;

  usage(argc);
  if (!(pe = getprotobyname("TCP")))
    return (EXIT_FAILURE);
  if ((s = _set_from_hostname(argv[1], argv[2], pe)) == -1)
    {
      perror("./client");
      return (EXIT_FAILURE);
    }
  check_signal(s);
  _handle_server(s);
  if (user(s, NULL, NULL, NULL))
    {
      my_close(s);
      return (EXIT_FAILURE);
    }
  (void)_loop(s);
  my_close(s);
  return (EXIT_SUCCESS);
}
