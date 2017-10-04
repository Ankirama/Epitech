/*
** my_verbose.c for my_verbose in /home/user/rendu/CPE_2013_Pushswap
**
** Made by 
** Login   
**
** Started on  Fri Jun  6 17:44:20 2014 
** Last update Sun Jun  8 20:03:51 2014 
*/

#include <unistd.h>
#include "my_list.h"

char	my_verbose(t_list *l_a, t_list *l_b)
{
  (void)write(1, "\n\n", 2);
  (void)write(1, "liste A : ", 10);
  my_display_list(l_a);
  (void)write(1, "\n----------\n", 12);
  (void)write(1, "liste B : ", 10);
  my_display_list(l_b);
  (void)write(1, "\n__________\n", 12);
  return (1);
}
