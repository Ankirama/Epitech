/*
** manipulate_map.h for  in /home/viterb_c/rendu/PSU_2014_zappy/include/server
** 
** Made by CHARLES VITERBO
** Login   <viterb_c@epitech.net>
** 
** Started on  Thu Jun 18 09:32:25 2015 CHARLES VITERBO
** Last update Sat Jul  4 00:26:40 2015 CHARLES VITERBO
*/

#ifndef MANIPULATE_MAP_H
# define MANIPULATE_MAP_H

# include "server.h"
# include "object.h"
# include "utils.h"

# define POURC_COM	3
# define POURC_RARE	10
# define POURC_FOOD	2

int	generate_map(t_map *);
int	generate_object(t_map *, int, unsigned int, unsigned int *);
void	drop_object(t_map *, unsigned int, int);
int	take_object(t_map *, unsigned int, int);

#endif /* !MANIPULATE_MAP_H */
