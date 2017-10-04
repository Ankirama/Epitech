/*
** my_revstr.c for test in /home/bourde_g/rendu/Library/Library
** 
** Made by Gauthier Bourdenx
** Login   <bourde_g@epitech.net>
** 
** Started on  Mon Mar 24 12:05:02 2014 Gauthier Bourdenx
** Last update Mon Mar 24 12:05:03 2014 Gauthier Bourdenx
*/

char	*my_revstr(char *str)
{
  char	tmp;
  char	nb;
  char	icm;
  
  icm = 0;
  nb = 0;
  while (str[nb] != '\0')
      nb = nb + 1;
  nb = nb - 1;
  while (nb > icm)
    {
      tmp = str[nb];
      str[nb] = str[icm];
      str[icm] = tmp;
      nb = nb - 1;
      icm = icm + 1;
    }
  return (str);
}
