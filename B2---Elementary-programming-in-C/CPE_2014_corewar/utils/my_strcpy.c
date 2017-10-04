/*
** my_strcpy.c for strcpy in /home/teyssa_r/rendu/Piscine-C-Jour_06/ex_01
** 
** Made by Raphael TEYSSANDIER
** Login   <teyssa_r@epitech.net>
** 
** Started on  Mon Mar 10 08:59:47 2014 Raphael TEYSSANDIER
** Last update Mon Mar 10 09:15:56 2014 Raphael TEYSSANDIER
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  i = i + 1;
  dest[i] = '\0';
  return (dest);
}
