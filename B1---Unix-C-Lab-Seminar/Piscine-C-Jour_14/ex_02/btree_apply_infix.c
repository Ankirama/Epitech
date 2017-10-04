/*
** btree_apply_infix.c for day 14 in /home/user/rendu/Piscine-C-Jour_14/ex_02
**
** Made by 
** Login   
**
** Started on  Thu Mar 27 12:08:43 2014 
** Last update Thu Mar 27 12:17:45 2014 
*/

#include <stdlib.h>
#include "tree.h"

void	btree_apply_infix(t_btree *root, int (*applyf)(void *))
{
  if (root != NULL)
    {
      btree_apply_infix(root->left, applyf);
      applyf(root->item);
      btree_apply_infix(root->right, applyf);
    }
}
