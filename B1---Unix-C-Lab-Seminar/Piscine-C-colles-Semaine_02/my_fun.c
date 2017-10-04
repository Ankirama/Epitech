/*
** my_fun.c for my_fun in /home/mar_b/rendu/Piscine-C-colles-Semaine_02
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat Mar 15 13:44:35 2014 Fabien Martinez
** Last update Sat Mar 15 13:45:32 2014 Fabien Martinez
*/

void    my_putchar(char c)
{
  write(1, &c, 1);
}

int     my_putnbr(int str)
{
  if (str / 10 == 0)
    my_putchar('0' + str);
  else
    {
      my_putnbr(str / 10);
      my_putchar('0' + (str % 10));
    }
}

int     my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i += 1;
    }
}

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      i += 1;
    }
  return (i);
}
