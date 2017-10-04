/*
** str.c for str in /home/mar_b/rendu/colle3_bob42
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep  9 22:12:18 2014 mar_b mar_b
** Last update Tue Sep  9 22:34:00 2014 mar_b mar_b
*/

#include "calc.h"
#include "utils.h"

char	*my_new_str(char *str, int rslt, int start, int end)
{
  char	*new_str;
  char	*rslt_char;

  rslt_char = my_put_in_str(rslt);
  new_str = my_malloc(start + my_strlen(rslt_char)
		      + my_strlen(&str[end + 1] + 1));
  new_str[0] = '\0';
  new_str = my_strncat(new_str, str, start);
  new_str = my_strncat(new_str, rslt_char, my_strlen(rslt_char));
  new_str = my_strncat(new_str, &str[end + 1], my_strlen(&str[end + 1]));
  return (new_str);
}

char	*convert_minus(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == ID_SUB && (i == 0 || str[i - 1] == ID_MULT ||
			       str[i - 1] == ID_ADD || str[i - 1] == ID_SUB ||
			       str[i - 1] == ID_MOD || str[i - 1] == ID_DIV))
	str[i] = '_';
    }
  return (str);
}
