/*
** my_loop.c for my_loop in /home/mar_b/rendu/Piscine-C-colles-Semaine_02
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat Mar 15 18:06:59 2014 Fabien Martinez
** Last update Sun Mar 16 08:15:02 2014 Fabien Martinez
*/

char	*my_newstr(char *str, int pos_star, int pos_word, int size);

int     my_loopstar(char *str, int position_max, int position_word, int size)
{
  int   position_star;

  position_star = 0;
  while (position_star < position_max)
    {
      my_putstr(my_newstr(str, position_star, position_word, size));
      usleep(50000);
      my_putchar('\r');
      position_star = position_star + 1;
    }
  return (position_star);
}

int	my_mid_display(char *str, int *pos_max, int *pos_word, int size)
{
  int	position_star;

  position_star = my_loopstar(str, *pos_max, *pos_word, size);
  *pos_max = *pos_max + 1;
  my_putstr(my_newstr(str, position_star, *pos_word, size));
  usleep(50000);
  my_putchar('\r');
  *pos_word = *pos_word + 1;
  my_putstr(my_newstr(str, position_star - 1, *pos_word, size));
  usleep(50000);
  position_star = *pos_max - 3;
  my_putchar('\r');
  return (position_star);
}

int	my_back_display(char *str, int pos_star, int position_word, int size)
{
  int	position_star;

  position_star = pos_star;
  while (position_star > 0)
    {
      my_putstr(my_newstr(str, position_star, position_word, size));
      usleep(50000);
      my_putchar('\r');
      position_star = position_star - 1;
    }
  return (position_star);
}

int	my_main_loop(char *str, int size)
{
  int	pos_star;
  int	pos_max;
  int	pos_word;
  int	reverse;
  int	length;

  reverse = 0;
  pos_max = 0;
  pos_word = 1;
  length = my_strlen(str);
  while (reverse == 0)
    {
      pos_star = my_mid_display(str, &pos_max, &pos_word, size);
      pos_star = my_back_display(str, pos_star, pos_word, size);
      if (my_newstr(str, 0, pos_word, size)[size - 3] == str[length - 1])
        {
          my_loopstar(str, pos_max, pos_word, size);
          str[my_strlen(str) - 1] = '\0';
	  reverse = 1;
        }
    }
  return (1);
}
