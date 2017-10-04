/*
** parser.c for  in /home/viterb_c/rendu/MUL_2013_rtracer/parser
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Tue Sep 30 10:19:23 2014 charles viterbo
** Last update Sun Oct 12 22:19:02 2014 charles viterbo
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "parser.h"
#include "utils.h"
#include "objects.h"
#include "str_to_wordtab.h"

/*
** brief : luminosity ambiance
** @scene : our scene
** @arr : our tab
*/
static void	_create_ambiance(t_scene **scene, char **arr)
{
  if (my_arrlen(arr) < 1)
    my_warning_obj("ambiance");
  else
    (*scene)->ambiance = atoi(arr[0]);
}

static t_tab_get_scene	g_my_figure[SIZE] =
  {
    {"orb", create_orb},
    {"cone", create_cone},
    {"cylinder", create_cylinder},
    {"plan", create_plan},
    {"eye", create_eye},
    {"light", create_light},
    {"paraboloide", create_paraboloide},
    {"ambiance", _create_ambiance}
  };

/*
** : brief : open and read the file that contain our scene
** @file_name : the path
** @scene : our scene
*/
t_scene	*get_scene(const char *file_name, t_scene *scene)
{
  int	fd;
  int	i;
  char	*str;
  char	**arr;

  if ((fd = open(file_name, O_RDONLY)) == -1)
    my_puterror(ERR_OPEN);
  while ((str = get_next_line(fd)) != NULL)
    {
      i = 0;
      arr = str_to_wordtab(str);
      while (i < SIZE && my_strcmp(arr[0], g_my_figure[i].name) != 0)
	i++;
      if (i < SIZE)
	g_my_figure[i].create(&scene, &arr[1]);
      free_arr(arr);
      free(str);
    }
  if (close(fd) == -1)
    my_puterror(ERR_CLOSE);
  return (scene);
}
