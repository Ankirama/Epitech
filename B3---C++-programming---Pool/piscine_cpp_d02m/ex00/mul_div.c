/*
** mul_div.c for here we go in /home/user/rendu/piscine_cpp_d02m/ex00
**
** Made by 
** Login   
**
** Started on  Thu Jan  8 09:48:44 2015 
** Last update Thu Jan  8 09:58:07 2015 
*/

void	add_mul_4param(int first, int second, int *add, int *mul)
{
  *add = first + second;
  *mul = first * second;
}

void	add_mul_2param(int *first, int *second)
{
  *first = *first + *second;
  *second = (*first - *second) * *second;
}
