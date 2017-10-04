/*
** who.c for who in /home/mar_b/rendu/Piscine-C-Jour_13/who
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Mar 26 19:20:53 2014 Fabien Martinez
** Last update Thu Mar 27 11:36:57 2014 Fabien Martinez
*/

#include <errno.h>
#include <utmp.h>
#include <time.h>
#include <sys/types.h>
#include <fcntl.h>
#include "my.h"
#include "my_perror.h"
#include "my_print_error.h"

void	my_display_time(time_t t)
{
  my_put_nbr(1970 + t / 31536000);
  my_putchar('-');
  t = t % 31536000;
  if (t / 2628000 < 10)
    my_putchar('0');
  my_put_nbr(t / 2628000);
  my_putchar('-');
  t = t % 604800;
  my_put_nbr(22 + t / 86400);
  my_putchar(' ');
  t = t % 86400;
  if (1 + t / 3600 >= 24)
    my_putstr("00");
  else
    {
      if (1 + t / 3600 < 10)
	my_putchar('0');
      my_put_nbr(1 + t / 3600);
    }
  my_putchar(':');
  t = t % 3600;
  if (t / 60 < 10)
    my_putchar('0');
  my_put_nbr(t / 60);
}

char	my_display_struct(struct utmp *my_utmp, int fd, int bytes)
{
  char	buffer[80];

  if (bytes == -1)
    {
      my_print_error(errno, "read");
      close(fd);
      return (1);
    }
  else if (my_utmp->ut_type == USER_PROCESS && bytes != 0)
    {
      my_putstr(my_utmp->ut_name);
      my_putstr("    ");
      my_putstr(my_utmp->ut_line);
      my_putstr("\t      ");
      if (my_utmp->ut_time == -1)
	return (1);
      my_display_time(my_utmp->ut_time);
      my_putstr(" (");
      my_putstr(my_utmp->ut_host);
      my_putstr(")\n");
    }
  return (0);
}

int		main(int argc, char **argv)
{
  struct utmp	*my_utmp;
  int		fd;
  int		bytes;

  (void)argv;
  if (argc != 1)
    {
      my_putstr("You have not to specifie arguments\n");
      return (1);
    }
  fd = open(UTMP_FILE, O_RDONLY);
  if (fd == -1)
    {
      my_print_error(errno, "read");
      return (1);
    }
  bytes = 1;
  while (bytes > 0)
    {
      bytes = read(fd, my_utmp, sizeof(*my_utmp));
      if (my_display_struct(my_utmp, fd, bytes) == 1)
	return (1);
    }
  close(fd);
  return 0;
}
