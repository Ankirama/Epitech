/*
** vm_main.c for  in /home/viterb_c/rendu/CPE_2014_corewar/corewar
** 
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
** 
** Started on  Mon Aug 25 11:17:35 2014 charles viterbo
** Last update Sun Aug 31 23:26:40 2014 chenev_d chenev_d
*/

#include "op.h"
#include "parser.h"
#include "vm.h"
#include <sys/types.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
  unsigned char	*vm_memory;
  t_list	*root;

  vm_memory = init_memory();
  root = parser_option(argc, argv, vm_memory);
  if (root->root > 1)
    main_cycle(root, vm_memory, 1);
  else
    main_cycle(root, vm_memory, 0);
  if (root->nb_tour != -1)
    print_memory(vm_memory);
  free(vm_memory);
  return (0);
}
