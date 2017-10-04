/*
** my_check_arg.c for my_check_arg in /home/lefebv_1/rendu/colle1
**
** Made by lefebv_1 lefebv_1
** Login   <lefebv_1@epitech.net>
**
** Started on  Tue Aug 26 22:25:14 2014 lefebv_1 lefebv_1
** Last update Tue Aug 26 22:10:53 2014 mar_b mar_b
*/

static char	my_check_carac(const char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '#' && str[i] != '@')
	return (1);
      i = i + 1;
    }
  return (0);
}

static char	my_check_s1(const char *s1, const char *s2)
{
  int		i;

  i = 0;
  while (s1[i] != '\0')
    {
      while (s1[i] != '@' && s1[i] != '\0')
	i = i + 1;
      if (s1[i] != '\0')
	{
	  if (s2[i] != s1[i])
	    {
	      return (1);
	    }
	  i = i + 1;
	}
    }
  return (0);
}

static char	my_check_s2(const char *s1, const char *s2)
{
  int		i;

  i = 0;
  while (s2[i] != '\0')
    {
      while (s2[i] != '@' && s2[i] != '\0')
	i = i + 1;
      if (s2[i] != '\0')
	{
	  if (s1[i] != s2[i])
	    return (1);
	  i = i + 1;
	}
    }
  return (0);
}

char	my_check_arg(const char *s1, const char *s2)
{
  if (my_check_carac(s1) == 1)
    return (1);
  else if (my_check_carac(s2) == 1)
    return (2);
  else if (my_strlen(s1) != my_strlen(s2)
	   || my_check_s1(s1, s2) == 1
	   || my_check_s2(s1, s2) == 1)
    return (3);
  return (0);
}
