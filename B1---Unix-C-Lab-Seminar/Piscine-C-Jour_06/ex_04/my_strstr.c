/*
** my_strstr.c for my_strstr in /home/mar_b/rendu/Piscine-C-Jour_06/ex_04
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 10:00:29 2014 Fabien Martinez
** Last update Mon Mar 10 10:40:25 2014 Fabien Martinez
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  int	start;
  char	*dest;

  i = 0;
  while (*(str + i) != '\0')
    {
      if (to_find[0] == str[i])
	{
	  start = i;
	  j = 0;
	  while (to_find[j] != '\0' && str[i] != '\0' && to_find[j] == str[i])
	    {
	      i += 1;
	      j += 1;
	    }
	  if (*(to_find + j) == '\0')
	    {
	      dest = &(*(str + start));
	      return (dest);
	    }
	  i = start;
	}
      i += 1;
    }
  return ('\0');
}
