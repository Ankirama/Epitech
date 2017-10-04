/*
** main.c for main in /home/mar_b/rendu/colle4_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep 16 19:04:36 2014 mar_b mar_b
** Last update Tue Sep 16 22:32:55 2014 mar_b mar_b
*/

#include <unistd.h>
#include "game_of_life.h"
#include "utils.h"

static int	_get_values(int *x, int *y, int *cells, char **argv)
{
  *x = my_getnbr(argv[1]);
  *y = my_getnbr(argv[2]);
  *cells = my_getnbr(argv[3]);
  return (0);
}

static void	_init_buff(char *buf)
{
  int		i;

  i = -1;
  while (++i <= SIZE_BUF)
    buf[i] = '\0';
}

static int	_getnbr(const char *str)
{
  int		nbr;
  int		i;

  i = 0;
  nbr = 0;
  while (str[i] >= '0' && str[i] <= '9' && nbr >= 0)
    {
      nbr = ((nbr * 10) + (str[i] - '0'));
      i = i + 1;
    }
  if (nbr < 0)
    return (-1);
  else if (str[i] != '\0')
    return (-1);
  return (nbr);
}

static void	_check_nbr(int x, int y, int nbr_cell)
{
  if (x <= 0)
    my_puterror(ERR_X);
  if (y <= 0)
    my_puterror(ERR_Y);
  if (x * y < nbr_cell)
    my_puterror(ERR_NBR_CELL);
}

int	main(int argc, char **argv)
{
  char	buf[SIZE_BUF + 1];
  int	nbr;
  int	x;
  int	y;
  int	cells;
  int	len;
  char	**tab;

  if (argc != 4)
    my_puterror(ERR_ARG);
  nbr = _get_values(&x, &y, &cells, argv);
  _check_nbr(x, y, cells);
  tab = main_tab(x, y, cells);
  my_write(1, MSG_NBR, my_strlen(MSG_NBR));
  _init_buff(buf);
  if ((len = read(0, buf, SIZE_BUF)) > 0)
    {
      buf[len - 1] = '\0';
      nbr = _getnbr(buf);
      if (nbr > 0)
	my_game_of_life(tab, nbr, x + 1, y + 1);
    }
  if (len < 0)
    my_puterror(ERR_READ);
  return (0);
}
