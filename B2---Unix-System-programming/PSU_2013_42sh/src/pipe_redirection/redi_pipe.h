/*
** redi_pipe.h for  in /home/viterb_c/rendu/PSU_2013_42sh/src/pipe_redirection
** 
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
** 
** Started on  Thu Oct  2 23:01:45 2014 charles viterbo
** Last update Thu Oct  2 23:17:41 2014 charles viterbo
*/

#ifndef REDI_PIPE_
# define REDI_PIPE_

# include "list.h"
# include "utils.h"
# include "parser.h"
# include "execution.h"

/*
** HERE_DOC_C
*/
t_double	*my_add(t_double **list, char *word);
t_double	*fill_tab(t_double **l_double, char **right);
char		process_heredoc(t_ast *left, int fd[2],
				t_double *l_double, t_list *env);
int		dup_stdin_doub(t_ast *left, char **right,
			       t_list *env, t_ope *ope);

/*
** PIPE_C_
*/
int		pipe_cmd(t_ast *left, char **right,
			 t_list *env, t_ope *ope);

/*
** REDIRECTION_C_
*/
int		dup_stdout(t_ast *left, char **right,
			   t_list *env, t_ope *ope);
int		dup_stdout_err(t_ast *left, char **right,
			       t_list *env, t_ope *ope);
int		dup_stdin_sim(t_ast *left, char **right,
			      t_list *env, t_ope *ope);

#endif /* *REDI_PIPE_ */
