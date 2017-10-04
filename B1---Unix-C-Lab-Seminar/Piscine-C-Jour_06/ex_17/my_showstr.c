 /*
** my_showstr.c for my_showstr in /home/mar_b/rendu/Piscine-C-Jour_06/ex_17
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 19:25:33 2014 Fabien Martinez
** Last update Tue Mar 11 08:26:00 2014 Fabien Martinez
*/

void	my_char_to_hexa(char c)
{
  if (c / 16 == 0)
    {
      if (c % 16 >= 10)
	my_putchar(c % 16 - 10 + 'a');
      else
	my_putchar('0' + c % 16);
    }
  else
    {
      if ((c / 16) >= 10)
	my_putchar((c / 16) - 10 + 'a');
      else
	my_putchar('0' + c / 16);
      my_char_to_hexa(c % 16);
    }
}

int	my_showstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= ' ' && str[i] <= '~')
	my_putchar(str[i]);
      else
	{
	  my_putchar('\\');
	  if (str[i] < 16)
	    my_putchar('0');
	  my_char_to_hexa(str[i]);
	}
      i += 1;
    }
  return (0);
}
