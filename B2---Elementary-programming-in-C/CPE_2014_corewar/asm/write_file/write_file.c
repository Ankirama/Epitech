/*
** write_file.c for write_file in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Aug 21 13:21:09 2014 mar_b mar_b
** Last update Fri Aug 29 21:04:45 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "op.h"
#include "write_file.h"
#include "asm_utils.h"
#include "utils.h"

/*
** brief: display the "assemblin' message"
** @header: used to write the name and comment
** @file: the .s' name
*/
static void	_my_assembling_msg(header_t *header, const char *file)
{
  my_write(1, "Assembling ", my_strlen("Assembling "));
  my_write(1, file, my_strlen(file));
  my_putchar(1, '\n');
  if (my_strlen(header->prog_name) > 0)
    {
      my_write(1, "\t", my_strlen("\t"));
      my_write(1, header->prog_name, my_strlen(header->prog_name));
      my_putchar(1, '\n');
    }
  if (my_strlen(header->comment) > 0)
    {
      my_write(1, "\t", my_strlen("\t"));
      my_write(1, header->comment, my_strlen(header->comment));
      my_putchar(1, '\n');
    }
}

/*
** brief: main function to write into our .cor
** @lst: our struct with instru/labels
** @fd: file descriptor
** @header: the header's struct
** @file: the .s's name
*/
void		write_file(t_asm *lst, const int fd, header_t *header,
			   const char *file)
{
  t_asm		*tmp;

  header->magic = COREWAR_EXEC_MAGIC;
  create_header(header, fd, lst);
  tmp = lst;
  while (tmp != NULL)
    {
      if (tmp->type == 1)
	write_instruction(tmp->data, fd, tmp->line, lst);
      tmp = tmp->next;
    }
  _my_assembling_msg(header, file);
}
