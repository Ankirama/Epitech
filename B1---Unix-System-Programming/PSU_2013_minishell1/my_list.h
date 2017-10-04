/*
** my_list.h for my_list in /home/mar_b/rendu/CPE_2013_Pushswap
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat May 17 20:13:26 2014 mar_b mar_b
** Last update Sat Jun 21 03:09:44 2014 mar_b mar_b
*/

#ifndef MY_LIST_H_
# define MY_LIST_H_

typedef struct	s_list
{
  char		*data;
  struct s_list	*next;
  struct s_list	*prec;
}		t_list;

void	my_add_elt(t_list **list, char *val, char *start);
t_list	*my_create_list(char **env);
void	my_remove_elt(t_list **lst, char *value);
void	my_display_lst(t_list *lst, char type);

#endif /* !MY_LIST_H_ */
