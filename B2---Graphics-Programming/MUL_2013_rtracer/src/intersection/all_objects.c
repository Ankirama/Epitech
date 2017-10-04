/*
** all_objects.c for  in /home/viterb_c/rendu/MUL_2013_rtracer/src/intersection
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Sat Oct  4 17:41:19 2014 charles viterbo
** Last update Sun Oct 12 16:23:33 2014 mar_b mar_b
*/

#include <math.h>
#include <stdlib.h>
#include "objects.h"
#include "intersection.h"
#include "utils.h"
#include "shadow.h"
#include "noise.h"

static t_tab_function	g_my_fun[FUNC] =
  {
    {all_orb, color_orb, create_p_orb},
    {all_cone, color_cone, create_p_cone},
    {all_cylinder, color_cylinder, create_p_cyl},
    {all_plan, color_plan, create_p_plan},
    {all_paraboloide, color_paraboloide, create_p_paraboloide},
  };

/*
** brief : to create the objects
** @scene : scene
** @eye : your eye
** @vision : vector vision
** @obj : the object
*/
t_color		*objects(t_scene *scene, t_eye *eye,
			 t_vector *vision, t_dis *obj)
{
  t_color	*color;
  t_vector	*point;
  t_vector	p2;
  int		i;

  i = -1;
  while (++i < FUNC)
    g_my_fun[i].inter(scene, eye, vision, obj);
  if (obj->type == NO_OBJ)
    return (NULL);
  p2.x = eye->coord->x + obj->k * vision->x;
  p2.y = eye->coord->y + obj->k * vision->y;
  p2.z = eye->coord->z + obj->k * vision->z;
  point = g_my_fun[(int)obj->type].point(obj, eye, vision);
  color = g_my_fun[(int)obj->type].color(scene, obj, point);
  color = my_shadow(scene, &p2, color);
  return (color);
}
