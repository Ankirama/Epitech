/*
** my_strncmp.c for my_strncmp in /home/mar_b/rendu/Piscine-C-Jour_06/ex_06
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 10:41:22 2014 Fabien Martinez
** Last update Tue Mar 11 10:55:52 2014 Fabien Martinez
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 1;
  while (s1[i - 1] != 0 && s2[i - 1] != 0 && s1[i - 1] == s2[i - 1] && i < n)
    {
      i += 1;
    }
  if (s1[i - 1] == s2[i - 1] || (i == n && s1[i - 1] == s2[i - 1]) || n <= 0)
    return (0);
  return (s1[i - 1] - s2[i - 1]);
}
