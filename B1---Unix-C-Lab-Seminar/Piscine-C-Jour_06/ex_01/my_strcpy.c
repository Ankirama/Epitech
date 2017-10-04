/*
** my_strcpy.c for my_strcpy in /home/mar_b/rendu/Piscine-C-Jour_06/ex_01
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 08:59:32 2014 Fabien Martinez
** Last update Mon Mar 10 09:36:46 2014 Fabien Martinez
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
