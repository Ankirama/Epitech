/*
** nbr.c for nbr in /root/rendu/CPE_2014_corewar/asm
**
** Made by
** Login   <-n@epitech.net>
**
** Started on  Sun Aug 10 12:08:01 2014
** Last update Wed Oct  1 18:05:16 2014 zighed_a zighed_a
*/

#include <unistd.h>
#include "utils.h"

static void	_my_putchar(const int fd, const char c)
{
  (void)write(fd, &c, 1);
}

static char	_check_nbr(const char *str)
{
  int		i;

  i = (str[0] == '-') ? 0 : -1;
  if (str[0] == '-' && str[i] == '\0')
    {
      (void)write(2, "error: '", my_strlen("error: '"));
      (void)write(2, str, my_strlen(str));
      (void)write(2, ERR_NBR, my_strlen(ERR_NBR));
      return (-1);
    }
  while (str[++i])
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  (void)write(2, "error: '", my_strlen("error: '"));
	  (void)write(2, str, my_strlen(str));
	  (void)write(2, ERR_NBR, my_strlen(ERR_NBR));
	  return (-1);
	}
    }
  return (0);
}

/*
** brief: Like ATOI
** @str: we will convert this string to an integer
** @error: if str isn't a valid number then we will set it
** return: it will return the new integer or -1 and set error if any error
*/
int	my_getnbr(const char *str, char *error)
{
  int	i;
  int	nbr;

  if (_check_nbr(str) == -1)
    {
      *error = 1;
      return (-1);
    }
  i = (str[0] == '-') ? 0 : -1;
  nbr = 0;
  if (str[0] == '-')
    {
      while (str[++i] && nbr <= 0)
	nbr = nbr * 10 + (str[i] - '0');
    }
  else
    {
      while (str[++i] && nbr >= 0)
	nbr = nbr * 10 + (str[i] - '0');
    }
  return (nbr);
}

/*
** brief: print a number (positif) into a fd
** @nbr: our number
** @fd: our file descriptor
*/
void	my_putnbr(int nbr, const int fd)
{
  if (nbr < 10)
    _my_putchar(fd, nbr + '0');
  else
    {
      my_putnbr(nbr / 10, fd);
      _my_putchar(fd, (nbr % 10) + '0');
    }
}
