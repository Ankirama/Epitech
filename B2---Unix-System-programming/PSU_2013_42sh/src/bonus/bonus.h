/*
** bonus.h for  in /home/teyssa_r/rendu/PSU_2013_42sh/bonus
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Mon Sep  1 05:09:59 2014 teyssa_r teyssa_r
** Last update Thu Oct  2 21:40:49 2014 teyssa_r teyssa_r
*/

#ifndef BONUS_H_
# define BONUS_H_

# define NB_FCT 12
# define NB_CHAR 3

#include "mini.h"
#include "list.h"

typedef struct	s_hst
{
  char		*name;
  int		val;
  int		root;
  struct s_hst	*prev;
  struct s_hst	*next;
}		t_hst;

typedef struct	s_string
{
  char		buff[BUFF + 1];
  char		*tmp;
  int		len;
  int		size;
  int		i;
}		t_string;
/*
** TAB_FCT_C_
*/

typedef int	(*my_tab_fct)(int *, t_hst **, char *, t_string *);
int		seek_key(int *x, t_hst **hst, t_string *str, char *cmd);

/*
** HISTORY_C_
*/

int		putschar(int nb);
char		*bonus(t_hst *hst, int *len);
char		*history(t_hst *hst, int *len);

/*
** FUNCTION_HST_C_
*/

t_hst		*add_before(t_hst **hst, char *name);
void		delete_hst(t_hst **hst);
t_hst		*make_hst(void);

/*
** FUNCTION_KEY_C_
*/

int		my_key_down(int *x, t_hst **hst, char *cmd, t_string *str);
int		my_key_up(int *x, t_hst **hst, char *cmd, t_string *str);

/*
** FUNCTION_ENTER_C_
*/

int		my_key_end(int *x, t_hst **hst, char *cmd, t_string *str);
int		my_key_start(int *x, t_hst **hst, char *cmd, t_string *str);
char		*my_key_enter(t_hst **hst, t_string *str, char *cmd);

/*
** FUNCTION_SIDE_C_
*/

int		my_key_right(int *x, t_hst **hst, char *cmd, t_string *str);
int		my_key_left(int *x, t_hst **hst, char *cmd, t_string *str);

/*
** FUNCTION_DELETE_C_
*/

int		my_key_del(int *x, t_hst **hst, char *cmd, t_string *str);
int		my_key_delete(int *x, t_hst **hst, char *cmd, t_string *str);

/*
** FIELD_STR_C_
*/

int		field_str_in(t_hst **hst, t_string *str, int *x, char *cmd);

/*
** FUNCTION_INIT_C_
*/

void		init_buff(char *buff, int size);
void		init_realloc(char *str, int size);

/*
** FREE_C_
*/

void		free_string(t_string *str);
void		free_hst(t_hst *hst);
char		*free_null(t_string *str, char *cmd);
char		*free_error(t_hst *hst, t_string *str, char *cmd, int *len);

#endif /* !BONUS_H_ */
