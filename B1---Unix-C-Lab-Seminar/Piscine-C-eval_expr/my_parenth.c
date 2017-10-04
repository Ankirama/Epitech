/*
** my_parenth.c for my_parenth in /home/mar_b/rendu/Piscine-C-eval_expr
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Mar 27 20:58:31 2014 Fabien Martinez
** Last update Thu Mar 27 22:42:39 2014 Fabien Martinez
*/

int	anyparent(char *str)
{
  if (str[0] == '(')
    return (1);
  else if (str[0] == 0)
    return (0);
  else
    return (anyparent(&str[1]));
}

int	backparent(char *str)
{
  if (str[0] == 0 || str[0] == ')')
    return (0);
  else
    return (1 + backparent(&str[1]));
}

int	firstparent(char *str, int i)
{
  if (str[i] == '(' || i == 0)
    return (i);
  else
    return (firstparent(str, i - 1));
}
