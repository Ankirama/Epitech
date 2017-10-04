/*
** my_evil_str.c for my_evil_str in /home/mar_b/rendu/Piscine-C-Jour_04
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Thu Mar  6 10:09:22 2014 Fabien Martinez
** Last update Thu Mar  6 10:39:27 2014 Fabien Martinez
*/

char	*my_evil_str(char *str)
{
  int	length;
  int	i;
  char	tmp;
  char	*reverse;
  
  reverse = str;
  length = my_strlen(str);
  i = 0;
  while (i <= (length / 2 - 1))
    {
      tmp = *(reverse + i);
      *(reverse + i) = *(reverse + length - i - 1);
      *(reverse + length - i - 1) = tmp;
      i = i + 1;
    }
  return (reverse);
}
