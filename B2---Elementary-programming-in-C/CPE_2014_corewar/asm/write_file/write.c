/*
** write.c for write_file in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Aug 21 13:21:02 2014 mar_b mar_b
** Last update Sun Aug 31 20:45:47 2014 mar_b mar_b
*/

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

static void	_my_putchar(const int fd, const unsigned char c)
{
  if (write(fd, &c, 1) == -1)
    exit(EXIT_FAILURE);
}

/*
** brief: it will write into our file the decimal
** @fd: our file descriptor
** @value: our decimal
** @i: between 0 and 24
** @max: the number of bits max
*/
void	write_int(const int fd, unsigned int value, unsigned char i,
		  const int max)
{
  if (i == max)
    {
      if (((value >> i) & 0xFF) != 0)
	_my_putchar(fd, (value >> i) & 0xFF);
      else
	my_lseek(fd, 1, SEEK_CUR);
    }
  else
    {
      write_int(fd, value, i + 8, max);
      if (((value >> i) & 0xFF) != 0)
	_my_putchar(fd, (value >> i) & 0xFF);
      else
	my_lseek(fd, 1, SEEK_CUR);
    }
}

void	write_int_neg(const int fd, unsigned int value,
		      unsigned char i, const int max)
{
  if (i == max)
    {
      if (((value >> i) & 0xFF) != 0)
	_my_putchar(fd, (value >> i) & 0xFF);
      else
	_my_putchar(fd, 255);
    }
  else
    {
      write_int_neg(fd, value, i + 8, max);
      if (((value >> i) & 0xFF) != 0)
	_my_putchar(fd, (value >> i) & 0xFF);
      else
	_my_putchar(fd, 0);
    }
}

/*
** brief: it will write into our file the string
** @fd: our file descriptor
** @str: our message
** @max_size: used for fill the good size
** @file: our file for error
*/
void	write_str(const int fd, const char *str, const int max_size)
{
  int	size;

  size = my_strlen(str);
  my_write(fd, str, size);
  my_lseek(fd, max_size - size, SEEK_CUR);
}
