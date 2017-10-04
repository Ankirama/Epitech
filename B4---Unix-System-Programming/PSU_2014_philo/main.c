/*
** main.c for main in /home/ankirama
** 
** Made by Fabien martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Mon Feb 23 02:19:01 2015 Fabien martinez
** Last update Sat Feb 28 01:14:19 2015 CHARLES VITERBO
*/

#include "philo.h"

static pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_t	g_threads[NBR_PHILO];
static t_state		g_states[NBR_PHILO];
static pthread_mutex_t	g_rods[NBR_PHILO];

void    state_table()
{
  int   j;

  usleep(50000);
  printf("%s********** T A B L E **********%s\n", CLR_RED, CLR_RESET);
  j = -1;
  while (++j < NBR_PHILO)
    {
      if (g_states[j] == REST)
        printf("%s*%s Philosopher n°%d is resting  %s*%s\n",
	       CLR_RED, CLR_RESET, j + 1, CLR_RED, CLR_RESET);
      else if (g_states[j] == THINK)
        printf("%s*%s Philosopher n°%d is thinking %s*%s\n",
	       CLR_RED, CLR_RESET, j + 1, CLR_RED, CLR_RESET);
      else
	printf("%s*%s Philosopher n°%d is eating   %s*%s\n",
	       CLR_RED, CLR_RESET, j + 1, CLR_RED, CLR_RESET);
    }
  printf("%s*******************************%s\n", CLR_RED, CLR_RESET);
}

void		*pthread_function(void *p)
{
  int		err;
  int		index;

  index = *((int *)p);
  err = IDX_NO_ERROR;
  while (err == IDX_NO_ERROR)
    {
      state_table();
      if ((err = take_rods(g_states, g_rods, &g_mutex, index)) == IDX_NO_ERROR)
	err = put_rods(g_states, g_rods, &g_mutex, index);
    }
  if (err == IDX_MUTEX_LOCK)
    fprintf(stderr, "%s\n", ERR_MUTEX_LOCK);
  else if (err == IDX_MUTEX_UNLOCK)
    fprintf(stderr, "%s\n", ERR_MUTEX_UNLOCK);
  pthread_exit(0);
}

static int	_init()
{
  int		i;
  int		error;

  i = -1;
  error = 0;
  while (++i < NBR_PHILO && error == 0)
    {
      g_states[i] = REST;
      if (pthread_mutex_init(&g_rods[i], NULL) != 0)
	error = 1;
    }
  if (error)
    {
      fprintf(stderr, "%s\n", ERR_MUTEX_INIT);
      return (1);
    }
  return (0);
}

static int	_create_pthread()
{
  int		i;
  int		error;

  error = 0;
  i = -1;
  while (++i < NBR_PHILO && error == 0)
    {
      sleep(1);
      if (pthread_create(&g_threads[i], NULL, pthread_function, &i) != 0)
	error = 1;
    }
  i = -1;
  while (error == 0 && ++i < NBR_PHILO)
    if (pthread_join(g_threads[i], NULL) != 0)
      error = 1;
  if (error)
    {
      fprintf(stderr, "%s\n", ERR_PTHREAD_CRT);
      return (1);
    }
  return (0);
}

int			main()
{
  srandom(time(NULL));
  if (_init())
    return (EXIT_FAILURE);
  if (_create_pthread())
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
