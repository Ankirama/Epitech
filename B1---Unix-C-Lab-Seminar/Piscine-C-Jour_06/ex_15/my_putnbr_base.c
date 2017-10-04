/*
** my_putnbr_base.c for my_putnbr_base in /home/user/rendu/Piscine-C-Jour_06/ex_15
**
** Made by 
** Login   
**
** Started on  Mon Mar 10 14:05:01 2014 
** Last update Mon Mar 10 16:17:06 2014 
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
