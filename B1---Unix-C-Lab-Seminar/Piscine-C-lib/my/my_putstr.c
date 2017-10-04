/*
** my_putstr.c for test in /home/bourde_g/rendu/Library/Library
**
** Made by Gauthier Bourdenx
** Login   
**
** Started on  Mon Mar 24 12:04:19 2014 Gauthier Bourdenx
** Last update Sat Mar 29 18:10:23 2014 
*/

void	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}
