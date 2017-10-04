/*
** colle.c for colle in /home/mar_b/rendu/Piscine-C-colles-Semaine_02
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat Mar 15 13:03:03 2014 Fabien Martinez
** Last update Sun Mar 16 08:15:19 2014 Fabien Martinez
*/

int	my_loop(char *str, int size)
{
  int	pos_star;
  int	pos_max;
  int	pos_word;
  int	reverse;

  reverse = 0;
  while (str[0] != 0)
    {
      if (reverse == 0)
	{
	  reverse = my_main_loop(str, size);
	}
      else
	{
	  reverse = my_main_rev_loop(str, size);
	  str = &str[1];
	}
    }
  usleep(50000);
  if (reverse == 0)
    my_putstr(my_newstr("", 0, 0, size));
  else
    my_putstr(my_revnewstr("", 1, 0, size));
}

char	verif_space(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] == ' ')
    i = i + 1;
  return (str[i] == '\0');
}

int	main(int argc, char **argv)
{
  int	nbr;

  if (argc != 3)
    {
      my_putstr("Usage : colle2-5 text size\n");
    }
  else
    {
      nbr = my_getnbr(argv[2]);
      if (my_strlen(argv[1]) < 1 || verif_space(argv[1]))
	my_putstr("String too small or only space(s)");
      else if (my_strlen(argv[1]) + 3 > nbr)
	my_putstr("Size too small\n");
      else
	my_loop(argv[1], nbr);
    }
}
