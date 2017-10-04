/*
** my_echo.c for 42sh in /home/zighed_a/rendu/PSU_2013_42sh/src/builtin
** 
** Made by zighed_a zighed_a
** Login   <zighed_a@epitech.net>
** 
** Started on  Fri Sep 19 17:15:52 2014 zighed_a zighed_a
** Last update Thu Oct  2 23:06:20 2014 zighed_a zighed_a
*/

#include <unistd.h>
#include <stdlib.h>
/* #include "list.h" */
/* #include "utils.h" */
/* #include "builtin.h" */

static const char	tabchoice[][2] =
{
  {'a', '\a'},
  {'b', '\b'},
  {'t', '\t'},
  {'n', '\n'},
  {'v', '\v'},
  {'f', '\f'},
  {'r', '\r'},
};

int	my_putchar(char c)
{
  write(0, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while(str && str[i] != '\0')
    i = i + 1;
  return (i);
}

int	my_pos(char c, char *base)
{
  int	j;

  j = 0;
  while (c != base[j])
    j++;
  return (j);
}

int     my_getnbr_base(char *str, char *base, int j, int limit)
{
  int   sign;
  int   result;

  sign = 1;
  result = 0;
  if (str[j + 1] != '\0' && str[j + 2] != '\0')
    j += 2;
  while (limit > 0)
    {
      while ((str[j] >= '0' && str[j] <= '9') || (str[j] >= 'a' && str[j] <= 'z'))
	{
	  result = (result * my_strlen(base)) + my_pos(str[j], base);
	  if (result < 0)
	    return (0);
	  j++;
	}
      limit--;
    }
  return (my_putchar((char)(result)));
}

char	my_strcmp(const char *s1, const char *s2, const char equal)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    ++i;
  if (equal == 1)
    return (s1[i] == '=' && s2[i] == '\0');
  else
    return ((s1[i] == s2[i] || s1[i] == ' ' || s1[i] == '\t') && s2[i] == '\0');
}

void	my_choice(char **arr, int i, int *j)
{
  int	choice;

  choice = 0;
  while (tabchoice[choice][0])
    {
      if (tabchoice[choice][0] == arr[i][*j + 1])
	{
      	(void)write(0, &tabchoice[choice][1], 1);
	*j +=1;
	return ;
	}
      choice++;
    }
  if (choice > 7 && arr[i][*j + 1] == 'x')
    {
      my_getnbr_base(arr[i], "0123456789abcdef", *j, 2);
      *j += 2;
    }
  if (choice > 7 && arr[i][*j + 1] == '0')
    {
      my_getnbr_base(arr[i], "012345678", *j, 3);
      *j += 3;
    }
}

void	my_echo_cap_e(char **arr, int n, int i)
{
  int	j;

  j = 0;
  while (arr && arr[i][j] != '\0')
    {
      (void)write(0, &arr[i][j], 1);
      j++;
    }
  if (n == 0)
    (void)write(0, "\n", 1);
}

void	my_echo_e(char **arr, int n, int i)
{
  int	j;

  j = 0;
  while (arr && arr[i][j] != '\0')
    {
      if (arr[i][j] == '\\')
	{
	  my_choice(arr, i, &j);
	  j += 2;
	}
      (void)write(0, &arr[i][j], 1);
      if (arr[i][j])
	j++;
    }
  if (n == 0)
      write(0, "\n", 1);
}


char	*my_built_opt(char **arr, int i, char *opt)
{
  int	y;

  y = 1;
  while (arr && arr[i][y] != '\0')
    {
      if (arr[i][y] == 'E')
	opt[0] = '0';
      if (arr[i][y] == 'e')
	opt[0] = '1';
      if (arr[i][y] == 'n')
	opt[1] = '1';
      if (arr[i][y] != 'n' && arr[i][y] != 'e' && arr[i][y] != 'E')
	my_echo_cap_e(arr, 0, i);
      y++;
    }
  return (opt);
}

void 	my_check_opt(char **arr, int i, char *opt)
{
  if ((my_strcmp(opt, "01", 0)) == 1)
    my_echo_cap_e(arr, 1, i);
  else if ((my_strcmp(opt, "10", 0)) == 1)
    my_echo_e(arr, 0, i);
  else if ((my_strcmp(opt, "11", 0)) == 1)
    my_echo_e(arr, 1, i);
  else if ((my_strcmp(opt, "00", 0)) == 1)
    my_echo_cap_e(arr, 0, i);
}

void	my_echo(char **arr)
{
  int	i;
  char	opt[3];

  i = 1;
  opt[0] = '0';
  opt[1] = '0';
  opt[2] = '\0';
  if (arr[i] == NULL)
    {
      write(0, "\n", 1);
      return ;
    }
  while (arr[i][0] == '-')
    {
      my_built_opt(arr, i, opt);
      i++;
    }
  my_check_opt(arr, i, opt);
}

int	main(int argc, char **argv)
{
  my_echo(argv);
}
