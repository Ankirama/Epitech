/*
** nbr.c for nbr in /root/rendu/CPE_2014_corewar/asm
**
** Made by
** Login   <-n@epitech.net>
**
** Started on  Sun Aug 10 12:08:01 2014
** Last update Sun Aug 24 21:29:05 2014 chenev_d chenev_d
*/

#include "utils.h"

static void	_check_nbr(const char *str)
{
  int		i;

  i = (str[0] == '-') ? 0 : -1;
  if (str[0] == '-' && str[i] == '\0')
    {
      my_write(2, "error: '", my_strlen("error: '"));
      my_write(2, str, my_strlen(str));
      my_puterror("' is not valid number !\n");
    }
  while (str[++i])
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  my_write(2, "error: '", my_strlen("error: '"));
	  my_write(2, str, my_strlen(str));
	  my_puterror("' is not valid number !\n");
	}
    }
}

/*
** brief: Like ATOI
** @str: we will convert this string to an integer
** return: it will return the new integer
*/
int	my_getnbr(const char *str)
{
  int	i;
  int	nbr;

  _check_nbr(str);
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
    my_putchar(fd, nbr + '0');
  else
    {
      my_putnbr(nbr / 10, fd);
      my_putchar(fd, (nbr % 10) + '0');
    }
}
