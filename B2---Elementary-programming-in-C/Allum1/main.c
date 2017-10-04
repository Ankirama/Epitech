/*
** main.c for main in /home/mar_b/rendu/Allum1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jun 30 20:29:58 2014 mar_b mar_b
** Last update Wed Jul  9 23:11:18 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "list.h"
#include "utils.h"
#include "graph.h"
#include "game.h"

static char	_my_strcmp(const char *s1, const char *s2)
{
  int		i;

  i = -1;
  while (s1[++i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]);
  return (s1[i] == s2[i]);
}

static char	_display_help()
{
  (void)write(1, "Keys : UP/DOWN to move\nENTER to remove lucifers\n", 48);
  (void)write(1, "Space to finish your turn\nEscape to leave the game\n", 52);
  return (0);
}

int		main(int argc, char **argv)
{
  t_list	*lst;

  if (argc > 1 && _my_strcmp(argv[1], "--help"))
      return (_display_help());
  lst = create_list(4);
  main_graph(lst, 0);
  return (0);
}
