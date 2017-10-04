/*
** my_list.h for my_list in /home/user/rendu/CPE_2013_Pushswap
**
** Made by 
** Login   
**
** Started on  Sat May 17 20:13:26 2014 
** Last update Wed Jun 25 00:45:57 2014 
*/

#ifndef LIST_H_
# define LIST_H_

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
char	*my_find_element(t_list *lst, char *value);

#endif /* !LIST_H_ */
