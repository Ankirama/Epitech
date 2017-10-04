/*
** my_sort.h for my_sort.h in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Apr 29 15:19:07 2014 Fabien Martinez
** Last update Thu May  1 23:43:12 2014 Fabien Martinez
*/

#ifndef MY_SORT_H_
# define MY_SORT_H_

typedef struct	s_my_def_file
{
  char		*name;
  unsigned char	type;
}		t_my_def_file;

char	my_sort_list(t_my_file **begin, char reverse, char *opt);
char	**my_sort_alpha(char **arr, char reverse);

#endif /* !MY_SORT_H_ */
