/*
** my_strlowcase.c for strlowcase in /home/bourde_g/rendu/Piscine-C-Jour_06/ex_08
** 
** Made by Gauthier Bourdenx
** Login   <bourde_g@epitech.net>
** 
** Started on  Mon Mar 10 22:03:27 2014 Gauthier Bourdenx
** Last update Mon Mar 24 13:02:46 2014 Gauthier Bourdenx
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	{
	  str[i] = str[i] + 32;
	}
      i = i + 1;
    }
  return (0);
}
