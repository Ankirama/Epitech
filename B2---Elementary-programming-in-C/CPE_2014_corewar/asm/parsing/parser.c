/*
** parser.c for parsing in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Aug 21 13:19:28 2014 mar_b mar_b
** Last update Mon Aug 25 16:06:12 2014
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "utils.h"
#include "asm_utils.h"
#include "asm.h"
#include "parsing.h"
#include "op.h"

/*
** brief: display a message when the type's length > max allowed
** @type: type like "name" or "comment"
** @size: the max size allowed
*/
static void	_warning_size(const char *type, const int size)
{
  my_write(2, "Warning the ", my_strlen("warning the "));
  my_write(2, type, my_strlen(type));
  my_write(2, ERR_SIZENAME, my_strlen(ERR_SIZENAME));
  my_putnbr(size, 2);
  my_putchar(2, '\n');
}

/*
** brief: return the name of the line, if we've ".name "toto""
** it will return toto
** @s: our line
** @line: the current line number
** @size: the limit (defined in the header)
** return: return the name
*/
static void	_get_name(header_t **lst, char *src,
			  int line, char type)
{
  int		i;
  int		j;
  int		size;

  size = (type == 0) ? PROG_NAME_LENGTH : COMMENT_LENGTH;
  i = 0;
  if (my_strlen(src) > size)
    _warning_size((type == 0) ? "name" : "comment",
		   (type == 0) ? PROG_NAME_LENGTH : COMMENT_LENGTH);
  while (src[i] != '\0' && src[i] != '\"' && src[i] != COMMENT_CHAR)
    ++i;
  if (src[i] == '\0' || src[i] == COMMENT_CHAR)
    my_error_line(line);
  j = -1;
  size = my_strlen(src);
  if (type == 0)
    while (++i <= size && src[i] != '\"' && src[i] != COMMENT_CHAR)
      (*lst)->prog_name[++j] = src[i];
  else
    while (++i <= size && src[i] != '\"' && src[i] != COMMENT_CHAR)
      (*lst)->comment[++j] = src[i];
  if (type == 0)
    (*lst)->prog_name[++j] = '\0';
  else
    (*lst)->comment[++j] = '\0';
}

/*
** brief: it will check if it's an header part and set it if not it will
** call check_command
** @str: the current line in the file
** @lst: our header
** @line: our line number
*/
static void	_non_command(char *str, header_t **header, int line,
			     t_asm **lst)
{
  int		i;
  char		**types;

  types = my_malloc(sizeof(char *) * 3);
  types[0] = my_malloc(sizeof(char) * 2);
  i = 0;
  types[0][0] = COMMENT_CHAR;
  types[0][1] = '\0';
  types[1] = NAME_CMD_STRING;
  types[2] = COMMENT_CMD_STRING;
  while (i < 3 && my_strcmp_pre_asm(str, types[i]) != 1)
    ++i;
  if (i == 1)
    _get_name(header, str, line, 0);
  else if (i == 2)
    _get_name(header, str, line, 1);
  else if (i != 0 && my_strcmp_pre_asm(str, "") != -1)
    check_command(str, lst, line);
  i = -1;
  free(types[0]);
  free(types);
}

/*
** brief: main function to parse asm
** @header: header struct
** fd: file descriptor (to read the file)
*/
t_asm	*my_parser(header_t *header, const int fd)
{
  char	*s;
  int	line;
  t_asm	*lst;

  line = 0;
  lst = NULL;
  while ((s = get_next_line(fd)) != NULL)
    {
      ++line;
      _non_command(s, &header, line, &lst);
      free(s);
    }
  if (line == 0)
    my_error_line(1);
  return (lst);
}
