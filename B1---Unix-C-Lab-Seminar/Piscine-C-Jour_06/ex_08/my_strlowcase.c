/*
** my_strlowcase.c for my_strlowcase in /home/user/rendu/Piscine-C-Jour_06/ex_08cd
**
** Made by 
** Login   
**
** Started on  Mon Mar 10 11:04:10 2014 
** Last update Mon Mar 10 11:42:08 2014 
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
    {
      if (*(str + i) >= 'A' && *(str + i) <= 'Z')
	  *(str + i) += 32;
      i += 1;
    }
  return (str);
}
