/*
** expose.c for  in /home/viterb_c/rendu/MUL_2013_rtracer/src
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Sat Oct  4 11:34:34 2014 charles viterbo
** Last update Sun Oct 12 16:32:27 2014 mar_b mar_b
*/

#include "rtracer.h"
#include "mlx.h"

/*
** brief : it will display our picture into the screen
** @ptr : our struct
*/
int	gere_expose(t_window *ptr)
{
  mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->loading, 0, 0);
  mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
  return (0);
}
