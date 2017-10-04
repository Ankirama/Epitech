/*
** write_commands.c for write_commands in /root/rendu/CPE_2014_corewar/asm
**
** Made by
** Login   <-n@epitech.net>
**
** Started on  Sun Aug 24 19:20:13 2014
** Last update Sun Aug 31 12:28:21 2014
*/

#include <stdlib.h>
#include "write_file.h"
#include "utils.h"
#include "op.h"

/*
** brief: it will write our direct value into our file
** @str: our current value like "%42"
** @fd: our file descriptor
** @line: our line if any error
*/
static void	_write_direct(const char *str, const int fd, const int line,
			      t_asm *head)
{
  char		error;
  int		nbr;
  unsigned int	max_value;

  max_value = my_pow(2, DIR_SIZE * 8);
  if (str[1] != LABEL_CHAR)
    {
      nbr = my_getnbr_asm(&str[1], &error);
      if (error || (DIR_SIZE < 4 &&
		    ((nbr >= 0 && nbr > my_pow((DIR_SIZE * 8) - 1, 2) - 1) ||
		     ((nbr < 0 && nbr < my_pow((DIR_SIZE * 8) - 1, 2) * -1)))))
	my_warning(ERR_DIR, line);
      if (nbr >= 0)
	write_int(fd, (unsigned int)nbr, 0, DIR_SIZE * 8 - 8);
      else
	write_int_neg(fd, max_value + nbr, 0, DIR_SIZE * 8 - 8);
    }
  else
    {
      if ((nbr = my_label(head, line, &str[2])) >= 0)
	write_int(fd, (unsigned int)nbr, 0, DIR_SIZE * 8 - 8);
      else
	write_int_neg(fd, max_value + nbr, 0, DIR_SIZE * 8 - 8);
    }
}

/*
** brief: it will write our registery into our file
** @str: our current value like "r2"
** @fd: our file descriptor
*/
static void	_write_reg(const char *str, const int fd)
{
  int		nbr;
  char		error;

  nbr = my_getnbr_asm(&str[1], &error);
  (void)error;
  write_int(fd, nbr, 0, 0);
}

/*
** brief: it will write our indirect value into our file
** @str: our current value like "42"
** @fd: our file descriptor
*/
static void	_write_ind(const char *str, const int fd, const int line,
			   t_asm *head)
{
  int		nbr;
  char		error;
  unsigned int	max_value;

  max_value = my_pow(2, IND_SIZE * 8);
  if ((str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR) || str[0] == LABEL_CHAR)
    {
      if ((nbr = my_label(head, line, (str[0] == DIRECT_CHAR) ?
			  &str[2] : &str[1])) >= 0)
	write_int(fd, (unsigned int)nbr, 0, IND_SIZE * 8 - 8);
      else
	write_int_neg(fd, max_value + nbr, 0, IND_SIZE * 8 - 8);
    }
  else
    {
      nbr = my_getnbr_asm((str[0] == DIRECT_CHAR) ? &str[1] : str, &error);
      if (error || nbr > IDX_MOD || (nbr * -1) > IDX_MOD)
	my_warning(ERR_INDIR, line);
      if (nbr >= 0)
	write_int(fd, (unsigned int)nbr, 0, IND_SIZE * 8 - 8);
      else
	write_int_neg(fd, max_value + nbr, 0, IND_SIZE * 8 - 8);
    }
}

/*
** brief: it will write our "octet de codage"
** @arr: our array with each param to calculate the size
** @fd: file descriptor
*/
static void	_write_codage_byte(char **arr, const int fd)
{
  int		i;
  char		byte;

  i = 0;
  byte = 0;
  while (arr[i] != NULL)
    {
      if (arr[i][0] == DIRECT_CHAR)
	byte += 2 << ((3 - i) * 2);
      else if (arr[i][0] == 'r')
	byte += 1 << ((3 - i) * 2);
      else
	byte += 3 << ((3 - i) * 2);
      ++i;
    }
  write_int(fd, byte, 0, 0);
}

/*
** brief: main_function to write an instruction + param into our file
** @arr: our array with instruction + params
** @fd: file descriptor
** @line: our line number if any error
** @head: the struct where each labels/instru
*/
void	write_instruction(char **arr, const int fd, const int line, t_asm *head)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < 16 && !my_strcmp(arr[0], op_tab[i].mnemonique))
    ++i;
  write_int(fd, op_tab[i].code, 0, 0);
  if (i != 0 && i != 8 && i != 11 && i != 14)
    _write_codage_byte(&arr[1], fd);
  while (arr[++j] != NULL)
    {
      if (arr[j][0] == DIRECT_CHAR && i != 8 && i != 9 && i != 10 && i != 11
	  && i != 14)
	_write_direct(arr[j], fd, line, head);
      else if (arr[j][0] == 'r')
	_write_reg(arr[j], fd);
      else
	_write_ind(arr[j], fd, line, head);
    }
}
