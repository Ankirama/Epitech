/*
** 209sondage.h for  in /home/viterb_c/rendu/209sondage/C
** 
** Made by CHARLES VITERBO
** Login   <viterb_c@epitech.net>
** 
** Started on  Thu Jun  4 20:28:28 2015 CHARLES VITERBO
** Last update Sat Jun  6 07:56:34 2015 CHARLES VITERBO
*/

#ifndef SONDAGE_H_
# define SONDAGE_H_

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define USAGE	"./209 population echantillon vote\n"
# define POPULATION	"The population must be a number > 0\n"
# define ECHANTILLON	"Echantillon must be a number > 0\n"
# define VOTE	"Vote must be a float > 0\n"

// UTILS.C
int	nbr(char *);
float	nbr_float(char *);
int	my_error(char *);

#endif /* !SONDAGE_H_ */
