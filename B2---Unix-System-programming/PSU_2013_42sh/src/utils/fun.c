/*
** fun.c for fun in /home/mar_b/rendu/PSU_2013_42sh
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep  2 14:13:43 2014 mar_b mar_b
** Last update Mon Sep  8 12:39:39 2014 charles viterbo
*/

/*
** brief: it will initialize our buf
** @buf: our char * we want to init.
** @size: our size
*/
void	my_init(char *buf, int size)
{
  int	i;

  i = -1;
  while (++i < size)
    buf[i] = '\0';
}
