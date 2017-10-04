/*
** my_sort_params.c for my_sort_params in /home/mar_b/rendu/Piscine-C-Jour_07/ex_04/my_sort_params
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Mar 11 13:29:32 2014 Fabien Martinez
** Last update Wed Mar 12 18:03:10 2014 Fabien Martinez
*/

void	my_display_arg(int argc, char **argv)
{
  int	i;

  i = 0;
  while (i < argc)
    {
      my_putstr(argv[i]);
      my_putchar('\n');
      i += 1;
    }
}

int	main(int argc, char ** argv)
{
  int	i;
  int	done;
  char	*tmp;

  done = 1;
  while (done == 1)
    {
      done = 0;
      i = 0;
      while (i < (argc - 1))
        {
          if (strcmp(argv[i], argv[i + 1]) > 0)
	    {
              done = 1;
	      tmp = argv[i];
	      argv[i] = argv[i + 1];
	      argv[i + 1] = tmp;
            }
          i += 1;
        }
    }
  my_display_arg(argc, argv);
}
