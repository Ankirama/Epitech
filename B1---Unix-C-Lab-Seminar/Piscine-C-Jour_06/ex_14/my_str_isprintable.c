/*
** my_str_isprintable.c for my_str_isprintable in /home/mar_b/rendu/Piscine-C-Jour_06/ex_14
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 12:54:59 2014 Fabien Martinez
** Last update Mon Mar 10 12:59:19 2014 Fabien Martinez
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] >= ' ' && str[i] <= '~')
    {
      i += 1;
    }
  if (str[i] == '\0')
    return (1);
  return (0);
}
