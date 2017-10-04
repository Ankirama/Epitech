/*
** func_fill.c for func_fill.c in /home/chenev_d/rendu/PSU_2014_myirc/src/client
** 
** Made by Alexandre Chenevier
** Login   <chenev_d@epitech.net>
** 
** Started on  Sat Apr 11 02:16:22 2015 Alexandre Chenevier
** Last update Thu Apr 16 09:08:08 2015 Alexandre Chenevier
*/

#include "utils.h"
#include "client.h"

void	fill_nick(t_client *client, char *word, char *before, char *all)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  client->nick = my_malloc(sizeof(char) + strlen(all) +
			   strlen(word) - strlen(before) + 1);
  while (word[i] != '\0')
    client->nick[j++] = word[i++];
  i = strlen(before) + 1;
  while (all[i] != '\0')
    client->nick[j++] = all[i++];
  client->nick[j] = '\0';
}

void	fill_word(t_client *client, char *word, char *before, char *all)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  client->message = my_malloc(sizeof(char) + strlen(all) +
                           strlen(word)- strlen(before) + 1);
  while (word[i] != '\0')
    client->message[j++] = word[i++];
  i = strlen(before) + 1;
  while (all[i] != '\0')
    client->message[j++] = all[i++];
  client->message[j] = '\0';
}

void	fill_for_msg(t_client *client, char *word, char *all)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  client->message = my_malloc(sizeof(char) + strlen(all) +
                           strlen(word) + strlen(client->curr_channel) + 2);
  client->message[0] = '\0';
  while (word[i] != '\0')
    client->message[j++] = word[i++];
  i = 0;
  while (client->curr_channel[i] != '\0')
    client->message[j++] = client->curr_channel[i++];
  i = 0;
  client->message[j++] = ' ';
  client->message[j++] = ':';
  while (all[i] != '\0')
    client->message[j++] = all[i++];
  client->message[j] = '\0';
}

void	fill_for_privmsg(t_client *client, char *word, char *before, char *all)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  client->message = my_malloc(sizeof(char) + strlen(all) +
                           strlen(word) - strlen(before) + 1);
  while (word[i] != '\0')
    client->message[j++] = word[i++];
  i = strlen(before) + 1;
  while (all[i] != ' ')
    client->message[j++] = all[i++];
  client->message[j++] = ' ';
  client->message[j++] = ':';
  i++;
  while (all[i] != '\0')
    client->message[j++] = all[i++];
  client->message[j] = '\0';
}

void	fill_connect(t_client *client)
{
  char	**array;

  array = str_to_wordtab(client->buffer, ' ', ' ');
  if (!(client->pe = getprotobyname("TCP")))
    exit (2);
  if (array[2] == NULL)
    client->s = set_from_hostname(array[1],
				  int_to_str(DEFAULT_PORT), client->pe, client);
  else if (array[2][0] == ':')
    client->s = set_from_hostname(array[1],
				  &(array[2][1]), client->pe, client);
}
