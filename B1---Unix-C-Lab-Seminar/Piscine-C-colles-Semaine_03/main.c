/*
** main.c for main in /home/mar_b/rendu/Piscine-C-colles-Semaine_03
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat Mar 29 00:09:57 2014 Fabien Martinez
** Last update Sun Mar 30 03:15:18 2014 Fabien Martinez
*/

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "my_proto.h"
#include "my.h"

char	my_width(char *str, int *width, char *my_coin)
{
  int	i;

  i = 0;
  while (str[i] != 0 && str[i] != '\n')
    {
      *width += 1;
      i += 1;
    }
  if (*width < 0)
    {
      *width = 0;
      return (1);
    }
  if (str[i] == '\n')
    {
      if (i > 0)
	my_coin[1] = str[i - 1];
      return (1);
    }
  return (0);
}

int	my_height(char *str, int height)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == '\n')
	height += 1;
      i += 1;
    }
  return (height);
}

int	my_loop(char *my_coin, int *width, int *height)
{
  char		buff[BUFF_SIZE + 1];
  int		len;
  char		width_done;
  char		first_carac_read;

  len = init_variables(height, width, &width_done, &first_carac_read);
  while (len != 0)
    {
      my_init(&buff[0]);
      if ((len = read(0, buff, BUFF_SIZE)) > 0)
	{
	  if (first_carac_read == 0)
	    {
	      my_coin[0] = buff[0];
	      first_carac_read = 1;
	    }
	  if (width_done == 0 && my_width(&buff[0], width, &my_coin[0]))
	    width_done = 1;
	  *height = *width == 0 ? 0 : (my_height(&buff[0], *height));
	  my_coin[2] = buff[len - 2];
	}
      else if (len == -1)
	return (my_print_error(errno, "./colle3: "));
    }
  return (0);
}

int		main(int argc, char **argv)
{
  char	my_coin[3];
  int	width;
  int	height;

  (void)argc;
  (void)argv;
  if (my_loop(&my_coin[0], &width, &height) == 1)
    return (1);
  if (width < 0 || height < 0)
    {
      my_putstr("Error: BUG\n");
      return (1);
    }
  my_colle(&my_coin[0], width, height);
  if (width == height && width > 0)
    {
      my_display_str(" || [square] ", width, height);
    }
  if (width > 0 && height > 0)
    {
      my_display_str(" || [rectangle] ", width, height);
    }
  my_putchar('\n');
  return (0);
}
