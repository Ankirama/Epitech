/*
** list.h for list in /home/user/rendu/Allum1
**
** Made by 
** Login   
**
** Started on  Tue Jul  1 13:57:08 2014 
** Last update Tue Jul  1 14:30:09 2014 
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
