/*
** lemipc.h for lemipc in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:54:12 2015 Fabien Martinez
** Last update Sun Mar  8 17:00:45 2015 CHARLES VITERBO
*/

#ifndef LEMIPC_H_
# define LEMIPC_H_

# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/sem.h>
# include <sys/msg.h>
# include <sys/shm.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
# include <unistd.h>

# include <SDL2/SDL.h>

# define MTYPE		42
# define MAX_TEAMS	10
# define MAX_PLAYERS	10
# define SIZE_AREA	200
# define AREA		SIZE_AREA * SIZE_AREA
# define WAIT_TIME	80000
# define SCREEN		3 * SIZE_AREA

# define PATH		"./"

# define ERR_MSGSND	"unable to send a message"
# define ERR_MSGRCV	"unable to receive a message"
# define ERR_MSGDEL	"unable to remove msgq"
# define ERR_SEMGET	"unable to create semaphore"
# define ERR_SEMOP	"unable to use semop"
# define ERR_SEMDEL	"unable to remove semaphore"
# define ERR_SHMGET	"unable to create shared memory"
# define ERR_SHMDEL	"unable to remove shared memory"
# define ERR_SHMAT	"unable to attach shared memory"
# define ERR_MSGGET	"unable to create msgq"
# define ERR_TEAMS	"unable to add another team"
# define ERR_TIME	"unable to find another team"
# define ERR_FTOK	"unable to create a key with ftok"

# define ERR_MALLOC	"Error with malloc !\n"
# define ERR_INIT	"SDL could not initialize ! SDL_Error : %s\n"

typedef struct	s_msg
{
  long		mtype;
  int		id;
}		t_msg;

typedef struct	s_sdl
{
  SDL_Window	*window;
  SDL_Renderer	*renderer;
}		t_sdl;

typedef struct	s_id
{
  key_t		key;
  int		shm_id;
  int		sem_id;
  t_sdl		*sdl;
}		t_id;

typedef struct	s_player
{
  int		team;
  int		x;
  int		y;
}		t_player;

typedef struct s_game
{
  char		map[AREA];
  int		teams[MAX_TEAMS];
}		t_game;

# define SIZE_GAME	sizeof(t_game)

/*
** position.c
*/
void	change_pos(t_player *player, t_game *game);
char	check_pos(t_player *, t_game *, int, int);
char	check_inf(t_game *game);

/*
** utils.c
*/
void	print_error(const char *msg);
void	error_used(const char *msg, int shm_id, int sem_id, int msg_id);
char	clean_data(int shm_id, int sem_id, int msg_id);
void	init_main(t_id *ids);

/*
** team.c
*/
void	find_free(char *area, t_player *player);
void	choose_team(int *teams, t_player *player, int id);
char	check_team(t_game *game);
int	check_winner(t_game *game);

/*
** utils2.c
*/
void	wait_first(int shm_id, int sem_id, t_game *game);
char	player_ok(t_player *player, int first);
void	loop(t_id *ids, t_game *game, t_player *player, int first);
void	my_semop(t_id *ids, struct sembuf *sops, size_t pos);
void	init_sembuf(struct sembuf *sops, int *started);

/*
** sdl.c
*/
t_sdl	*init_sdl(t_id *ids);
void	display_sdl(char *, t_sdl *);

/*
** ai.c
*/
void	move(t_player *player, t_game *game);

#endif /* !LEMIPC_H_ */
