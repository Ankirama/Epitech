/*
** my_revloop.c for my_revloop in /home/mar_b/rendu/Piscine-C-colles-Semaine_02
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat Mar 15 21:26:09 2014 Fabien Martinez
** Last update Sun Mar 16 01:02:38 2014 Fabien Martinez
*/

char	*my_revnewstr(char *str, int pos_star, int pos_word, int size);

int     my_revloopstar(char *str, int pos_max, int pos_word, int size)
{
  int   position_star;

  position_star = 1;
  while (position_star < pos_max)
    {
      my_putstr(my_revnewstr(str, position_star, pos_word, size));
      usleep(50000);
      my_putchar('\r');
      position_star = position_star + 1;
    }
  return (position_star);
}

int     my_revmid_display(char *str, int *pos_max, int *pos_word, int size)
{
  int   position_star;

  position_star = my_revloopstar(str, *pos_max, *pos_word, size);
  *pos_max = *pos_max + 1;
  my_putstr(my_revnewstr(str, position_star, *pos_word, size));
  usleep(50000);
  my_putchar('\r');
  *pos_word = *pos_word + 1;
  my_putstr(my_revnewstr(str, position_star - 1, *pos_word, size));
  usleep(50000);
  position_star = *pos_max - 3;
  my_putchar('\r');
  return (position_star);
}

int	my_revback_display(char *str, int pos_star, int pos_word, int size)
{
  int	position_star;

  position_star = pos_star;
  while (position_star > 0)
    {
      my_putstr(my_revnewstr(str, position_star, pos_word, size));
      usleep(50000);
      my_putchar('\r');
      position_star = position_star - 1;
    }
  return (position_star);
}

int	my_main_rev_loop(char *str, int size)
{
  int	pos_star;
  int	pos_max;
  int	pos_word;
  int	reverse;

  reverse = 1;
  pos_max = 0;
  pos_word = 1;
  while (reverse == 1)
    {
      pos_star = my_revmid_display(str, &pos_max, &pos_word, size);
      pos_star = my_revback_display(str, pos_star, pos_word, size);
      if (my_revnewstr(str, 0, pos_word, size)[0] == str[0])
	{
	  my_revloopstar(str, pos_max, pos_word, size);
	  reverse = 0;
	}
    }
  return (0);
}
