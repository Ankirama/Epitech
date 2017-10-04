/*
** my_str_isupper.c for my_str_isupper in /home/mar_b/rendu/Piscine-C-Jour_06/ex_13
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 12:49:37 2014 Fabien Martinez
** Last update Mon Mar 10 12:52:07 2014 Fabien Martinez
*/

int     my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while(str[i] != '\0' && str[i] >= 'A' && str[i] <= 'Z')
    {
      i += 1;
    }
  if (str[i] == '\0')
    return (1);
  return (0);
}
