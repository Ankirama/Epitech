/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

/*
** @file conv.c
** @brief functions to conv, useful for check_params.c
** @author ankirama
** @version 1.0
*/

#include "utils.h"

/*
** @brief convert string to unsigned int
**
** It will convert string and check with errno if any error
**
** @param value will store the conversion
** @param str string we will convert
** @return 0 if no problem, else 1
*/
int		conv_to_unint(unsigned int *value, char *str)
{
  long int	tmp;
  char		*error;

  tmp = strtol(str, &error, 10);
  errno = 0;
  if (strlen(error) > 0 || errno != 0 || tmp > UINT_MAX || tmp < 0)
    {
      if (errno != 0)
	cmd_log(strerror(errno), "conv_to_unint", xdate(), TYPE_ERROR);
      else
	cmd_log("overflow or underflow", "conv_to_unint", xdate(), TYPE_ERROR);
      errno = 0;
      return (1);
    }
  errno = 0;
  *value = (unsigned int)tmp;
  return (0);
}

/*
** @brief return nbr elements in array
**
** @param arr our array we want to get the size
** @return the array's size
*/
int	arrlen(char **arr)
{
  int	i;

  i = 0;
  while (arr[i])
    ++i;
  return (i);
}

static int	_remove_graphic_size(char ** argv, int start, int size)
{
  int		i;
  int		real_size;

  i = -1;
  real_size = 0;
  while (++i < size)
    {
      if (strcmp(argv[i + start], GRAPHIC_CLIENT) != 0)
	++real_size;
    }
  return (real_size);
}

/*
** @brief extract a sub array from argv
**
** @param argv every arguments from console
** @param start the start position
** @param size nbr elements
** @return sub array extracted
*/
char	**split_array(char **argv, int start, int size)
{
  int	i;
  char	**arr;
  int	error;

  size = _remove_graphic_size(argv, start, size);
  arr = my_malloc((size + 1) * sizeof(char *));
  if (arr == NULL)
    return (NULL);
  i = 0;
  error = 0;
  while (error == 0 && i < size)
    {
      if (strcmp(argv[i + start], GRAPHIC_CLIENT) != 0 &&
	  (arr[i] = my_strdup(argv[i + start])) == NULL)
	error = 1;
      ++i;
    }
  arr[i] = NULL;
  if (error == 1)
    {
      if (i > 0)
	free_wordtab(arr);
    }
  return (error == 0 ? arr : NULL);
}
