/*
** main.c<2> for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 10:31:18 2015 Fabien Martinez
*/

#include "utils.h"

t_protoent	*my_name(const char *str)
{
  t_protoent	*pe;

  if (!(pe = getprotobyname(str)))
    {
      fprintf(stderr, "./server: problem with getprotobyname(%s).\n", str);
      exit(EXIT_FAILURE);
    }
  return (pe);
}

int	my_s(int domain, int type, int protocol)
{
  int	s;

  if ((s = socket(domain, type, protocol)) == -1)
    {
      perror("socket");
      exit(EXIT_FAILURE);
    }
  return (s);
}

int	my_bind(int s, const t_sockaddr *sin, socklen_t addrlen, int port)
{
  if (bind(s, sin, addrlen) == -1)
    {
      my_printf(2, "bind port %d: %s\n", port, strerror(errno));
      my_close(s);
      return (-1);
    }
  return (0);
}

void	my_listen(int s, int backlog)
{
  if ((listen(s, backlog)) == -1)
    {
      perror("listen");
      my_close(s);
      exit(EXIT_FAILURE);
    }
}

int	my_accept(int s, t_sockaddr *sin, socklen_t *sinlen)
{
  int	client_s;

  if ((client_s = accept(s, sin, sinlen)) == -1)
    {
      perror("accept");
      my_close(s);
      return (-1);
    }
  return (client_s);
}
