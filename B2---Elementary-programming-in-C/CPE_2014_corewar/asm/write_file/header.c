/*
** header.c for write_file in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Aug 21 13:20:55 2014 mar_b mar_b
** Last update Fri Aug 29 15:50:35 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "utils.h"
#include "asm_utils.h"
#include "asm.h"
#include "op.h"
#include "write_file.h"

/*
** brief: display a warnin message
** @str: "name" or "comment"
*/
static void	_warning_empty(const char *str)
{
  my_write(2, "warning: the ", my_strlen("warning: the "));
  my_write(2, str, my_strlen(str));
  my_write(2, " is empty\n", my_strlen(" is empty\n"));
}

/*
** brief: it will write our header into our file, it will check eaCh instru too
** @header: the struct with infos like name, comment etc...
** @fd: the file descriptor to write into our file
** @lst: the struct with instru/labels
*/
void	create_header(header_t *header, const int fd, t_asm *lst)
{
  t_asm	*tmp;

  tmp = lst;
  header->prog_size = 0;
  while (tmp != NULL)
    {
      if (tmp->type == 1)
	check_instru(tmp, lst, &header->prog_size);
      tmp = tmp->next;
    }
  write_int(fd, header->magic, 0, 24);
  if (my_strlen(header->prog_name) == 0)
    _warning_empty("name");
  write_str(fd, header->prog_name, PROG_NAME_LENGTH);
  write_int(fd, header->prog_size, 0, 24);
  if (my_strlen(header->comment) == 0)
    _warning_empty("comment");
  write_str(fd, header->comment, COMMENT_LENGTH);
}
