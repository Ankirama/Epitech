/*
** main.c for main in /home/ankirama
**
** Made by 
** Login   <>
**
** Started on  Thu Feb 19 21:38:01 2015 
** Last update Wed Apr  1 11:40:32 2015 
*/

#ifndef INTERPRET_MESSAGE_H_
# define INTERPRET_MESSAGE_H_

# include "server.h"
# include "send.h"
# include "actions.h"
# include "team.h"
# include "welcome.h"

/*
** interpret_message.c
*/
int	interpret_message(t_server *server, int fd);

#endif /* !INTERPRET_MESSAGE_H_ */
