/*
** tree.h for tree_struct in /home/user/rendu/Piscine-C-Jour_14
**
** Made by 
** Login   
**
** Started on  Thu Mar 27 11:50:47 2014 
** Last update Thu Mar 27 11:52:00 2014 
*/

#ifndef TREE_H_
# define TREE_H_

typedef struct		s_btree
{
  struct s_btree	*left;
  struct s_btree	*right;
  void			*item;
}			t_btree;

#endif /* !TREE_H_ */
