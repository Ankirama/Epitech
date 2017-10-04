/*
** ptr_tricks.c for ptr_tricks in /home/mar_b/rendu/piscine_cpp_d02m/ex05
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jan  8 13:53:54 2015 Fabien Martinez
** Last update Thu Jan  8 15:50:55 2015 Fabien Martinez
*/

#include <stdio.h>
#include "ptr_tricks.h"

int	get_array_nb_elem(int *ptr1, int *ptr2)
{
  return (ptr2 - ptr1 < 0 ? ptr1 - ptr2 : ptr2 - ptr1);
}

t_whatever	*get_struct_ptr(int *member_ptr)
{
  t_whatever	ptr;
  t_whatever	*rslt;
  long		addr_member;
  long		addr_strct;
  long		dist;

  addr_member = (long)&(ptr.member);
  addr_strct = (long)&ptr;
  dist = addr_member - addr_strct;
  rslt = (t_whatever*)((long)member_ptr - dist);
  return (rslt);
}
