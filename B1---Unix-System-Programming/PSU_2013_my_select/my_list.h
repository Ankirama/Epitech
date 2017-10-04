/*
** my_list.h for my_list in /home/mar_b/rendu/PSU_2013_my_select
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu May 15 11:19:30 2014 mar_b mar_b
** Last update Fri May 16 16:08:54 2014 mar_b mar_b
*/

#ifndef MY_LIST_H_
# define MY_LIST_H_

typedef struct	s_list
{
  char		*data;
  int		size;
  char		active;
  struct s_list	*next;
  struct s_list	*prec;
}		t_list;

t_list	*my_create_list(char **argv, int argc);
void	my_display_list(t_list *list);
t_list	*my_ret_elt(t_list *lst, int pos);
void	my_let_it_go(t_list *list);

#endif /* !MY_LIST_H_ */
