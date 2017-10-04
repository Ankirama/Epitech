/*
** my_strlen.c for test in /home/bourde_g/rendu/Library/Library
** 
** Made by Gauthier Bourdenx
** Login   <bourde_g@epitech.net>
** 
** Started on  Mon Mar 24 12:06:09 2014 Gauthier Bourdenx
** Last update Mon Mar 24 12:06:10 2014 Gauthier Bourdenx
*/

int	my_strlen(char *str)
{
  int	n;

  n = 0;
  while (*str != '\0')
    {
      n = n + 1;
      str = str + 1;
    }
  return (n);
}
