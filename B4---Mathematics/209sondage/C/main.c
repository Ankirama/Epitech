/*
** main.c for  in /home/viterb_c/rendu/209sondage/C
** 
** Made by CHARLES VITERBO
** Login   <viterb_c@epitech.net>
** 
** Started on  Sat Jun  6 07:07:15 2015 CHARLES VITERBO
** Last update Sat Jun  6 08:07:41 2015 CHARLES VITERBO
*/

#include "209sondage.h"

float	calc_variance(float pop, float echan, float vote)
{
  float	p;
  float	var;

  p = vote / 100.0;
  var = p * (1 - p);
  return (var / echan * (pop - echan) / (pop - 1.0));
}

void	print_result(int pop, int echan, float vote, float variance, float amp_95, float amp_99)
{
  printf("taille de la population :\t %d\n", pop);
  printf("taille de l'echantillon :\t %d\n", echan);
  printf("resultat du sondage :\t \t %.2f\n", vote);
  printf("variance estimee :\t \t %.6f\n", variance);
  printf("intervalle de confiance a 95%% : [%.2f%% ; %.2f%%]\n", vote - amp_95, vote + amp_95);
  printf("intervalle de confiance a 99%% : [%.2f%% ; %.2f%%]\n", vote - amp_99, vote + amp_99);
}

void	run_calc(int pop, int echan, float vote)
{
  float	variance;
  float	amp_95;
  float	amp_99;

  variance = calc_variance(pop, echan, vote);
  amp_95 = 1.96 * sqrt(variance) * 100;
  amp_99 = 2.58 * sqrt(variance) * 100;
  print_result(pop, echan, vote, variance, amp_95, amp_99);
}


int	check_arg(char **argv, int *pop, int *echan, float *vote)
{
  if ((*pop = nbr(argv[1])) == -1)
    return (my_error(POPULATION));
  if ((*echan = nbr(argv[2])) == -1)
    return (my_error(ECHANTILLON));
  if ((*vote = nbr_float(argv[3])) == -1)
    return (my_error(VOTE));
  return (0);
}

int	main(int argc, char **argv)
{
  int	pop;
  int	echan;
  float	vote;

  if (argc != 4)
    return (my_error(USAGE));
  if (check_arg(argv, &pop, &echan, &vote) == 1)
    return (1);
  run_calc(pop, echan, vote);
  return (0);
}
