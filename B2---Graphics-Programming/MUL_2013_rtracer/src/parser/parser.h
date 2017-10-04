/*
** parser.h for  in /home/viterb_c/rendu/MUL_2013_rtracer/parser
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Tue Sep 30 10:15:15 2014 charles viterbo
** Last update Sun Oct 12 14:33:04 2014 charles viterbo
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "objects.h"

# define SIZE 8

typedef struct	s_tab_get_scene
{
  char		*name;
  void		(*create)(t_scene **, char **);
}		t_tab_get_scene;

t_scene	*get_scene(const char *file_name, t_scene *list);

#endif /* !PARSER_H_ */
