/*
** my_str_islower.c for my_str_islower in /home/mar_b/rendu/Piscine-C-Jour_06/ex_12
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 12:47:31 2014 Fabien Martinez
** Last update Mon Mar 10 12:48:02 2014 Fabien Martinez
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  while(str[i] != '\0' && str[i] >= 'a' && str[i] <= 'z')
    {
      i += 1;
    }
  if (str[i] == '\0')
    return (1);
  return (0);
}
