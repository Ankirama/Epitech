/*
** my_strncpy.c for my_strncpy in /home/mar_b/rendu/Piscine-C-Jour_06/ex_02
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 09:28:19 2014 Fabien Martinez
** Last update Mon Mar 10 09:36:26 2014 Fabien Martinez
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
