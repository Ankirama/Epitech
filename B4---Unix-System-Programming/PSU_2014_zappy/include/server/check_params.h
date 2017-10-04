/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

#ifndef CHECK_PARAMS_H_
# define CHECK_PARAMS_H_

# include "server.h"

# define ID_OPT_PORT		0
# define ID_OPT_WIDTH		1
# define ID_OPT_HEIGHT		2
# define ID_OPT_TEAMS		3
# define ID_OPT_CLIENTS		4
# define ID_OPT_TIME		5
# define ID_OPT_DEBUG		6

# define NO_LIMITS		-1

# define MAX_VAL_PORT		1
# define MAX_VAL_WIDTH		1
# define MAX_VAL_HEIGHT		1
# define MAX_VAL_TEAMS		NO_LIMITS
# define MAX_VAL_CLIENTS	1
# define MAX_VAL_TIME		1
# define MAX_VAL_DEBUG		0

# define NB_OPT			7

# define ID_NO_ERR		0
# define ID_ERR_NO_OPT		1
# define ID_ERR_ALRD_USED	2
# define ID_ERR_OPT_NOT_SET	3

/*
** @def not enough args for specific option
*/
# define ID_ERR_NOT_ENG_ARG	4

# define ERR_NO_OPT		"not an option."
# define ERR_ALRD_USED		"option already used."
# define ERR_OPT_NOT_SET	"option isn't set."
# define ERR_NOT_ENG_ARG	"not enough arguments for option."

typedef struct	s_opt_pos
{
  char		*opt;
  int		pos;
  int		nbr_val;
  int		max_val;
}		t_opt_pos;

typedef struct	s_opt_arg
{
  char		*port;
  unsigned int	x;
  unsigned int	y;
  char		**teams;
  unsigned int	clients;
  unsigned int	time;
  int		debug;
}		t_opt_arg;

int		free_options(t_opt_arg *opt_arg);
t_opt_arg	*set_options(int argc, char **argv);

#endif /* !CHECK_PARAMS_H_ */
