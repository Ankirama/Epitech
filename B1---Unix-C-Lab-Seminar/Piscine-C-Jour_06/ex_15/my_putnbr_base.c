/*
** my_putnbr_base.c for my_putnbr_base in /home/mar_b/rendu/Piscine-C-Jour_06/ex_15
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 14:05:01 2014 Fabien Martinez
** Last update Mon Mar 10 16:17:06 2014 Fabien Martinez
*/

void	my_real_function(int nbr, char *base, int len)
{
  if (nbr / len == 0)
    my_putchar(base[nbr]);
  else
    {
      my_real_function(nbr / len, base, len);
      my_putchar(base[nbr % len]);
    }
}

int	my_putnbr_base(int nbr, char *base)
{
  int	base_len;

  base_len = 0;
  while (base[base_len] != '\0')
    {
      base_len += 1;
    }
  if (nbr < 0)
    my_putchar('-');
  my_real_function(nbr, base, base_len);
}
