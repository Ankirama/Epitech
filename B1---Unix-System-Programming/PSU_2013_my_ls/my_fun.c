/*
** my_fun.c for my_fun in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Apr 23 23:16:47 2014 Fabien Martinez
** Last update Fri May  2 19:06:16 2014 Fabien Martinez
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "my_file.h"
#include "my_fun.h"
#include "my_path.h"
#include "my_ls.h"

/*
** This function will compare 2 string and return -X if s2 > s1
** or s1 > s2 (reverse). if the char is < 0 or > z --> increment
*/
int	my_strcmp_name(char *s1, char *s2, char reverse)
{
  int	i;
  int	j;
  char	diff;
  char	c1;
  char	c2;

  i = 0;
  j = 0;
  diff = 0;
  c1 = s1[0];
  c2 = s2[0];
  while (s1[i] && s2[j] && diff == 0)
    {
      c1 = s1[i] >= 'A' && s1[i] <= 'Z' ? s1[i] + 32 : s1[i];
      c2 = s2[j] >= 'A' && s2[j] <= 'Z' ? s2[j] + 32 : s2[j];
      if ((s1[i] < '0' || s1[i] > 'z'))
	c1 = s1[++i];
      if ((s2[j] < '0' || s2[j] > 'z'))
	c2 = s2[++j];
      diff = c1 == c2 ? 0 : 1;
      i += 1;
      j += 1;
    }
  return (reverse ? c2 - c1 : c1 - c2);
}

/*
** This function will compare time modification
*/
static int	my_strcmp_time(time_t t1, time_t t2, char reverse)
{
  if (reverse)
    {
      if (t1 < t2)
	return (-1);
      if (t1 > t2)
	return (1);
      return (0);
    }
  if (t1 < t2)
    return (1);
  if (t1 > t2)
    return (-1);
  return (0);
}

/*
** This function will compare the size
*/
static int	my_strcmp_size(off_t s1, off_t s2, char reverse)
{
  if (reverse)
    {
      if (s1 < s2)
	return (-1);
      if (s1 > s2)
	return (1);
      return (0);
    }
  if (s1 < s2)
    return (1);
  if (s1 > s2)
    return (-1);
  return (0);
}

/*
** this function will call the compar function with option
*/
int		my_strcmp(t_my_file *s1, t_my_file *s2, char reverse, char *opt)
{
  struct stat	*buf1;
  struct stat	*buf2;
  int		res;

  if (opt[NOTSORT])
    return (0);
  if ((buf1 = malloc(sizeof(*buf1))) == NULL ||
      (buf2 = malloc(sizeof(*buf2))) == NULL)
    my_puterror();
  if ((lstat(my_pathfile(s1->path, s1->name, '\0'), buf1)) == -1)
    my_puterrno(my_pathfile(s1->path, s1->name, '\0'), errno);
  if ((lstat(my_pathfile(s2->path, s2->name, '\0'), buf2)) == -1)
    my_puterrno(my_pathfile(s2->path, s2->name, '\0'), errno);
  if (opt[TIME])
    res = my_strcmp_time(buf1->st_mtime, buf2->st_mtime, reverse);
  else if (opt[SIZE])
    res = my_strcmp_size(buf1->st_size, buf2->st_size, reverse);
  else
    res = my_strcmp_name(s1->name, s2->name, reverse);
  free(buf1);
  free(buf2);
  return (res);
}
