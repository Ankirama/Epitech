/*
** list.h for let it go in /home/mar_b/rendu/colle_06_HBX_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep 30 18:55:28 2014 mar_b mar_b
** Last update Tue Sep 30 21:26:01 2014 mar_b mar_b
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
