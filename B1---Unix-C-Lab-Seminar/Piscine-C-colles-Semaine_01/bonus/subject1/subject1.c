/*
** subject1.c for subject_1 in /home/mar_b/rendu/Piscine-C-colles-Semaine_01
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Sat Mar  8 14:32:58 2014 Fabien Martinez
** Last update Sat Mar  8 18:59:15 2014 Fabien Martinez
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_char_display(char c, int i, int x, int y)
{
  if ((i == 0 || i == (x - 1)) && x > 0 && y > 0)
    my_putchar(c);
  else
    my_putchar('-');
}

void	my_main_loop(int x, int y)
{
  int	i;
  int	j;

  j = 0;
  while (j < y)
    {
      i = 0;
      while (i < x)
	{
	  if (j == 0 || j == (y - 1))
	    my_char_display('o', i, x, y);
          else
	    {
	      if (i == 0 || i == (x - 1))
		my_putchar('|');
	      else
		my_putchar(' ');
	    }
	  i += 1;
	}
      j += 1;
      my_putchar('\n');
    }
}

void	colle(int x, int y)
{
  if (x <= 0 || y <= 0)
    my_putchar('\n');
  else
    my_main_loop(x, y);
}

int	main()
{
  colle(-130, 24);
  return (0);
}
