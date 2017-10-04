/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sat Feb 21 22:09:24 2015 Fabien Martinez
*/

#ifndef CLIENT_H_
# define CLIENT_H_

int	my_get(char **arr, int s, int fd, char *size_buf);
void	usage(int argc);
void	sig_handler(int sig);
void	check_signal(int socket);
int	user(int socket, char **arr, char *user, char *pwd);

#endif /* !CLIENT_H_ */
