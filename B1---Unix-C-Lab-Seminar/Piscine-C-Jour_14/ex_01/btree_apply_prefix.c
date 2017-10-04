/*
** btree_apply_prefix.c for day14 in /home/mar_b/rendu/Piscine-C-Jour_14/ex_01
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Mar 27 11:58:42 2014 Fabien Martinez
** Last update Thu Mar 27 12:07:59 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "tree.h"

void	btree_apply_prefix(t_btree *root, int (*applyf)(void *))
{
  if (root != NULL)
    {
      applyf(root->item);
      btree_apply_prefix(root->left, applyf);
      btree_apply_prefix(root->right, applyf);
    }
}
