/*
** my_strncat.c for my_stsrncat in /home/user/rendu/Piscine-C-Jour_07/my
**
** Made by 
** Login   
**
** Started on  Tue Mar 11 09:51:40 2014 
** Last update Tue Mar 11 10:11:23 2014 
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	length;

  length = 0;
  while (dest[length] != '\0')
    {
      length += 1;
    }
  i = 0;
  while (src[i] != '\0' && i < nb)
    {
      dest[length + i] = src[i];
      i += 1;
    }
  dest[length + i] = '\0';
  return (dest);
}
