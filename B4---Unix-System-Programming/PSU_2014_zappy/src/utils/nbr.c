/*
** read.c for read in /home/mar_b/rendu/PSU_2014_myirc
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Wed Apr  1 10:18:18 2015 Fabien Martinez
** Last update Sun Jul  5 19:01:13 2015 CHARLES VITERBO
*/

#include "utils.h"

/*
** @file nbr.c
** @brief functions about int
** @author ankirama
** @version 1.0
*/

/*
** @brief get size interger
**
** @param nb number we will get the size
** @return the number's size
*/
int	str_nbr(int nb)
{
  if (nb < 10)
    return (1);
  else
    return (1 + str_nbr(nb / 10));
}

/*
** @brief convert interger to string
**
** @param nb number we will convert to string
** @return the string from our integer
*/
char	*int_to_str(int nb)
{
  char	*s;
  int	i;
  int	size;

  size = str_nbr(nb);
  if ((s = my_malloc(size + 1)) == NULL)
    return (NULL);
  i = -1;
  s[size] = '\0';
  while (nb >= 10)
    {
      s[size - ++i - 1] = (nb % 10) + '0';
      nb /= 10;
    }
  s[size - ++i - 1] = nb + '0';
  return (s);
}

/*
** @brief create random number
**
** It will return a random number in 0, max - 1
**
** @param max our number max
** @return generated number
*/
int		random_number(int max)
{
  static int	seed_ = 0;

  if (seed_ == 0)
    {
      seed_ = 1;
      srand(time(NULL));
    }
  return (rand() % max);
}

/*
** @brief it will restrain a number in an area
**
** Example: value = -8, max = 4
** it will return 4
** Example 2: value = 5, max = 4
** it will return 1
** Useful to convert a position and keep it in our map
**
** @param value our current value we want to restrain / convert
** @param max max value to restrain
** @return the new value
*/
int	restrain_number(int value, int max)
{
  if (value < 0)
    {
      value = CONV_ABS(value);
      while (value > max)
	value -= max;
      value = max - value;
    }
  else
    {
      if (value >= max)
	value %= max;
    }
  return (value);
}

/*
** @brief it will convert a string to an int
**
** @param str our string to convert
** @param error in case of error
**
** @return our value
*/
int	str_to_int(char *str, int *error)
{
  char	*ptr;
  int	res;

  res = strtol(str, &ptr, 10);
  if (errno != 0 || (ptr != NULL && strlen(str) > 0))
    {
      cmd_log(strerror(errno), "str_to_int", xdate(), TYPE_ERROR);
      res = 0;
      *error = 1;
      errno = 0;
    }
  *error = 0;
  return (res);
}
