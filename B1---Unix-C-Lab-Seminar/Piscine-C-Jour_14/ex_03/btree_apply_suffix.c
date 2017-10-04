/*
** btree_apply_suffix.c for day14 in /home/mar_b/rendu/Piscine-C-Jour_14/ex_03
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Mar 27 12:22:04 2014 Fabien Martinez
** Last update Thu Mar 27 12:23:47 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "tree.h"

void	btree_apply_suffix(t_btree *root, int (*applyf)(void *))
{
  if (root != NULL)
    {
      btree_apply_suffix(root->left, applyf);
      btree_apply_suffix(root->right, applyf);
      applyf(root->item);
    }
}
