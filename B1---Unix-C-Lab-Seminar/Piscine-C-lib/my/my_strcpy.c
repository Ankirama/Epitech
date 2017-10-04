/*
** my_strcpy.c for test in /home/bourde_g/rendu/Library/Library
** 
** Made by Gauthier Bourdenx
** Login   <bourde_g@epitech.net>
** 
** Started on  Mon Mar 24 12:05:58 2014 Gauthier Bourdenx
** Last update Mon Mar 24 12:05:59 2014 Gauthier Bourdenx
*/

char	*my_strcpy(char *dest, char *src)
{
  char acm;

  acm = 0;
  while (src[acm] != '\0')
    {
      dest[acm] = src[acm];
      acm = acm + 1;
    }
  return (dest);
}
