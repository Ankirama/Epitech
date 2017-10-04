/*
** my_str_isupper.c for my_str_isupper in /home/user/rendu/Piscine-C-Jour_06/ex_13
**
** Made by 
** Login   
**
** Started on  Mon Mar 10 12:49:37 2014 
** Last update Mon Mar 10 12:52:07 2014 
*/

int     my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while(str[i] != '\0' && str[i] >= 'A' && str[i] <= 'Z')
    {
      i += 1;
    }
  if (str[i] == '\0')
    return (1);
  return (0);
}
