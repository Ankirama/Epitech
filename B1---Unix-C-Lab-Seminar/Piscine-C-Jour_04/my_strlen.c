/*
** my_strlen.c for my_strlen in /home/mar_b/rendu/Piscine-C-Jour_04
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Thu Mar  6 10:04:43 2014 Fabien Martinez
** Last update Thu Mar  6 10:08:22 2014 Fabien Martinez
*/

int	my_strlen(char *str)
{
  int	n;

  n = 0;
  while (*(str + n) != '\0')
    {
      n += 1;
    }
  return (n);
}
