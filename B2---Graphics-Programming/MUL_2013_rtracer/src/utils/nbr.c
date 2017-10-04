/*
** nbr.c for nbr in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Oct  9 14:16:03 2014 mar_b mar_b
** Last update Sat Oct 11 18:50:07 2014 chenev_d chenev_d
*/

#include "mlx.h"
#include "utils.h"

/*
** brief: write one character on display
** @c: the charater
*/
static void	my_putchar(char c)
{
  my_write(1, &c, 1);
}

/*
** brief: to display the progression of the calcul
** @i: it's a percentage
*/
void	display_progession(char i)
{
  if (i <= 30)
    my_write(1, DEB_PRO, my_strlen(DEB_PRO));
  else if (i <= 70)
    my_write(1, MID_PRO, my_strlen(MID_PRO));
  else
    my_write(1, END_PRO, my_strlen(END_PRO));
  put_nbr(i);
  my_write(1, RESET_PRO, my_strlen(RESET_PRO));
}

/*
** brief: to put a nomber on display
** @i: the number to display
*/
void	put_nbr(unsigned int i)
{
  if (i < 10)
    my_putchar(i + '0');
  else
    {
      put_nbr(i / 10);
      my_putchar(i % 10 + '0');
    }
}
