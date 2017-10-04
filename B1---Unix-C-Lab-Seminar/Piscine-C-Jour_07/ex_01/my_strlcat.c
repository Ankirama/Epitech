/*
** my_strlcat.c for my_strlcat in /home/mar_b/rendu/Piscine-C-Jour_07/my
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Mar 11 10:12:23 2014 Fabien Martinez
** Last update Tue Mar 11 11:37:26 2014 Fabien Martinez
*/

int	my_str_len1(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i += 1;
  return (i);
}

int	my_strlcat(char *dest, char *src, int size)
{
  int	length_dest;
  int	length_src;
  int	i;

  length_dest = my_str_len1(dest);
  length_src = my_str_len1(src);
  if (size <= length_dest - 1)
    {
      return (length_src + size);
    }
  i = 0;
  while (src[i] != '\0' && i < size - length_dest - 1)
    {
      dest[length_dest + i] = src[i];
      i += 1;
    }
  dest[length_dest + i] = '\0';
  return (length_src + length_dest);
}
