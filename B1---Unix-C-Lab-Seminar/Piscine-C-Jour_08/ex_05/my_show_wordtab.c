/*
** my_show_wordtab.c for my_show_wordtab in /home/mar_b/rendu/Piscine-C-Jour_08/ex_05
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Mar 13 19:36:31 2014 Fabien Martinez
** Last update Thu Mar 13 19:38:13 2014 Fabien Martinez
*/

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i += 1;
    }
}
