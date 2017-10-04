/*
** check_channel.c for check_channel in /home/chenev_d/rendu/PSU_2014_myirc/src/client
** 
** Made by Alexandre Chenevier
** Login   <chenev_d@epitech.net>
** 
** Started on  Thu Apr 16 05:25:43 2015 Alexandre Chenevier
** Last update Thu Apr 16 13:27:50 2015 Alexandre Chenevier
*/

#include "client.h"

void	fill_channel(t_client *client)
{
  char	**array;

  array = str_to_wordtab(client->buffer, ' ', ' ');
  if (array[1] != NULL && array[1][1] != '\0' && array[1][0] == '#')
    client->curr_channel = array[2];
}

void	empty_channel(t_client *client)
{
  char	**array;

  array = str_to_wordtab(client->buffer, ' ', ' ');
  if (array[1] != NULL && array[1][1] != '\0' && array[1][0] == '#'
      && array[1] == client->curr_channel)
    client->curr_channel = "";
}

void	fill_for_user(t_client *client, char *word)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  client->message = my_malloc(sizeof(char) +
			      strlen(word) + strlen(client->curr_channel) + 2);
  client->message[0] = '\0';
  while (word[i] != '\0')
    client->message[j++] = word[i++];
  i = 0;
  while (client->curr_channel[i] != '\0')
    client->message[j++] = client->curr_channel[i++];
  client->message[j] = '\0';
}
