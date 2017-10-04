/*
** my_str_isnum.c for my_str_isnum in /home/user/rendu/Piscine-C-Jour_06/ex_11
**
** Made by 
** Login   
**
** Started on  Mon Mar 10 12:39:51 2014 
** Last update Mon Mar 10 12:42:49 2014 
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while(str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
      i += 1;
    }
  if (str[i] == '\0')
    return (1);
  return (0);
}
