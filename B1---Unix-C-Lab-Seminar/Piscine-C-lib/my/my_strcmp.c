/*
** my_strcmp.c for strcmp in /home/bourde_g/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by Gauthier Bourdenx
** Login   <bourde_g@epitech.net>
** 
** Started on  Mon Mar 10 20:31:06 2014 Gauthier Bourdenx
** Last update Mon Mar 10 21:53:07 2014 Gauthier Bourdenx
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    i = i + 1;
  if (s1[i] == s2[i])
    return (0);
  if (s1[i] > s2[i])
    return (1);
  else if (s1[i] < s2[i])
    return (-1);
  return (0);
}
