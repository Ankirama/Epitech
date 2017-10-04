/*
** my_aff_comb.c for my_aff_comb in /home/mar_b/rendu/Piscine-C-Jour_03
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Wed Mar  5 10:24:39 2014 Fabien Martinez
** Last update Thu Mar  6 08:50:12 2014 Fabien Martinez
*/

void    my_displaychar(char a, char b, char c)
{
  my_putchar(a);
  my_putchar(b);
  my_putchar(c);
  my_putchar(',');
  my_putchar(' ');
}

void	my_triplechar(char a, char b, char c)
{
  my_putchar(a);
  my_putchar(b);
  my_putchar(c);
}

int	my_try_display(char a, char b, char c)
{
  if (a == '7' && a < b && b < c)
    my_triplechar(a, b, c);
  else
    {
      if (a < b && b < c)
	{
	  my_displaychar(a, b, c);
	}
    }	      
}

int	my_aff_comb()
{
  char	a;
  char	b;
  char	c;

  a = '0';
  while (a <= '7')
    {
      b = '0';
      while (b <= '8')
	{
	  c = '0';
	  while (c <= '9')
	    {
	      my_try_display(a, b, c);
	      c += 1;
	    }
	  b += 1;
	}
      a += 1;
    }
  return (0);
}
