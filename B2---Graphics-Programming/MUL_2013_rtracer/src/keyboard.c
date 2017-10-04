/*
** keyboard.c for  in /home/viterb_c/rendu/MUL_2013_rtracer/src/keyboard
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Fri Oct  3 18:42:44 2014 charles viterbo
** Last update Sat Oct 11 15:56:49 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "rtracer.h"
#include "mlx.h"
#include "utils.h"

/*
** brief: it will check every key and do something for escape key (exit + free)
** key_code: our key_code
** return : return 0
*/
int	gere_keyboard(int key_code, t_window *pr)
{
  if (key_code == ESC)
    {
      let_it_go(pr);
      exit(0);
    }
  return (0);
}
