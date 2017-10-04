/*
** my_ls.c for my_ls in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Apr 23 01:43:40 2014 Fabien Martinez
** Last update Fri May  2 19:10:07 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "my_printf.h"
#include "my_ls.h"
#include "my_display.h"
#include "my_printf.h"
#include "my_read.h"

/*
** copy a char * into another char *
*/
static char	*my_strcpy(char *my_file)
{
  int		i;
  char		*str;

  if ((str = malloc(my_strlen(my_file) + 1)) == NULL)
    my_puterror();
  i = 0;
  while (my_file[i])
    str[i] = my_file[i++];
  str[i] = '\0';
  return (str);
}

/*
** This function will create a char ** which contains params (except options)
*/
static char	**my_nbr_words(int argc, char **argv)
{
  int		i;
  int		count;
  char		**tab;

  i = 1;
  count = 0;
  while (i < argc)
    {
      if (argv[i][0] != '-')
	count += 1;
      i += 1;
    }
  if ((tab = malloc(count + 1)) == NULL)
    return (NULL);
  i = 0;
  while (i <= count)
    {
      if ((tab[i] = malloc(1)) == NULL)
	return (NULL);
      tab[i] = 0;
      i += 1;
    }
  return (tab);
}

/*
** Check if there is/are argument(s) or the -d option is present
*/
static char	my_c(char **my_tab, char *opt)
{
  return (my_tab[0] != 0 || opt[DIRC]);
}

/*
** This function looks like a main, but i'm not sure I pasted it... <3
*/
int	main(int argc, char **argv)
{
  int	i;
  int	pos;
  char	opt[8];
  char	**tb;

  i = 0;
  while (i < 8)
    opt[i++] = 0;
  if ((tb = my_nbr_words(argc, argv)) == NULL)
    my_puterror();
  i = 1;
  pos = 0;
  while (i < argc)
    {
      if (argv[i][0] == '-')
	{
	  if (my_check_options(opt, argv[i]))
	    return (my_help());
	}
      else
	tb[pos++] = my_strcpy(argv[i]);
      i += 1;
    }
  return (my_c(tb, opt) ? my_read_manage(tb, opt) :
	  my_read_dir("./", opt, 0, 1));
}
