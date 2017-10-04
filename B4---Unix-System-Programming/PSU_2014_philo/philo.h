/*
** philo.h for philo in /home/ankirama
** 
** Made by Fabien martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Mon Feb 23 02:15:34 2015 Fabien martinez
** Last update Fri Feb 27 15:03:05 2015 CHARLES VITERBO
*/

#ifndef PHILO_H_
# define PHILO_H_

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>

# define NBR_PHILO		7
# define TIME_EAT		2
# define TIME_THINK		3
# define PHILO_LEFT(x)		((x + (NBR_PHILO - 1)) % NBR_PHILO)
# define PHILO_RIGHT(x)		((x + 1) % NBR_PHILO)
# define IDX_NO_ERROR		0
# define IDX_MUTEX_LOCK		1
# define IDX_MUTEX_UNLOCK	2

# define ERR_PTHREAD_CRT	"Error with pthread_create!"
# define ERR_MUTEX_INIT		"Error with ptreahd_mutex_init!"
# define ERR_USLEEP		"Error with usleep!"
# define ERR_MUTEX_LOCK		"Error with mutex_lock!"
# define ERR_MUTEX_UNLOCK	"Error with mutex_unlock!"
# define ERR_MALLOC		"Error with malloc!"
# define ERR_FREE		"Error with free!"

# define CLR_RED		"\033[1;31m"
# define CLR_BLUE		"\033[1;34m"
# define CLR_RESET		"\033[0m"
# define STR_PHILO		"Philosopher n°"

typedef enum	e_state
{
  REST,
  THINK,
  EAT,
  ATE
}		t_state;

typedef struct		s_args
{
  t_state		*states;
  pthread_mutex_t	*rods;
  int			index;
}			t_args;

/*
** state.c
*/
int	take_rods(t_state *states, pthread_mutex_t *rods,
		  pthread_mutex_t *mutex, int index);
int	put_rods(t_state *states, pthread_mutex_t *rods,
		 pthread_mutex_t *mutex, int index);

#endif /* !PHILO_H_ */
