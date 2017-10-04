/*
** fun.c for fun in /root/rendu/CPE_2014_corewar/asm
**
** Made by
** Login   <-n@epitech.net>
**
** Started on  Sat Aug  9 14:10:09 2014
** Last update Tue Aug 26 11:35:55 2014
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "utils.h"

/*
** brief: like lseek but check if any error
** @fd: our file descriptor
** @str: our str
** @size: size of the str
*/
void	my_write(int fd, const char *str, int size)
{
  if (write(fd, str, size) != size)
    exit(EXIT_FAILURE);
}

/*
** brief: like lseek but check if any error
** @fd: our file descriptor
** @offset: the size
** @whence: for example SEEK_CUR etc...
** @file: used for the error
*/
void	my_lseek(const int fd, off_t offset, int whence)
{
  if (lseek(fd, offset, whence) == -1)
    my_puterror("error: problem with lseek !\n");
}

/*
** brief: like open but check any error
** @pathname: the file we want to open
** @flags: flags like O_CREAT, O_WRONLY, O_RDONLY...
** @mode: permissions for create a file
** return: return the file descriptor
*/
int	my_open(const char *pathname, int flags, mode_t mode)
{
  int	fd;

  if ((fd = open(pathname, flags, mode)) == -1)
    my_error(pathname, " not accessible\n");
  return (fd);
}

/*
** brief: like close but check any error
** @fd: our file descriptor we want to close
** @str: used for the error
*/
void	my_close(const int fd, const char *str)
{
  if (close(fd) == -1)
    my_error(str, " can't be close\n");
}

void	*my_malloc(size_t size)
{
  void	*data;

  if ((data = malloc(size)) == NULL)
    my_puterror("Can't perform malloc\n");
  return (data);
}
