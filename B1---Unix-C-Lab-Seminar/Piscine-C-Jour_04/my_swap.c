/*
** my_swap.c for my_swap in /home/mar_b/rendu/Piscine-C-Jour_04
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Thu Mar  6 09:09:34 2014 Fabien Martinez
** Last update Thu Mar  6 09:45:26 2014 Fabien Martinez
*/

int	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *b;
  *b = *a;
  *a = tmp;
}
