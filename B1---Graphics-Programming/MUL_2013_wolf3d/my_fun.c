/*
** my_fun.c for my_fun.c in /home/mar_b/rendu/MUL_2013_wolf3d
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jun 13 15:47:03 2014 mar_b mar_b
** Last update Sun Jun 15 17:53:05 2014 mar_b mar_b
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_error.h"
#include "my_init.h"
#include "wolf3d.h"

/*
** brief: will calculate the numbers of char
** @str: this is the string
** return: will return the number of char
*/
int	my_strlen(const char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (0);
  while (str[++i]);
  return (i);
}

/*
** brief: it will copy each char into the new string
** @str: the string we will copy
** return: return the new string
*/
char	*my_strdup(const char *str)
{
  int	i;
  char	*cpy;

  if ((cpy = malloc(sizeof(char) * my_strlen(str))) == NULL)
    my_puterror("error: problem to malloc!\n");
  i = -1;
  while (str[++i])
    cpy[i] = str[i];
  cpy[i] = '\0';
  return (cpy);
}

/*
** brief: Like ATOI
** @str: we will convert this string to an integer
** return: it will return the new integer
*/
int	my_getnbr(const char *str)
{
  int	i;
  int	nbr;

  i = -1;
  while (str[++i])
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  (void)write(2, "error: '", 8);
	  (void)write(2, &str[i], 1);
	  my_puterror("' is not valid, this world is so bad !\n");
	}
    }
  i = -1;
  nbr = 0;
  while (str[++i] && nbr >= 0)
    nbr = nbr * 10 + (str[i] - '0');
  return (nbr);
}

/*
** brief: this function will set the move struct
** @pr : the struct used to define the move, each ptr like the img etc...
** @map: if map == 1 then we have to find the player's position, 0 = default
*/
void	my_find_pos(t_ptr *pr, char map)
{
  int	i;
  int	j;
  int	found;

  if (map)
    {
      i = -1;
      found = 0;
      while (++i < pr->lab->x && !found)
	{
	  j = -1;
	  while (++j < pr->lab->y && !found)
	    {
	      if (pr->lab->patrn[i][j] == '2')
		{
		  pr->lab->patrn[i][j] = '0';
		  found = 1;
		}
	    }
	}
      if (!found)
	my_puterror("error: unable to find the player!\n");
      my_init_move(pr, i + 0.5, j + 0.5);
    }
}
