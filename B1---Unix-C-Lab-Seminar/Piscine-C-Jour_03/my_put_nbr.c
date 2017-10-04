/*
** my_put_nbr.c for my_put_nbr in /home/user/rendu/Piscine-C-Jour_03
** 
** Made by 
** Login   
** 
** Started on  Wed Mar  5 11:17:38 2014 
** Last update Thu Mar  6 08:52:20 2014 
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
