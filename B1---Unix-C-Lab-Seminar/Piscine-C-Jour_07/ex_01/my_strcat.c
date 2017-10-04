/*
** my_strcat.c for my_strcat in /home/mar_b/rendu/Piscine-C-Jour_07/my
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Mar 11 09:36:43 2014 Fabien Martinez
** Last update Tue Mar 11 10:01:52 2014 Fabien Martinez
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	length;

  length = 0;
  while (dest[length] != '\0')
    {
      length += 1;
    }
  i = 0;
  while (src[i] != '\0')
    {
      dest[length + i] = src[i];
      i += 1;
    }
  dest[length + i] = '\0';
  return (dest);
}
