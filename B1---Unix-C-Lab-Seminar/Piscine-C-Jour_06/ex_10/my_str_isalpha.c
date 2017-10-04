/*
** my_str_isalpha.c for my_str_isalpha in /home/user/rendu/Piscine-C-Jour_06/ex_10
**
** Made by 
** Login   
**
** Started on  Mon Mar 10 12:32:09 2014 
** Last update Mon Mar 10 12:36:37 2014 
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	{
	  i += 1;
	}
      else if (str[i] >= 'a' && str[i] <= 'z')
	{
	  i += 1;
	}
      else
	return (0);
    }
  return (1);
}
