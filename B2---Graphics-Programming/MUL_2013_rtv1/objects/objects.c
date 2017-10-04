/*
** objects.c for objects in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jul 17 13:32:06 2014 mar_b mar_b
** Last update Thu Jul 24 18:20:32 2014 mar_b
*/

/*
** brief: use to travel our str in the file (like sphere 42 42 42 100 0xFFFFFF
** @str: our line
** @i: our start position, we change it too
** return : return a position used to find the old position
*/
int	travel_string(const char *str, int *i)
{
  int	j;
  int	start;

  start = *i + 1;
  j = *i;
  while (str[++j] != '\0' && str[j] != ' ');
  *i = j;
  return (start);
}
