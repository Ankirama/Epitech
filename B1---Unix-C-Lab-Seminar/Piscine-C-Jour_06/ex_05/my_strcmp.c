/*
** my_strcmp.c for my_strcmp in /home/mar_b/rendu/Piscine-C-Jour_06/ex_05
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 10:41:22 2014 Fabien Martinez
** Last update Tue Mar 11 10:56:05 2014 Fabien Martinez
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    {
      i += 1;
    }
  return (s1[i] - s2[i]);
}
