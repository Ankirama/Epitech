/*
** parser_scene.c for parser_scene in /home/mar_b/rendu/MUL_2013_rtv1/parser_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul 15 09:34:14 2014 mar_b mar_b
** Last update Sun Aug  3 10:32:01 2014 mar_b mar_b
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "objects.h"
#include "get_next_line.h"
#include "utils.h"

static void	_add_spot(t_scene **scene, const char *str)
{
  t_spots	*elt;
  int		i;
  int		start;

  if ((elt = malloc(sizeof(*elt))) == NULL)
    my_puterror("error: problem to malloc in parser_scene.c\n");
  i = -1;
  while (str[++i] != '\0' && str[i] != ' ');
  elt->x = char_to_float(str, i);
  start = i + 1;
  while (str[++i] != '\0' && str[i] != ' ');
  elt->y = char_to_float(&str[start], i - start);
  start = i + 1;
  while (str[++i] != '\0' && str[i] != ' ');
  elt->z = char_to_float(&str[start], i - start);
  elt->next = ((*scene)->spots == NULL) ? NULL : (*scene)->spots;
  (*scene)->spots = elt;
}

static void	_add_eye(t_scene **scene, const char *str)
{
  t_vector	*elt;
  int		i;
  int		start;

  if ((elt = malloc(sizeof(*elt))) == NULL)
    my_puterror("error: problem to malloc in parser_scene.c\n");
  i = -1;
  while (str[++i] != '\0' && str[i] != ' ');
  elt->x = char_to_float(str, i);
  start = i + 1;
  while (str[++i] != '\0' && str[i] != ' ');
  elt->y = char_to_float(&str[start], i - start);
  start = i + 1;
  while (str[++i] != '\0' && str[i] != ' ');
  elt->z = char_to_float(&str[start], i - start);
  (*scene)->eye = elt;
}

static char	_my_strcmp(const char *s1, const char *s2)
{
  int		i;

  i = -1;
  while (s1[++i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]);
  return (s1[i] == ' ' && s2[i] == '\0');
}

static void	_add_in_scene(const char *str, t_scene **scene)
{
  void		(*tab_fun[5])(t_scene **scene, const char *str);
  char		**arr;
  int		i;

  if ((arr = malloc(sizeof(char *) * 6)) == NULL)
    my_puterror("error: problem to malloc in parser_scene.c\n");
  arr[0] = "sphere";
  arr[1] = "plane";
  arr[2] = "cylinder";
  arr[3] = "cone";
  arr[4] = "eye";
  arr[5] = "spot";
  tab_fun[0] = add_sphere;
  tab_fun[1] = add_plane;
  tab_fun[2] = add_cylinder;
  tab_fun[3] = add_cone;
  tab_fun[4] = _add_eye;
  tab_fun[5] = _add_spot;
  i = -1;
  while (++i < 6 && !_my_strcmp(str, arr[i]));
  if (i == 6)
    my_puterror("error: bad line in the file!\n");
  else
    tab_fun[i](scene, &str[my_strlen(arr[i]) + 1]);
  free(arr);
}

void	my_get_file(const char *pathname, t_scene *scene)
{
  int	fd;
  char	*s;
  int	i;

  if ((fd = open(pathname, O_RDONLY)) == -1)
    my_puterror("error: problem to open the file in parser_scene.c\n");
  i = -1;
  while (++i < 7)
    free(get_next_line(fd));
  while ((s = get_next_line(fd)) != NULL)
    {
      _add_in_scene(s, &scene);
      free(s);
    }
  if (close(fd) == -1)
    my_puterror("error: problem to close the fd in parser_scene.c\n");
}
