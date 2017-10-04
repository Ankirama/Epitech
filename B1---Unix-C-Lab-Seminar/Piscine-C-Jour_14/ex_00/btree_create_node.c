/*
** btree_create_node.c for day14 in /home/mar_b/rendu/Piscine-C-Jour_14/ex_00
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Mar 27 11:53:20 2014 Fabien Martinez
** Last update Thu Mar 27 12:04:26 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "tree.h"

t_btree		*btree_create_node(void *item)
{
  t_btree	*node;

  node = malloc(sizeof(*node));
  node->item = item;
  node->left = NULL;
  node->right = NULL;
  return (node);
}
