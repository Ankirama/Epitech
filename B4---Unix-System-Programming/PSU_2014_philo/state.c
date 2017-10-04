/*
** state.c for  in /home/viterb_c/rendu/PSU_2014_philo
** 
** Made by CHARLES VITERBO
** Login   <viterb_c@epitech.net>
** 
** Started on  Wed Feb 25 09:52:21 2015 CHARLES VITERBO
** Last update Sat Feb 28 01:12:43 2015 CHARLES VITERBO
*/

#include "philo.h"

static int	neighbors(t_state *states, pthread_mutex_t *rods, int index)
{
  if (states[PHILO_LEFT(index)] == REST
      && states[PHILO_RIGHT(index)] == REST)
    {
      if (pthread_mutex_lock(&(rods[index])) != 0)
	return (IDX_MUTEX_LOCK);
      if (random() % 2 == 0)
	{
	  states[index] = EAT;
	  printf("%sPhilosopher n°%d takes rods %d and %d.%s\n", CLR_BLUE,
		 index + 1, PHILO_LEFT(index) + 1, index + 1, CLR_RESET);
	  sleep(TIME_EAT);
	  states[index] = ATE;
	}
      else
	{
	  states[index] = THINK;
	  sleep(TIME_THINK);
	}
      if (pthread_mutex_unlock(&rods[index]) != 0)
	return (IDX_MUTEX_UNLOCK);
    }
  return (IDX_NO_ERROR);
}

int	take_rods(t_state *states, pthread_mutex_t *rods,
		  pthread_mutex_t *mutex, int index)
{
  int	error;

  if (pthread_mutex_lock(mutex) != 0)
    return (IDX_MUTEX_LOCK);
  if ((error = neighbors(states, rods, index)) != IDX_NO_ERROR)
    return (error);
  if (pthread_mutex_unlock(mutex) != 0)
    return (IDX_MUTEX_UNLOCK);
  sleep(TIME_THINK);
  return (IDX_NO_ERROR);
}

int	put_rods(t_state *states, pthread_mutex_t *rods,
		 pthread_mutex_t *mutex, int index)
{
  int	error;

  if (pthread_mutex_lock(mutex) != 0)
    return (IDX_MUTEX_LOCK);
  states[index] = REST;
  printf("%sPhilosopher n°%d is putting rod n°%d and n°%d on the table.%s\n",
	 CLR_BLUE, index + 1, PHILO_LEFT(index) + 1, index + 1, CLR_RESET);
  if ((error = neighbors(states, rods, PHILO_LEFT(index))) != IDX_NO_ERROR)
    return (error);
  if ((error = neighbors(states, rods, PHILO_RIGHT(index))) != IDX_NO_ERROR)
    return (error);
  if (pthread_mutex_unlock(mutex) != 0)
    return (IDX_MUTEX_UNLOCK);
  return (IDX_NO_ERROR);
}
