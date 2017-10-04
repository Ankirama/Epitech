/*
** fun.c for fun in /home/mar_b/rendu/PSU_2013_42sh
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Sep  5 00:20:26 2014 mar_b mar_b
** Last update Thu Oct  2 21:02:59 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "lexer.h"
#include "utils.h"

char	strcmp_lexer(const char *s1, const char *s2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (s1[i] != '\0' && s2[j] != '\0')
    {
      if (s1[i] == '\\')
	{
	  if (s1[i + 1] == '\0')
	    return (2);
	  i += 2;
	}
      if (s1[i] != s2[j])
	return (0);
      i = s1[i] == '\0' ? i : i + 1;
      ++j;
    }
  return (s2[j] == '\0');
}

int		check_opt(char *str, char **g_opt)
{
  int		i;

  i = 0;
  while (i < NBR_OPT && !strcmp_lexer(str, g_opt[i]))
    ++i;
  return (i);
}

char		**_my_arrcat(char **arr1, char **arr2)
{
  int		i;
  int		j;
  char		**arr;

  if (!(arr = malloc(sizeof(char *) * (my_arrlen(arr1) + my_arrlen(arr2) + 1))))
    my_puterror_null(ERR_MALLOC);
  i = -1;
  while (arr2[++i] != NULL)
    arr[i] = arr2[i];
  j = -1;
  while (arr1[++j] != NULL)
    {
      arr[i] = arr1[j];
      ++i;
    }
  arr[++i] = NULL;
  free_arr(arr2);
  arr2 = arr;
  return (arr);
}

/*
** brief: display an array
** @arr: char **
*/
void	display_arr(char **arr)
{
  int	i;

  if (arr != NULL)
    {
      i = -1;
      while (arr[++i] != NULL)
	{
	  (void)write(1, arr[i], my_strlen(arr[i]));
	  if (arr[i + 1] != NULL)
	    (void)write(1, " ", 1);
	}
      (void)write(1, "\n", 1);
    }
}

/*
** brief: it will display our ast (prefix travel)
** @ast: our ast
*/
void	travel_ast(t_ast *ast)
{
  if (ast != NULL)
    {
      (void)write(1, "noeud : ", my_strlen("noeud : "));
      display_arr(ast->array);
      (void)write(1, "fils gauche : \n", my_strlen("fils gauche : \n"));
      travel_ast(ast->left);
      (void)write(1, "fils droit : \n", my_strlen("fils droit : \n"));
      travel_ast(ast->right);
    }
  else
    (void)write(1, "NULL\n", 5);
}
