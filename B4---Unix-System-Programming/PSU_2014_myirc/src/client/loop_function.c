/*
** loop_function.c for loop_function in /home/chenev_d/rendu/PSU_2014_myirc/src/client
** 
** Made by Alexandre Chenevier
** Login   <chenev_d@epitech.net>
** 
** Started on  Sun Apr 12 19:04:37 2015 Alexandre Chenevier
** Last update Thu Apr 16 13:30:57 2015 Alexandre Chenevier
*/

#include "client.h"

void	loop_write(t_client *client)
{
  if (client->nick != NULL)
    {
      my_printf(client->s, "%s\n", client->nick);
      client->nick = NULL;
    }
  else
    {
      if (client->message != NULL || client->message != '\0')
	{
	  my_printf(client->s, "%s", client->message);
	  free(client->message);
	  client->message = NULL;
	}
    }
}

void	func_quit(t_client *client)
{
  my_printf(client->s, "QUIT\n");
  close(client->s);
  exit(1);
}

void	next_loop(t_client *client)
{
  int	i;

  i = 0;
  while (i < FUNC && strncmp(client->buffer, client->func[i],
			     strlen(client->func[i])) != 0)
    ++i;
  if (i == 6)
    func_quit(client);
  else if (i == 5)
    fill_for_privmsg(client, client->func_serv[i],
		     client->func[i], client->buffer);
  else if (i == 4)
    fill_for_user(client, client->func_serv[4]);
  else
    {
      if (i == 2)
	fill_channel(client);
      else if (i == 3)
	empty_channel(client);
      fill_word(client, client->func_serv[i],
		client->func[i], client->buffer);
    }
}

void	init_connection(t_client *client)
{
  if (my_read(1, client->buffer, MAX_BUFF))
    {
      if ((client->host == NULL) &&
          strncmp(client->buffer, client->func[0],
                  strlen(client->func[0])) == 0)
        fill_nick(client, client->func_serv[0],
                  client->func[0], client->buffer);
      else if (strncmp(client->buffer, client->func[7],
                       strlen(client->func[7])) == 0)
        {
          fill_connect(client);
          my_read(client->s, client->to_serv, MAX_BUFF);
	  my_printf(1, "%s", client->to_serv);
        }
      else
        write(1, USA_CL, strlen(USA_CL));
    }
}

void	loop_func(t_client *client)
{
  memset(client->buffer, '\0', MAX_BUFF);
  if (my_read(1, client->buffer, MAX_BUFF))
    {
      next_loop(client);
      if (client->buffer[0] != '/')
	fill_for_msg(client, client->func_serv[5], client->buffer);
    }
}
