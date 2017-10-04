/*
** my_put_nbr.c for my_put_nbr in /home/mar_b/rendu/Piscine-C-Jour_03
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Wed Mar  5 11:17:38 2014 Fabien Martinez
** Last update Thu Mar  6 08:52:20 2014 Fabien Martinez
*/

int	rec_my_put_nbr(int nbr)
{
   if (nbr <= 9)
    {
      my_putchar('0' + nbr);
    }
  else
    {
      my_put_nbr(nbr / 10);
      my_putchar ('0' + (nbr % 10));
    }
}

int	my_put_nbr(int nbr)
{
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = nbr * (-1);
    }
  rec_my_put_nbr(nbr);
}
