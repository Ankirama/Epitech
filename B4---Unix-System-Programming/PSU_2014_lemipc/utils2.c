/*
** utils.c for utils in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 22:17:01 2015 Fabien Martinez
** Last update Sun Mar  8 16:09:06 2015 CHARLES VITERBO
*/

#include "lemipc.h"

void		wait_first(int shm_id, int sem_id, t_game *game)
{
  int		count;
  struct sembuf	sops;

  init_sembuf(&sops, &count);
  count = 0;
  printf("Waiting players...\n");
  while (!check_team(game) && ++count < WAIT_TIME)
    usleep(100);
  if (count >= WAIT_TIME)
    error_used(ERR_TIME, shm_id, sem_id, -1);
  sops.sem_op = 1;
  if (semop(sem_id, &sops, 1))
    error_used(ERR_SEMOP, shm_id, sem_id, -1);
}

char	player_ok(t_player *player, int first)
{
  if (first)
    return (1);
  else
    return (player->team != 0);
}

void		loop(t_id *ids, t_game *game, t_player *player, int first)
{
  struct sembuf sops;
  int		started;

  init_sembuf(&sops, &started);
  while (started ||
	 (!check_winner(game) && check_inf(game) && player_ok(player, first)))
    {
      usleep(50000);
      started = 0;
      sops.sem_op = -1;
      my_semop(ids, &sops, 1);
      change_pos(player, game);
      sops.sem_op = 1;
      my_semop(ids, &sops, 1);
      if (first)
	display_sdl(game->map, ids->sdl);
      if (player->team == 0)
	printf("Arggggg I can't continue to fight!\n");
    }
  if (first && !check_inf(game) && clean_data(ids->shm_id, ids->sem_id, -1))
    printf("Unable to finish the fight\n");
  else if (first && check_winner(game) &&
	   clean_data(ids->shm_id, ids->sem_id, -1))
    printf("Team %d won this amazing fight!\n", check_winner(game));
}

void	my_semop(t_id *ids, struct sembuf *sops, size_t pos)
{
  if (semop(ids->sem_id, sops, pos))
    {
      clean_data(ids->shm_id, ids->sem_id, -1);
      exit(EXIT_FAILURE);
    }
}

void	init_sembuf(struct sembuf *sops, int *started)
{
  sops->sem_num = 0;
  sops->sem_flg = 0;
  *started = 1;
}
