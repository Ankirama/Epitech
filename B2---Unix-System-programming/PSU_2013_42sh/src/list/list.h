/*
** my_list.h for my_list in /home/mar_b/rendu/CPE_2013_Pushswap
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat May 17 20:13:26 2014 mar_b mar_b
** Last update Thu Oct  2 21:24:30 2014 chenev_d chenev_d
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_list
{
  char		*data;
  struct s_list	*next;
  struct s_list	*prec;
}		t_list;

typedef struct		s_double
{
  char			*str;
  struct s_double	*next;
}			t_double;

char	my_add_elt(t_list **list, char *val, char *start);
t_list	*my_create_list(char **env);
void	my_remove_elt(t_list **lst, char *value);
void	my_display_lst(t_list *lst, char type);
char	*my_find_element(t_list *lst, char *value);

#endif /* !LIST_H_ */
