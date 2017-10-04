/*
** my_revstr.c for my_revstr in /home/mar_b/rendu/Piscine-C-Jour_06/ex_03
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 09:40:30 2014 Fabien Martinez
** Last update Mon Mar 10 22:04:34 2014 Fabien Martinez
*/

char	*my_revstr(char *str)
{
  int	i;
  int	count;
  char	c;

  while (*(str + i) != '\0')
    {
      i += 1;
    }
  count = i;
  i = 0;
  while (i < count / 2)
    {
      c = *(str + i);
      *(str + i) = *(str + count - i - 1);
      *(str + count - i - 1) = c;
      i += 1;
    }
  return (str);
}
