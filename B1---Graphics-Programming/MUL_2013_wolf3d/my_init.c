/*
** my_init.c for my_init in /home/mar_b/rendu/MUL_2013_wolf3d
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jun 11 16:01:13 2014 mar_b mar_b
** Last update Sun Jun 15 16:22:58 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_error.h"
#include "wolf3d.h"
#include "my_init.h"
#include "my_pret.h"
#include "get_next_line.h"
#include "my_fun.h"

/*
** brief: this function will create a new vector (0, 0)
** return: it will return our new vector
*/
t_vector	*my_init_pos()
{
  t_vector	*pos;

  if ((pos = malloc(sizeof(*pos))) == NULL)
    my_puterror("error: problem to malloc!\n");
  pos->x = 0;
  pos->y = 0;
  return (pos);
}

/*
** brief: this function will fill our move struct
** @param: the struct used to define the move, each ptr like the img etc...
** @x: it's player's xPosition
** @y: it's player's yPosition
*/
void	my_init_move(t_ptr *param, float x, float y)
{
  param->move->pos = my_init_pos();
  param->move->pos->x = x;
  param->move->pos->y = y;
  param->move->id_ang = 5;
  param->move->range_k = 0;
  my_calc_angles(param->move->sin_ang, param->move->cos_ang);
}

/*
** brief: it will create our labyrinth
** @ptr: the struct used to define the move, each ptr like the img etc...
** @array[15][15]: this is our labyrinth
*/
static void	_my_init_lab(t_ptr *ptr, char array[15][15])
{
  int		i;
  int		j;

  if ((ptr->lab = malloc(sizeof(*(ptr->lab)))) == NULL)
    my_puterror("error: problem to malloc!\n");
  if ((ptr->lab->patrn = malloc(sizeof(char *) * 15)) == NULL)
    my_puterror("error: problem to malloc!\n");
  i = -1;
  while (++i < 15)
    {
      j = -1;
      if ((ptr->lab->patrn[i] = malloc(sizeof(char) * 15)) == NULL)
	my_puterror("error: problem to malloc!\n");
      while (++j < 15)
	ptr->lab->patrn[i][j] = array[i][j];
    }
  ptr->lab->x = 15;
  ptr->lab->y = 15;
  my_init_move(ptr, 5.4, 4.5);
}

/*
** brief: this function contains our labyrinth and will call my_inut_lab
** @ptr: the struct used to define the move, each ptr like the img etc...
*/
static void	_my_array(t_ptr *ptr)
{
  char		array[15][15] = {
    {"111111111111111"},
    {"100000000000001"},
    {"100000000000001"},
    {"100000000000001"},
    {"100111111111101"},
    {"100000010000101"},
    {"101100010000101"},
    {"100100010000101"},
    {"100111111001101"},
    {"100100010001001"},
    {"100100010000001"},
    {"100100010000001"},
    {"100100011111001"},
    {"100000000000001"},
    {"111111111111111"}
  };

  _my_init_lab(ptr, array);
}

/*
** brief: this function will create our maze and move struct
** @ptr: the struct used to define the move, each ptr like the img etc...
** @fd: file descriptor, used to load our maze2
** BRIEF: this function will, if fd = -1 call our my_array function to create
** our maze or will use get_next_line to create our maze with a file.
** after the creation, we will set our move struct with find_pos
*/
void	my_load_conf(t_ptr *ptr, int fd)
{
  char	*s;
  int	i;
  int	j;

  if (fd == -1)
    _my_array(ptr);
  else
    {
      if ((s = get_next_line(fd)) == NULL || ((j = my_getnbr(s)) < 0) ||
	  (ptr->lab = malloc(sizeof(*(ptr->lab)))) == NULL ||
	  (ptr->lab->patrn = malloc(sizeof(char *) * j)) == NULL)
	my_puterror("error: problem to malloc!\n");
      i = -1;
      while ((s = get_next_line(fd)) != NULL)
	{
	  ptr->lab->patrn[++i] = my_strdup(s);
	  free(s);
	}
      ptr->lab->x = my_strlen(ptr->lab->patrn[0]);
      ptr->lab->y = j;
      if (close(fd) == -1)
	my_puterror("problem to close the map!\n");
    }
  my_find_pos(ptr, fd != -1);
}
