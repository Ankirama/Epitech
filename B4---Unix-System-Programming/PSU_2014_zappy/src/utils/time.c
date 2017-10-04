/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 19:03:48 2015 CHARLES VITERBO
*/

/*
** @file time.c
** @brief function about time ellapsed etc...
** @author ankirama
** @version 0.1
*/

#include "utils.h"

/*
** @brief Difference between 2 timeval
**
** @param start first timeval
** @param finish second timeval
** @return difference between start and finish (finish - start)
*/
long	time_diff(t_my_timeval *start, t_my_timeval *finish)
{
  long	msec;

  msec = (finish->tv_sec - start->tv_sec) * 1000;
  msec += (finish->tv_usec - start->tv_usec) / 1000;
  return (msec);
}

/*
** @brief check gettimeofday and exit if any error
**
** @param timeval try to set this timeval
*/
void	my_gettimeofday(t_my_timeval *timeval)
{
  if (gettimeofday(timeval, NULL) == -1)
    {
      cmd_log(strerror(errno), "my_gettimeofday", xdate(), TYPE_ERROR);
      errno = 0;
      my_exit(0);
    }
}

/*
** @brief check if we are time more far
**
** In milliseconds
**
** @param start struct when we exec our command
** @param time time we want to wait (in milliseconds)
** @return 1 if it's ok, else 0 (-1 if any error)
*/
int		is_time_elapsed(t_my_timeval *start, long time)
{
  t_my_timeval	finish;
  long		res;

  if (time == -1)
    return (1);
  if (gettimeofday(&finish, NULL) == -1)
    {
      cmd_log(strerror(errno), "is_time_elapsed", xdate(), TYPE_ERROR);
      errno = 0;
      return (-1);
    }
  res = time_diff(start, &finish);
  return (res >= time ? 1 : 0);
}

/*
** @brief get current date format : 2001-04-13 11:11:11
**
** @return NULL if any error, else date string
*/
char		*xdate()
{
  t_my_timeval	tv;
  struct tm	*ptm;
  char		*date;

  if (!(date = my_malloc(sizeof(char) * 20)))
    return (NULL);
  if (gettimeofday(&tv, NULL) == -1)
    {
      free(date);
      return (NULL);
    }
  if ((ptm = localtime(&tv.tv_sec)) == NULL)
    {
      free(date);
      return (NULL);
    }
  if (!strftime(date, 20, "%Y-%m-%d %H:%M:%S", ptm))
    {
      free(date);
      return (NULL);
    }
  return (date);
}

/*
** @brief set our timeout
**
** @param timeval the time value
** @param sec number of seconds
** @param usrc number of milliseconds
*/
void	set_timeout(struct timeval *timeval, time_t sec, suseconds_t usec)
{
  timeval->tv_sec = sec;
  timeval->tv_usec = usec;
}
