/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sat Jun 27 15:53:43 2015 CHARLES VITERBO
*/

/*
** @file send.c
** @brief functions to send some messages to a fd
** @author ankirama
** @version 1.0
*/

#include "send.h"

/*
** @brief it will create a message with 2 string and add a newline
**
** @param value first message
** @param msg second message
** @return our new message or NULL if any error
*/
char	*create_error_msg(char *value, char *msg)
{
  char	*error;

  if (!(error = my_malloc(strlen(value) + strlen(msg) + strlen("\n") + 1)))
    return (NULL);
  error = memset(error, '\0', strlen(value) + strlen(msg) + strlen("\n")+ 1);
  error = strcat(error, value);
  error = strcat(error, msg);
  error[strlen(value) + strlen(msg)] = '\n';
  return (error);
}

/*
** @brief create a list from a string
**
** It will store our string converted in our mwrite_buffer struct with fd
**
** @param server main structure
** @param fd file descriptor
** @return 0 if no error else 1
*/
static int	_split_msg_list(t_server *server, int fd, char *msg)
{
  int		begin;
  int		len;
  char		*tmp;
  int		error;

  begin = 0;
  error = 0;
  len = strlen(msg);
  while (begin < len && error == 0)
    {
      if (!(tmp = strndup(&msg[begin], MAX_MSG)))
	error = 1;
      if (add_element(&(server->write_buffer[fd]), my_strdup(tmp), strlen(tmp)))
	error = 2;
      free(tmp);
      begin += MAX_MSG;
    }
  if (error == 0)
    return (0);
  else if (error == 2)
    free(tmp);
  return (1);
}

/*
** @brief send a basic msg
**
** It will call _split_msg_list and free our message
**
** @param server main structure
** @param fd file descriptor
** @param message our message we will send / free
** @return 0 if no error, else -1
*/
int	send_msg(t_server *server, int fd, char *message)
{
  int	error;

  if (message == NULL)
    return (-1);
  error = _split_msg_list(server, fd, message);
  free(message);
  return (error == 0 ? 0 : -1);
}

/*
** @brief send 2 numbers
**
** Used to send X Y from every client.
** It will call send_msg to send our message generated
**
** @param server our main structure with all informations
** @param fd file descriptor we will send any message
** @param val1 first integer we want to send
** @param val2 second interger we want to send
** @return 0 if no problem, else -1
*/
int	send_nbrs(t_server *server, int fd, int val1, int val2)
{
  char	*msg;
  char	*t1;
  char	*t2;
  char	*tmp;

  t1 = int_to_str(val1);
  t2 = NULL;
  if (val2 != -1 && (t2 = int_to_str(val2)) != NULL)
    {
      tmp = my_malloc(strlen(" ") + strlen(t2) + 1);
      tmp[0] = '\0';
      tmp = strcat(tmp, " ");
      tmp = strcat(tmp, t2);
      msg = create_error_msg(t1, tmp);
      free(tmp);
      free(t2);
    }
  else if (val2 != -1 && t2 == NULL)
    return (-1);
  else
    msg = create_error_msg(t1, "");
  free(t1);
  return (send_msg(server, fd, msg));
}

/*
** @brief main function to send messages
**
** It will check the write_buffer list and send it to fd
** It will free the list after used it
**
** @param s main structure
** @param fd file descriptor
*/
void		write_client(t_server *s, int fd)
{
  t_list	*tmp;
  int		reset;

  reset = 0;
  tmp = s->write_buffer[fd] != NULL ? s->write_buffer[fd]->next : NULL;
  if (reset == 0 && tmp != NULL && tmp != s->write_buffer[fd])
    {
      while (reset == 0 && tmp != NULL && tmp != s->write_buffer[fd])
	{
	  if (my_printf(fd, "%s", tmp->data) == -1)
	    {
	      if (errno == ECONNRESET || errno == EPIPE)
		close_connection(s, fd);
	      errno = 0;
	      reset = 1;
	    }
	  tmp = reset == 0 ? tmp->next : tmp;
	}
      if (!reset)
	{
	  let_it_go(&(s->write_buffer[fd]));
	  s->write_buffer[fd] = create_root();
	}
    }
}
