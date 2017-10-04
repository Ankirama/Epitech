/*
** my_strncpy.c for my_strncpy in /home/user/rendu/Piscine-C-Jour_06/ex_02
**
** Made by 
** Login   
**
** Started on  Mon Mar 10 09:28:19 2014 
** Last update Mon Mar 10 09:36:26 2014 
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (*(src + i) != '\0' && i < n)
    {
      *(dest + i) = *(src + i);
      i += 1;
    }
  while (i < n)
    {
      *(dest + i) = '\0';
    }
  return (dest);
}
