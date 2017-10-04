/*
** utils.c for utils in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 22:17:01 2015 Fabien Martinez
** Last update Sun Mar  8 17:04:13 2015 CHARLES VITERBO
*/

#include "lemipc.h"

void	print_error(const char *msg)
{
  fprintf(stderr, "Error : %s\n", msg);
  exit(EXIT_FAILURE);
}

void	error_used(const char *msg, int shm_id, int sem_id, int msg_id)
{
  if (shm_id != -1 && shmctl(shm_id, IPC_RMID, NULL) == -1)
    print_error(ERR_SHMDEL);
  if (sem_id != -1 && semctl(sem_id, 0, IPC_RMID) == -1)
    print_error(ERR_SEMDEL);
  if (msg_id != -1 && msgctl(msg_id, IPC_RMID, NULL) == -1)
    print_error(ERR_MSGDEL);
  print_error(msg);
}

char	clean_data(int shm_id, int sem_id, int msg_id)
{
  if (shm_id != -1)
    (void)shmctl(shm_id, IPC_RMID, NULL);
  if (sem_id != -1)
    (void)semctl(sem_id, 0, IPC_RMID);
  if (msg_id != -1)
    (void)msgctl(msg_id, IPC_RMID, NULL);
  return (1);
}

void		display_area(char *area)
{
  int		i;
  int		j;

  i = -1;
  while (++i < SIZE_AREA)
    {
      j = -1;
      printf("[");
      while (++j < SIZE_AREA)
	{
	  if (j != 0)
	    printf("|");
	  if (area[i * SIZE_AREA + j] != 0)
	    printf("\033[1;41m%d\033[0m", area[i * SIZE_AREA + j]);
	  else
	    printf("%d", area[i * SIZE_AREA + j]);
	}
      printf("]\n");
    }
  printf("\n");
}

void	init_main(t_id *ids)
{
  srand((unsigned)time(NULL) * getpid());
  if ((ids->key = ftok(PATH, 0)) == -1)
    print_error(ERR_FTOK);
}
