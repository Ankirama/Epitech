/*
** mylist.h for my_list in /home/mar_b/rendu/Piscine-C-include
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Mar 25 09:00:50 2014 Fabien Martinez
** Last update Tue Mar 25 09:03:43 2014 Fabien Martinez
*/

#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

#endif /* !MY_LIST_H_ */
