/*
** btree_insert_data.c for data in /home/mar_b/rendu/Piscine-C-Jour_14/ex_04
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Mar 27 12:26:22 2014 Fabien Martinez
** Last update Thu Mar 27 12:49:34 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "tree.h"

t_btree		*my_rec_btree_insert(t_btree *root, void *item,
			     int (*cmpf)(void *, void *))
{
  t_btree	*tmp;

  if (root == NULL)
    {
      root == btree_create_node(item);
      return (root);
    }
  else
    {
      if (cmpf(item, root->item) < 0)
	root->left = my_rec_btree_insert(root->left, item, cmpf);
      else if (cmpf(item, root->item) > 0)
	root->right = my_rec_btree_insert(root->right, item, cmpf);
      else
	{
	  tmp = btree_create_node(item);
	  tmp->right = root->right;
	  (root->right)->tmp;
	  return (root);
	}
    }
}

  void		btree_insert_data(t_btree **root, void *item,
			  int (*cmpf)(void *, void *))
  {
    btree	*tmp;

    if (root == NULL)
      {
	root = malloc(*(*root));
	(*root) = btree_create_node(item);
      }
    else
      {
	tmp = my_rec_btree_insert(&root, item, cmpf);
	(*root) = tmp;
      }
  }
