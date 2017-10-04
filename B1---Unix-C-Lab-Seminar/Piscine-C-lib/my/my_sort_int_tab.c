/*
** my_sort_int_tab.c for test in /home/bourde_g/rendu/Library/Library
** 
** Made by Gauthier Bourdenx
** Login   <bourde_g@epitech.net>
** 
** Started on  Mon Mar 24 12:05:24 2014 Gauthier Bourdenx
** Last update Mon Mar 24 12:05:25 2014 Gauthier Bourdenx
*/

void	my_sort_int_tab(int *tab, int size)
{
  int i;
  int j;
  int tmpa;

  i = 0;
  j = 1;
  while (i != (size))
    {
      while (j != (size + 1))
	 {
	   if (tab[i] < tab[j])
	     {
	       tmpa = tab[i];
	       tab[i] = tab[j];
	       tab[j] = tmpa;
	     }
	   j = j + 1;
	 }
      i = i + 1;
      j = 0;
    }
}
