/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Thu Apr 16 08:56:08 2015 Alexandre Chenevier
*/

#include "client.h"
#include "utils.h"

void	to_serv(t_client *client)
{
  client->func_serv[0] = "NICK ";
  client->func_serv[1] = "LIST ";
  client->func_serv[2] = "JOIN ";
  client->func_serv[3] = "PART ";
  client->func_serv[4] = "USERS ";
  client->func_serv[5] = "PRIVMSG ";
  client->func_serv[6] = "QUIT ";
  client->func_serv[7] = "CONNECT ";
}

void	assign_func(t_client *client)
{
  client->func[0] = "/nick";
  client->func[1] = "/list";
  client->func[2] = "/join";
  client->func[3] = "/part";
  client->func[4] = "/users";
  client->func[5] = "/msg";
  client->func[6] = "/quit";
  client->func[7] = "/server";
}

int			set_from_hostname(char *hostname, char *port,
				  struct protoent *pe, t_client *client)
{
  struct addrinfo	hints;
  struct addrinfo	*rp;
  int			errn;
  int			s;

  client->host = hostname;
  client->port = port;
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

void	init_param(t_client *client)
{
  client->message = NULL;
  client->curr_channel = "";
  client->port = NULL;
  client->host = NULL;
  client->nick = NULL;
  client->s = -1;
}

int		main()
{
  t_client	client;

  init_param(&client);
  to_serv(&client);
  assign_func(&client);
  while (client.s < 0)
    init_connection(&client);
  while (client.s)
    {
      set_fd(&client);
      if (select(client.fd_max, &(client.fd_read), &(client.fd_write),
		 NULL, NULL) == -1)
	{
	  my_printf(2, "select: %s\n", strerror(errno));
	  break;
	}
      check_fd(&client);
    }
  if (client.s)
    my_close(client.s);
  return (0);
}
