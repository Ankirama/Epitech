/*
** error.c for error in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Aug 21 14:53:24 2014 mar_b mar_b
** Last update Sun Aug 24 13:33:59 2014
*/

#include <stdlib.h>
#include "utils.h"
#include "asm_utils.h"

/*
** brief: it will display the message for a line
** @line: the current line
*/
void	my_error_line(int line)
{
  my_write(2, ERR_LINE, my_strlen(ERR_LINE));
  my_putnbr(line, 2);
  my_putchar(2, '\n');
  exit(EXIT_FAILURE);
}

/*
** brief: display (and exit) a message if we cant find the label
** @label: the unknow label
** @line: the line where the problem occured
*/
void	error_label(const char *label, const int line, const char *str)
{
  my_write(2, "label ", my_strlen("label "));
  my_write(2, label, my_strlen(label));
  my_write(2, ERR_UNDEF, my_strlen(ERR_UNDEF));
  my_putnbr(line, 2);
  my_putchar(2, '\n');
  my_write(2, str, my_strlen(str));
  my_putchar(2, '\n');
  exit(EXIT_FAILURE);
}

/*
** brief: display and error message if the register is > REG_NUMBER
** @line: the line where the problem occured
*/
void	my_error_register(const int line, const char *str)
{
  my_write(2, ERR_REG, my_strlen(ERR_REG));
  my_putnbr(line, 2);
  my_putchar(2, '\n');
  my_write(2, str, my_strlen(str));
  my_putchar(2, '\n');
  exit(EXIT_FAILURE);
}

/*
** brief: display a warning message and dont exit the program
** @err: the message displayed
** @line: the line where the problem occured
*/
void	my_warning(const char *err, const int line)
{
  my_write(2, err, my_strlen(err));
  my_putnbr(line, 2);
  my_putchar(2, '\n');
}
