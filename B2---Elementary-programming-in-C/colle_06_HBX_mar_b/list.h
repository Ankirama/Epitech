/*
** list.h for let it go in /home/user/rendu/colle_06_HBX_
**
** Made by 
** Login   
**
** Started on  Tue Sep 30 18:55:28 2014 
** Last update Tue Sep 30 21:26:01 2014 
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_list
{
  char		carac;
  unsigned int	nbr;
  struct s_list	*next;
  struct s_list	*prec;
}		t_list;

void	add_element(t_list **lst, char carac, unsigned int nbr);
void	let_it_go(t_list *lst);
void	travel_lst(t_list *lst, char rev);
void	travel_range(t_list *lst, char rev, unsigned int nbr);

#endif /* !LIST_H_ */
