/*
** main.c<2> for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 10:31:18 2015 Fabien Martinez
*/

/*
** @file check_functions.c
** @brief basic functions with check error and exit
** @author ankirama
** @version 1.0
*/

#include "utils.h"

/*
** @brief getprotobyname like with error check
**
** exit if any error
**
** @param str protocole to get
** @return return structure protoent
*/
t_protoent	*my_name(const char *str)
{
  t_protoent	*pe;

  if (!(pe = getprotobyname(str)))
    {
      cmd_log("problem with getprotobyname", "my_name", xdate(), TYPE_ERROR);
      my_exit(EXIT_FAILURE);
    }
  return (pe);
}

/*
** @brief socket like with error check
**
** exit if any error
**
** @param domain specifies a communication domain
** @param type specifies the communication semantics.
** @param protocol specifies a particular protocol to be used with the socket
** @return socket created (fd like)
*/
int	my_s(int domain, int type, int protocol)
{
  int	s;

  if ((s = socket(domain, type, protocol)) == -1)
    {
      cmd_log(strerror(errno), "my_s", xdate(), TYPE_ERROR);
      my_exit(EXIT_FAILURE);
    }
  return (s);
}

/*
** @brief bind like with error like
**
** @param s socket fd
** @param sin used to assigns adress
** @param addrlen specifies the size in byte of the adress structure
** @param port used to display an error
** @return -1 if any error, else 0
*/
int	my_bind(int s, const t_sockaddr *sin, socklen_t addrlen, int port)
{
  if (bind(s, sin, addrlen) == -1)
    {
      nbr_log(strerror(errno), port, "my_bind", TYPE_ERROR);
      return (-1);
    }
  return (0);
}

/*
** @brief listen like with error check
**
** exit if any error
**
** @param s socket fd
** @param backlog defines  the  maximum length to the queue
*/
void	my_listen(int s, int backlog)
{
  if ((listen(s, backlog)) == -1)
    {
      cmd_log(strerror(errno), "my_listen", xdate(), TYPE_ERROR);
      my_close(s);
      my_exit(EXIT_FAILURE);
    }
}

/*
** @brief accept like with error check
**
** @param s socket fd
** @param sin pointer to a sockaddr structure
** @param sinlen sin's size
** @return -1 if any error, socket fd created else
*/
int	my_accept(int s, t_sockaddr *sin, socklen_t *sinlen)
{
  int	client_s;

  if ((client_s = accept(s, sin, sinlen)) == -1)
    {
      cmd_log(strerror(errno), "my_accept", xdate(), TYPE_ERROR);
      my_close(s);
      return (-1);
    }
  return (client_s);
}
