/*
** fun_2.c for  in /home/teyssa_r/rendu/CPE_2014_corewar/utils
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Sun Aug 17 00:17:03 2014 teyssa_r teyssa_r
** Last update Thu Aug 21 18:14:44 2014 teyssa_r teyssa_r
*/

#include "utils.h"
#include <unistd.h>

/*
** brief: like lseek but check if any error
** @fd: our file descriptor
** @buf: buffer
** @count: size of buffer
*/
int	my_read(int fd, void *buf, size_t count)
{
  int	len;

  if ((len = read(fd, buf, count)) == -1)
    my_puterror("Error : read failure\n");
  return (len);
}
