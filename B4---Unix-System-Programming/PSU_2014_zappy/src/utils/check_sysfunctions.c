/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sat Feb 21 19:30:29 2015 Fabien Martinez
*/

/*
** @file check_sysfunctions.c
** @brief basic functions with check error and exit
** @author ankirama
** @version 1.0
*/

#include "utils.h"

/*
** @brief close like with error check
**
** @param fd file descriptor to close
*/
void	my_close(int fd)
{
  if (close(fd) == -1)
    cmd_log(strerror(errno), "my_close", xdate(), TYPE_ERROR);
}

/*
** @brief read like with error check
**
** @param fd file descriptor
** @param buf buffer
** @param size size to read
** @return -1 if error, else length rode
*/
ssize_t	my_read(int fd, void *buf, size_t size)
{
  int	len;

  if ((len = read(fd, buf, size)) == -1)
    {
      cmd_log(strerror(errno), "my_read", xdate(), TYPE_ERROR);
      return (-1);
    }
  return (len);
}

/*
** @brief write like with error check
**
** @param fd file descriptor to write
** @param buf string to write
** @param size to write
** @return -1 if error else size wrote
*/
ssize_t	my_write(int fd, const void *buf, size_t size)
{
  int	len;

  if ((len = write(fd, buf, size)) == -1)
    {
      cmd_log(strerror(errno), "my_write", xdate(), TYPE_ERROR);
      return (-1);
    }
  return (len);
}

/*
** @brief malloc like with check error
**
** exit if any error
**
** @param size size to malloc
** @return pointer to allocated area
*/
void	*my_malloc(size_t size)
{
  void	*p;

  if (!(p = malloc(size)))
    {
      cmd_log(ERR_MALLOC, "my_malloc", xdate(), TYPE_ERROR);
      return (NULL);
    }
  return (p);
}

/*
** @brief strdup like with error check
**
** exit if any error
**
** @param s string to copy
** @return new string
*/
char	*my_strdup(const char *s)
{
  char	*new;

  new = strdup(s);
  if (new == NULL)
    {
      cmd_log("Problem with strdup", "my_write", xdate(), TYPE_ERROR);
      return (NULL);
    }
  return (new);
}
