/*
** my_sort_int_tab.c for my_sort_int_tab in /home/user/rendu/Piscine-C-Jour_04
** 
** Made by 
** Login   
** 
** Started on  Thu Mar  6 13:17:32 2014 
** Last update Thu Mar  6 17:19:02 2014 
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	done;
  int	*ptr;
  int	*ptr2;
  
  done = 1;
  while (done == 1)
    {
      done = 0;
      i = 0;
      while (i < (size - 1))
	{
	  if (*(tab + i) > *(tab + i + 1))
	    {
	      done = 1;
	      ptr = &(*(tab + i));
	      ptr2 = &(*(tab + i + 1));
	      my_swap(ptr, ptr2);
	    }
	  i += 1;
	}
    } 
}
