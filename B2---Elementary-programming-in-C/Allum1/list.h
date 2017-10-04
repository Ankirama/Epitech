/*
** list.h for list in /home/mar_b/rendu/Allum1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul  1 13:57:08 2014 mar_b mar_b
** Last update Tue Jul  1 14:30:09 2014 mar_b mar_b
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_list
{
  int		nbr_ele;
  char		*bin;
  struct s_list	*next;

}		t_list;

t_list	*create_list(int length);
void	remove_ele(t_list *lst, int pos);
void	free_lst(t_list *lst);

#endif /* !LIST_H_ */
