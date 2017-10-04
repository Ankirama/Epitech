/*
** my_rev_params.c for my_rev_params in /home/mar_b/rendu/Piscine-C-Jour_07/ex_03/my_rev_params
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Mar 11 12:42:19 2014 Fabien Martinez
** Last update Wed Mar 12 22:49:23 2014 Fabien Martinez
*/

int	main(int argc, char **argv)
{
  int	i;

  i = argc - 1;
  while (i >= 0)
    {
      my_putstr(argv[i]);
      my_putchar('\n');
      i -= 1;
    }
  return (0);
}
