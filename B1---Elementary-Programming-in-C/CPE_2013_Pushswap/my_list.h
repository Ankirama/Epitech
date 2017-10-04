/*
** my_list.h for my_list in /home/user/rendu/CPE_2013_Pushswap
**
** Made by 
** Login   
**
** Started on  Sat May 17 20:13:26 2014 
** Last update Mon Jun  2 11:36:18 2014 
*/

#ifndef MY_LIST_H_
# define MY_LIST_H_

typedef struct	s_list
{
  int		data;
  int		size;
  struct s_list	*next;
  struct s_list	*prec;
}		t_list;

t_list	*my_create_list(int argc, char **argv);
void	my_display_list(t_list *list);
void	my_remove_elt(t_list *lst, int pos);
void	my_empty_lb(t_list **l_a, t_list **l_b);

#endif /* !MY_LIST_H_ */
