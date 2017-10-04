/*
** my_strcpy.c for my_strcpy in /home/user/rendu/Piscine-C-Jour_06/ex_01
**
** Made by 
** Login   
**
** Started on  Mon Mar 10 08:59:32 2014 
** Last update Mon Mar 10 09:36:46 2014 
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i += 1;
    }
  return (dest);
}
