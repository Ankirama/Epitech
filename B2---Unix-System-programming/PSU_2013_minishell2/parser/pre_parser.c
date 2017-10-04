/*
** pre_parser.c for preparser in /home/mar_b/rendu/PSU_2013_minishell2
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jul 10 14:24:10 2014 mar_b mar_b
** Last update Sun Aug  3 14:19:47 2014
*/

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"
#include "utils.h"

void	*_my_error(char c1, char c2, t_parser *lst)
{
  (void)write(2, "mysh: parse error near '", 24);
  (void)write(2, &c1, 1);
  (void)write(2, &c2, 1);
  (void)write(2, "'\n", 2);
  free_parser(lst);
  return (NULL);
}

/*
** brief: this function will add our new element like (ls /root)
** @arr: our array with all cmds
** @lst: our parser used to add element
** @len: the size we will travel
** @id_opt: the number for our option
** return: return 0 if any problem or -1 if there is for example ;; ;| etc...
*/
static char	_my_add_parser(char **arr, t_parser **lst, int len, int id_opt)
{
  t_parser	*tmp;
  t_parser	*elt;
  int		i;

  tmp = (*lst);
  if ((elt = malloc(sizeof(*elt))) == NULL ||
      (elt->array = malloc(sizeof(char *) * (len + 1))) == NULL)
    my_puterror("error: problem to malloc in my_parser.c\n");
  i = -1;
  while (arr[++i] != NULL && i < len)
    elt->array[i] = my_strdup(arr[i]);
  elt->array[i] = NULL;
  elt->option = id_opt;
  elt->next = NULL;
  if (tmp == NULL)
    (*lst) = elt;
  else
    {
      while (tmp != NULL && tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elt;
    }
  free_arr(arr);
  return (i == 0 ? -1 : 0);
}

static char	_check_quote(char *str, int i, char quote)
{
  if (str[i] == '"' || str[i] == '\'')
    {
      if (i == 0 || str[i - 1] != '\\')
	return (!quote);
    }
  return (quote);
}

/*
** brief: we will travel our string for find each cmd and separate it
** @str: our string with ls ; chmod +x test| yes >>file
** @lst: our structure
** @opt: our array with each option
** @quote: used to check if we have for ex echo "coucou;" (0 = !quote 1 = quote)
** return: return our structure
*/
static t_parser	*_check_opt_shell(char *str, t_parser *lst, char **opt,
				  char quote)
{
  char		**arr;
  int		deb;
  int		i;
  int		j;

  i = -1;
  deb = 0;
  while (str[++i] != '\0')
    {
      quote = _check_quote(str, i, quote);
      j = -1;
      while (!quote && ++j < NBR_OPT && !my_strcmp(&str[i], opt[j], 2));
      if (!quote && j < NBR_OPT)
	{
	  arr = my_str_to_wordtab(&str[deb], " \t", i - deb);
	  if (_my_add_parser(arr, &lst, my_arrlen(arr), j) == -1)
	    return (_my_error(str[(i == 0) ? i : i - 1], str[i], lst));
	}
      i = (j < NBR_OPT && !quote) ? i + my_strlen(opt[j]) - 1 : i;
      deb = (!quote && j < NBR_OPT) ? i + 1 : deb;
    }
  arr = my_str_to_wordtab(&str[deb], " \t", i - deb);
  _my_add_parser(arr, &lst, my_arrlen(arr), NBR_OPT);
  return (my_parserror("error: problem with quotes !\n", quote, lst));
}

/*
** brief: this function will create our structure and return this
** @str: our char * with cmd like chmod +x test ; ls | cat ...
** return: return our t_parser
*/
t_parser	*my_pre_parser(char *str)
{
  t_parser	*lst;
  char		**opt;

  if ((opt = malloc(sizeof(char *) * NBR_OPT)) == NULL)
    my_puterror("error: problem to malloc in my_parser.c\n");
  opt[ID_ADD_FERR] = ">>&";
  opt[ID_ADD_FOUT] = ">>";
  opt[ID_FLUX_ERR] = ">&";
  opt[ID_FLUX_OUT] = ">";
  opt[ID_ADD_FIN] = "<<";
  opt[ID_FLUX_IN] = "<";
  opt[ID_PIPE] = "|";
  opt[ID_WAIT] = ";";
  lst = NULL;
  lst = _check_opt_shell(str, lst, opt, 0);
  free(opt);
  return (lst);
}
