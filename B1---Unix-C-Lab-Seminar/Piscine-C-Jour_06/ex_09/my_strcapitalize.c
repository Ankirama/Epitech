/*
** my_strcapitalize.c for my_strcapitalize in /home/mar_b/rendu/Piscine-C-Jour_06/ex_09
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 11:42:39 2014 Fabien Martinez
** Last update Mon Mar 10 12:28:38 2014 Fabien Martinez
*/

char	my_alphanumeric(int i, char *str)
{
  if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
    return (1);
  if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
    return (1);
  if (str[i - 1] >= '0' && str[i - 1] <= '9')
    return (1);
  return (0);
}

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  if (str[0] >= 'a' && str[0] <= 'z')
    str[0] -= 32;
  while (*(str + i) != '\0')
    {
      if (my_alphanumeric(i, str))
	{
	  if (*(str + i) >= 'A' && *(str + i) <= 'Z')
	    {
	      my_putchar('\n');
	      *(str + i) += 32;
	    }
	}
      else
	{
	  if (*(str + i) >= 'a' && *(str + i) <= 'z')
	    *(str + i) -= 32;
	}
      i += 1;
    }
  my_putstr(str);
  return (str);
}
