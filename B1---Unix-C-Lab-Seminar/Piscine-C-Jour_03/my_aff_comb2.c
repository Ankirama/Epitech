/*
** my_aff_comb2.c for my_aff_comb2 in /home/mar_b/rendu/Piscine-C-Jour_03
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Wed Mar  5 10:41:53 2014 Fabien Martinez
** Last update Thu Mar  6 08:49:42 2014 Fabien Martinez
*/

int	my_display_comb2(char a, char b)
{
  my_putchar('0' + (a / 10));
  my_putchar('0' + (a % 10));
  my_putchar(' ');
  my_putchar('0' + (b / 10));
  my_putchar('0' + (b % 10));
}

int	my_aff_comb2()
{
  char	a;
  char	b;
  
  a = 0;
  while (a < 99)
    {
      b = 0;
      while (b <= 99)
	{
	  if (a < b)
	    {
	      my_display_comb2(a, b);
	      if (a != 98)
		{
		  my_putchar(',');
		  my_putchar(' ');
		}
	    }
	  b += 1;
	}
      a += 1;
    }
}
