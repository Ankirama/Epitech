/*
** my_error.h for my_error.h in /home/user/rendu/PSU_2013_minishell1
**
** Made by 
** Login   
**
** Started on  Mon Jun 16 03:11:28 2014 
** Last update Sat Jun 21 12:51:18 2014 
*/

#ifndef MY_ERROR_H_
# define MY_ERROR_H_

void	my_puterror(const char *error);
void	my_error(const char *error, const char *var);
char	my_env_error(char *env, char type, int pos);
char	my_cnf(char *cmd);

#endif /* !MY_ERROR_H_ */
