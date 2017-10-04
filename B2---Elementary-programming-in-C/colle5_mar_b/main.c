/*
** main.c for let it go in /home/mar_b/rendu/colle5_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep 23 19:01:35 2014 mar_b mar_b
<<<<<<< HEAD
** Last update Tue Sep 23 22:46:04 2014 mar_b mar_b
*/

=======
<<<<<<< HEAD
<<<<<<< HEAD
** Last update Tue Sep 23 22:42:34 2014 lefebv_1 lefebv_1
=======
** Last update Tue Sep 23 22:38:22 2014 mar_b mar_b
*/

=======
<<<<<<< HEAD
** Last update Tue Sep 23 22:38:54 2014 lefebv_1 lefebv_1
>>>>>>> 21afe7f91835be42aa7c48bc963361c380f08dbb
=======
<<<<<<< HEAD
** Last update Tue Sep 23 22:01:17 2014 mar_b mar_b
*/

/* int		main(int argc, char **argv) */
/* { */
/*   t_option	option; */

/*   my_check_options(argc, argv, &option); */
/* } */

>>>>>>> 38b5396cd2ec89bd50a67906cc69ca4878ff399b
>>>>>>> 887db889befcdde6179fd1cee237fa8adf9ac5ca
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "utils.h"
#include "algo.h"

static void	_display_arr(t_boogle *boogle)
{
  int		i;

  i = -1;
  while (boogle->tab[++i] != '\0')
    {
      if (i > 0 && i % boogle->sizeline == 0)
	(void)write(1, "\n", 1);
      (void)write(1, &(boogle->tab[i]), 1);
    }
}

void	my_default_option(t_option *option)
{
  char	buffer[4096];
  int	i;

  i = 0;
  if (option->word == NULL)
    {
      while (read(0, buffer, 4096) > 0 && buffer[i] != '\n')
	{
	  option->word[i] = buffer[i];
	  i = i + 1;
	}
      option->word[i] = '\0';
    }
  /* (void)write(1, "\n", 1); */
}

static void	_error(char *err)
{
  (void)write(2, "Le mot ", my_strlen("Le mot "));
  (void)write(2, err, my_strlen(err));
  my_puterror("n'est pas dans la grille.\n");
}

static void	_init_boogle(t_boogle *boogle, t_option *option)
{
  boogle->word = option->word;
  boogle->tab = option->grid;
  boogle->sizeline = option->size;
}

int		main(int argc, char **argv)
{
  t_boogle	boogle;
  t_option	option;

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 21afe7f91835be42aa7c48bc963361c380f08dbb
>>>>>>> 887db889befcdde6179fd1cee237fa8adf9ac5ca
  option.size = 4;
  option.grid = NULL;
  option.word = NULL;
  option.color = 0;
  my_check_option(argc, argv, &option);
<<<<<<< HEAD
  _init_boogle(&boogle, &option);
=======
  printf("%d\n", option.size);
  printf("%s\n", option.grid);
  printf("%s\n", option.word);
  printf("%d\n", option.color);
  /* boogle.tab = "lqnelooelbtelqte"; */
  /* boogle.word = "noob"; */
  /* boogle.sizeline = 4; */
  /* if (argc > 1) */
  /*   { */
  /*     if (!my_find_word(&boogle, argv[1], 0, 0)) */
  /* 	fprintf(stderr, "Le mot \"%s\" n'est pas dans la grille.\n", argv[1]); */
  /*     else */
  /* 	_display_arr(&boogle); */
  /*   } */
  /* printf("RES : %d\n", next_is_ok(&boogle, 'n', 2, 0)); */
<<<<<<< HEAD
/* ======= */
/* <<<<<<< HEAD */
/*   boogle.tab = strdup("lqnelooelbtelqte"); */
/*   boogle.word = "noob"; */
/*   boogle.sizeline = 4; */
/*   _display_arr(&boogle); */
/*   (void)write(1, "__________\n", 11); */
/* ======= */
/*   option.color = 0; */
/*   my_check_options(argc, argv, &option); */
/*   boogle.tab = "lqnelooelbtelqte"; */
/*   boogle.word = "noob"; */
/*   boogle.sizeline = 4; */
/* >>>>>>> dce6e96736719069a6e0a6f6dec76cff7af75207 */
/*   if (argc > 1) */
/*     { */
/*       if (!my_find_word(&boogle, argv[1], 0, 0)) */
/* 	fprintf(stderr, "Le mot \"%s\" n'est pas dans la grille.\n", argv[1]); */
/*       else */
/* 	_display_arr(&boogle); */
/*     } */
/* <<<<<<< HEAD */
/* ======= */
/*   printf("RES : %d\n", next_is_ok(&boogle, 'n', 2, 0)); */
/* >>>>>>> dce6e96736719069a6e0a6f6dec76cff7af75207 */
/* >>>>>>> a6972e5a5af9dfa41822a56057232bae1e7e1078 */
=======
=======
<<<<<<< HEAD
>>>>>>> 38b5396cd2ec89bd50a67906cc69ca4878ff399b
  boogle.tab = strdup("lqnelooelbtelqte");
  boogle.word = "noob";
  boogle.sizeline = 4;
>>>>>>> 887db889befcdde6179fd1cee237fa8adf9ac5ca
  _display_arr(&boogle);
  option.color = 0;
  boogle.tab = "lqnelooelbtelqte";
  boogle.word = "noob";
  boogle.sizeline = 4;
  if (argc > 1)
    {
      if (!my_find_word(&boogle, argv[1], 0, 0))
	_error(option.word);
      else
	_display_arr(&boogle);
    }
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
  printf("RES : %d\n", next_is_ok(&boogle, 'n', 2, 0));
>>>>>>> dce6e96736719069a6e0a6f6dec76cff7af75207
>>>>>>> a6972e5a5af9dfa41822a56057232bae1e7e1078
>>>>>>> 38b5396cd2ec89bd50a67906cc69ca4878ff399b
>>>>>>> 21afe7f91835be42aa7c48bc963361c380f08dbb
>>>>>>> 887db889befcdde6179fd1cee237fa8adf9ac5ca
  return (0);
}
