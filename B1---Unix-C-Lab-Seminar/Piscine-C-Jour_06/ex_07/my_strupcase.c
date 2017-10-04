/*
** my_strupcase.c for my_strupcase in /home/mar_b/rendu/Piscine-C-Jour_06/ex_07
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 11:04:10 2014 Fabien Martinez
** Last update Mon Mar 10 11:41:55 2014 Fabien Martinez
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
    {
      if (*(str + i) >= 'a' && *(str + i) <= 'z')
	  *(str + i) -= 32;
      i += 1;
    }
  return (str);
}
