/*
** my_swap.c for my_swap in /home/user/rendu/Piscine-C-Jour_04
** 
** Made by 
** Login   
** 
** Started on  Thu Mar  6 09:09:34 2014 
** Last update Thu Mar  6 09:45:26 2014 
*/

int	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *b;
  *b = *a;
  *a = tmp;
}
