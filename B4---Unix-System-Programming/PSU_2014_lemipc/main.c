/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Fri Mar  6 22:56:39 2015 CHARLES VITERBO
*/

#include "lemipc.h"

static void	_init_area(char *area)
{
  int		i;

  i = -1;
  while (++i < AREA)
    area[i] = 0;
}

/*
** brief : it will check our shared memory, create it and the area too
** @key: used to use shared memory's functions
** return: return the pointer created by shmat
*/
static void	*_init_shm(t_id *ids, t_player *player, int *first, int team)
{
  t_game	game;
  t_game	*tmp;
  void		*p;

  if ((ids->shm_id = shmget(ids->key, SIZE_GAME, SHM_W | SHM_R)) == -1)
    {
      _init_area(game.map);
      *first = 1;
      memset(&(game.teams), 0, sizeof(game.teams));
      if ((ids->shm_id =
	   shmget(ids->key, SIZE_GAME, IPC_CREAT | SHM_W | SHM_R)) == -1)
	error_used(ERR_SHMGET, -1, -1, -1);
      if ((p = shmat(ids->shm_id, NULL, SHM_W | SHM_R)) == (void *)-1)
	error_used(ERR_SHMGET, ids->shm_id, -1, -1);
      memcpy((t_game *)p, &game, SIZE_GAME);
    }
  else
    if ((p = shmat(ids->shm_id, NULL, SHM_W | SHM_R)) == (void *)-1)
      error_used(ERR_SHMGET, ids->shm_id, -1, -1);
  tmp = (t_game *)p;
  choose_team(tmp->teams, player, team < 0 ? 0 : team);
  find_free(tmp->map, player);
  return (p);
}

static int	_init_sem(key_t key, int shm_id)
{
  int		sem_id;

  if ((sem_id = semget(key, 1, SHM_R | SHM_W)) == -1)
    {
      if ((sem_id = semget(key, 1, IPC_CREAT | SHM_R | SHM_W)) == -1)
	error_used(ERR_SEMGET, shm_id, -1, -1);
      if (semctl(sem_id, 0, SETVAL, 0) == -1)
	error_used(ERR_SEMGET, shm_id, sem_id, -1);
    }
  return (sem_id);
}

int		main(int argc, char **argv)
{
  t_id		ids;
  int		first;
  t_game	*p;
  t_player	player;

  init_main(&ids);
  p = _init_shm(&ids, &player, &first, argc > 1 ? atoi(argv[1]) : 0);
  ids.sem_id = _init_sem(ids.key, ids.shm_id);
  if (first)
    {
      if (!(ids.sdl = init_sdl(&ids)))
	return (1);
      wait_first(ids.shm_id, ids.sem_id, p);
    }
  printf("new player in the team no %d\n", player.team);
  loop(&ids, p, &player, first);
  if (ids.sdl != NULL)
    {
      SDL_DestroyRenderer(ids.sdl->renderer);
      SDL_DestroyWindow(ids.sdl->window);
      SDL_Quit();
    }
  return (0);
}
