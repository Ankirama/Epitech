/*
** castmania.c for castmania in /home/mar_b/rendu/piscine_cpp_d02m/ex04
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jan  8 11:46:14 2015 Fabien Martinez
** Last update Thu Jan  8 13:50:42 2015 Fabien Martinez
*/

#include <stdio.h>
#include "castmania.h"

void exec_operation(t_instruction_type instruction_type, void *data)
{
  if (instruction_type == ADD_OPERATION)
    {
      exec_add(((t_instruction *)data)->operation);
      printf("%d\n", ((t_add *)((t_instruction *)data)->operation)->add_op.res);
    }
  else if (instruction_type == DIV_OPERATION)
    {
      exec_div(((t_instruction *)data)->operation);
      if (((t_div *)((t_instruction *)data)->operation)->div_type == INTEGER)
	printf("%d\n", ((t_integer_op *)((t_div *)((t_instruction *)data)->operation)->div_op)->res);
      else
	printf("%f\n", ((t_decimale_op *)((t_div *)((t_instruction *)data)->operation)->div_op)->res);
    }
}

void exec_instruction(t_instruction_type instruction_type, void *data)
{
  if (instruction_type == PRINT_INT)
    printf("%d\n",*((int*)data));
  else if (instruction_type == PRINT_FLOAT)
    printf("%f\n", *((float*)data));
  else
    exec_operation(instruction_type, data);
}
