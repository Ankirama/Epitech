/*
** is_big_endian.c for is_big_endian in /home/user/rendu/Piscine-C-Jour_09/ex_05
**
** Made by 
** Login   
**
** Started on  Thu Mar 13 17:01:23 2014 
** Last update Fri Mar 14 19:50:36 2014 
*/

int	is_big_endian(void)
{
  int	i;
  char	*conv_i;

  i = 1;
  conv_i = (char*)&i;
  return (!*conv_i == 1);
}
