/*
** checkCommand.c for parsing in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Aug 21 13:19:11 2014 mar_b mar_b
** Last update Mon Aug 25 16:05:16 2014
*/

#include "utils.h"
#include "asm_utils.h"
#include "op.h"
#include "parsing.h"

/*
** brief : for remove space and tabulation
** @str : our sentence
** @i : the current position and we change it
*/
static void	_remove_space(char *str, int *i)
{
  while (str[*i] != '\0' && (str[*i] == ' ' || str[*i] == '\t'))
    *i = *i + 1;
}

/*
** brief : try to match the current char with the char *
** @c : our current char
** @ref : we'll try to match our char with the ref
** return: return 1 if we match it, else 0
*/
char		good_char(char c, const char *ref)
{
  int		i;

  i = 0;
  while (ref[i] != '\0' && c != ref[i])
    ++i;
  return (ref[i] != '\0' && c == ref[i]);
}

/*
** brief : we will try to find a label (like toto: add r1,r2,r3)
** @str : the current line where we're trying to find a label
** @line : our current line number
** @lst : our struct to add our label
** return: return a new position (for i) if we found a label, else 0
*/
static char	_check_label(char *str, int line, t_asm **lst)
{
  int		i;

  i = 0;
  _remove_space(str, &i);
  while (str[i] != '\0' && str[i] != COMMENT_CHAR &&
	 str[i] != LABEL_CHAR && good_char(str[i], LABEL_CHARS))
    ++i;
  _remove_space(str, &i);
  if (str[i] == '\0' || str[i] == COMMENT_CHAR)
    my_error_line(line);
  if (str[i] == LABEL_CHAR)
    {
      add_label(lst, str, line);
      return (i + 1);
    }
  else
    return (0);
}

/*
** brief : main function to fill our structure
** @str : our current line
** @lst : our struct with instr/labels
** @line : our line number
*/
void	check_command(char *str, t_asm **lst, int line)
{
  int	i;

  i = _check_label(str, line, lst);
  _remove_space(str, &i);
  if (str[i] != '\0')
    add_instru(lst, &str[i], line);
}
