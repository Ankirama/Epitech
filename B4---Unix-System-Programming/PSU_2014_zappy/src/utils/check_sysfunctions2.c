/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 18:56:26 2015 CHARLES VITERBO
*/

/*
** @file check_sysfunctions2.c
** @brief log functions
** @author ankirama
** @vesion 1.0
*/

#include "utils.h"

/*
** @brief recode of calloc function and send to log
**
** @param count number of elements
** @param size
**
** @return NULL if error else the pointeur
*/
void	*my_calloc(size_t count, size_t size)
{
  void	*ptr;

  if (!(ptr = calloc(count, size)))
    {
      cmd_log("Unable to calloc", "my_calloc", xdate(), TYPE_ERROR);
      return (NULL);
    }
  return (ptr);
}

/*
** @brief recode of open function and send to log
**
** @param pathname the file's path
** @param flags flags for open
**
** @return -1 if error else fd
*/
int	my_open(const char *pathname, int flags)
{
  int	fd;

  if ((fd = open(pathname, flags, 0666) == -1))
    {
      cmd_log(strerror(errno), "my_open", xdate(), TYPE_ERROR);
      return (-1);
    }
  return (fd);
}

/*
** @brief recode of exit function and send to log
**
** @param status value of exit
*/
void	my_exit(int status)
{
  close_log_file();
  exit(status);
}
