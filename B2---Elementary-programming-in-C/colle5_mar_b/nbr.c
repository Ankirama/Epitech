/*
** nbr.c for nbr in /home/mar_b/rendu/colle5_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep 23 20:33:08 2014 mar_b mar_b
** Last update Tue Sep 23 22:02:57 2014 lefebv_1 lefebv_1
*/

int	my_getnbr(const char *str)
{
  int	nbr;
  int	i;

  i = -1;
  nbr = 0;
  while (str[++i] != '\0' && str[i] >= '0' && str[i] <= '9' && nbr >= 0)
    nbr = nbr * 10 + str[i] - '0';
  return (str[i] == '\0' && nbr >= 0 ? nbr : -1);
}
