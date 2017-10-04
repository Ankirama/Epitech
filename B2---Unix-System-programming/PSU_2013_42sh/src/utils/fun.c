/*
** fun.c for fun in /home/user/rendu/PSU_2013_42sh
**
** Made by 
** Login   
**
** Started on  Tue Sep  2 14:13:43 2014 
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
