/*
** tree.h for tree in /home/mar_b/rendu/PSU_2013_42sh/src/parser/binary_tree
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Sep 19 15:48:02 2014 mar_b mar_b
** Last update Thu Oct  2 23:16:43 2014 mar_b mar_b
*/

#ifndef LEXER_H_
# define LEXER_H_

# define ID_ADD_FERR	0
# define ID_ADD_FOUT	1
# define ID_FLUX_ERR	2
# define ID_FLUX_OUT	3
# define ID_ADD_FIN	4
# define ID_FLUX_IN	5
# define ID_PIPE	6
# define ID_WAIT	7

# define NBR_OPT	8

# define IS_FLUX(value) ((value <= 5 && value >= 0) ? 1 : 0)
# define IS_NOT_WAIT(value) (value < 7 && value >= 0)
# define IS_TRUNC(value) ((value == 2 || value == 3 || value == 5) ? 1 : 0)

typedef	struct	s_ast
{
  char		**array;
  char		oper;
  struct s_ast	*dad;
  struct s_ast	*left;
  struct s_ast	*right;
}		t_ast;

/*
** AST_C_
*/
t_ast	*create_element_ast(char **array, char oper);
t_ast	*add_wait_opera(t_ast *ast);
t_ast	*add_operator(t_ast *ast, char *oper, char id_ope);
t_ast	*add_command(t_ast *ast, char *cmd, char **array, int end);
void	remove_right(t_ast **ast);

/*
** MY_STR_TO_WORDTAB_C_
*/
char	**my_str_to_wordtab(char *str, int end, int i, int j);

/*
** FUN_C_
*/
char	strcmp_lexer(const char *s1, const char *s2);
int	check_opt(char *str, char **g_opt);
void	display_arr(char **arr);
void	travel_ast(t_ast *ast);
char	**_my_arrcat(char **arr1, char **arr2);

/*
** LEXER_C_
*/
t_ast	*my_lexer(char *str);

#endif /* !LEXER_H_ */
