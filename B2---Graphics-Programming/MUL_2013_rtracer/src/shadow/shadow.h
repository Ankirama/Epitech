/*
** shadow.h for shadow in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Oct  9 11:09:53 2014 mar_b mar_b
** Last update Sun Oct 12 17:50:40 2014 charles viterbo
*/

#ifndef SHADOW_H_
# define SHADOW_H_

# include "objects.h"

typedef struct	s_inter_shadow
{
  double	(*fun)(t_scene *scene, t_vector *l, t_vector *p);
}		t_inter_shadow;

/*
** SHADOW
*/
t_color		*my_shadow(t_scene *scene, t_vector *shadow,
			   t_color *color);
void		pass_to_simple(t_vector **p, t_vector **l,
			       t_vector *coord, t_vector *rot);
void		pass_to_real(t_vector **p, t_vector **l,
			     t_vector *coord, t_vector *rot);
/*
** ORB_C_
*/
double		shadow_orb(t_scene *scene, t_vector *l, t_vector *p);

/*
** CONE_C_
*/
double		shadow_cones(t_scene *scene, t_vector *l, t_vector *p);

/*
** PLAN_C_
*/
double		shadow_plan(t_scene *scene, t_vector *l, t_vector *p);

/*
** CYLINDER_C_
*/
double		shadow_cylinder(t_scene *scene, t_vector *l, t_vector *p);

/*
** PARABOLOIDE_C_
*/
double		shadow_paraboloide(t_scene *scene, t_vector *l, t_vector *p);

#endif /* !SHADOW_H_ */
