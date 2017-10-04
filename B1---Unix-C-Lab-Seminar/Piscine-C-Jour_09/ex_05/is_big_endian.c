/*
** is_big_endian.c for is_big_endian in /home/mar_b/rendu/Piscine-C-Jour_09/ex_05
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Mar 13 17:01:23 2014 Fabien Martinez
** Last update Fri Mar 14 19:50:36 2014 Fabien Martinez
*/

int	is_big_endian(void)
{
  int	i;
  char	*conv_i;

  i = 1;
  conv_i = (char*)&i;
  return (!*conv_i == 1);
}
