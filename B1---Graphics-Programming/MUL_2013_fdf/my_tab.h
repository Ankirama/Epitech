/*
** my_tab.h for my_tab in /home/mar_b/rendu/MUL_2013_fdf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri May  2 17:12:02 2014 Fabien Martinez
** Last update Thu May  8 09:57:12 2014 mar_b mar_b
*/

#ifndef MY_TAB_H_
# define MY_TAB_H_

typedef struct		s_my_tab
{
  char			**data;
  struct s_my_tab	*next;
}			t_my_tab;

t_my_tab	*my_append_elt(t_my_tab *tab, char **data);

#endif /* !MY_TAB_H_ */
