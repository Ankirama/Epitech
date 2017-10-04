/*
** simple_btree.c for btree in /home/mar_b/rendu/piscine_cpp_d02a/ex01
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jan  8 18:01:09 2015 Fabien Martinez
** Last update Thu Jan  8 20:08:37 2015 Fabien Martinez
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "simple_btree.h"

t_bool btree_is_empty(t_tree tree)
{
  return (tree == NULL ? TRUE : FALSE);
}

unsigned int btree_get_size(t_tree tree)
{
  if (tree == NULL)
    return (0);
  else
    {
      if (tree->left == NULL && tree->right == NULL)
	return (1);
      else
	return (1 + (btree_get_size(tree->left)) + (btree_get_size(tree->right)));
    }
}

unsigned int btree_get_depth(t_tree tree)
{
  int	left;
  int	right;
  int	depht;

  if (tree == NULL)
    return (0);
  left = btree_get_depth(tree->left);
  right = btree_get_depth(tree->right);
  depht = left > right ? left + 1 : right + 1;
  return (depht);
}

t_bool btree_create_node(t_tree *node_ptr, double value)
{
  t_tree node;

  if ((node = malloc(sizeof(node))) == NULL)
    return (FALSE);
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  *node_ptr = node;
  return (TRUE);
}

t_bool btree_delete(t_tree *root_ptr)
{
  if (*root_ptr == NULL)
    return (FALSE);
  btree_delete(&(*root_ptr)->left);
  btree_delete(&(*root_ptr)->right);
  free((*root_ptr)->left);
  free((*root_ptr)->right);
  return (TRUE);
}

double btree_get_max_value(t_tree tree)
{
  double	left_val;
  double	right_val;
  double	max;

  if (tree == NULL)
    return (0);
  max = tree->value;
  if (tree->left)
    {
      left_val = btree_get_max_value(tree->left);
      max = max > left_val ? max : left_val;
    }
  if (tree->right)
    {
      right_val = btree_get_max_value(tree->right);
      max = max > right_val ? max : right_val;
    }
  return (max);
}

double btree_get_min_value(t_tree tree)
{
  double	left_val;
  double	right_val;
  double	min;

  if (tree == NULL)
    return (0);
  min = tree->value;
  if (tree->left)
    {
      left_val = btree_get_min_value(tree->left);
      min = min < left_val ? min : left_val;
    }
  if (tree->right)
    {
      right_val = btree_get_min_value(tree->right);
      min = min < right_val ? min : right_val;
    }
  return (min);
}
