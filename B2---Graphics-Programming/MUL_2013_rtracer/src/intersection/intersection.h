/*
** intersection.h for  in /home/viterb_c/rendu/MUL_2013_rtracer/src/intersection
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Sat Oct  4 18:00:05 2014 charles viterbo
** Last update Sun Oct 12 14:35:10 2014 charles viterbo
*/

#ifndef INTERSECTION_H_
# define INTERSECTION_H_

# define FUNC	5

# include "objects.h"

typedef struct	s_tab_function
{
  void		(*inter)(t_scene *, t_eye *, t_vector *, t_dis *);
  t_color	*(*color)(t_scene *, t_dis *, t_vector *);
  t_vector	*(*point)(t_dis *, t_eye *, t_vector *);
}		t_tab_function;

t_color		*objects(t_scene *scene, t_eye *eye,
			 t_vector *vision, t_dis *obj);

/*
** CYLINDER_C_
*/
t_color		*color_cylinder(t_scene *scene, t_dis *obj, t_vector *point);
double		inter_cylinder(t_vector *v1, t_vector *v3, double cons);
void		all_cylinder(t_scene *scene, t_eye *eye,
			     t_vector *vision, t_dis *obj);
t_vector	*create_p_cyl(t_dis *obj, t_eye *eye, t_vector *vision);

/*
** CONE_C_
*/
t_color		*color_cone(t_scene *scene, t_dis *obj, t_vector *point);
double		inter_cone(t_vector *v1, t_vector *v3, double cons[2]);
t_vector	*create_p_cone(t_dis *obj, t_eye *eye, t_vector *vision);
void		all_cone(t_scene *scene, t_eye *eye,
			 t_vector *vision, t_dis *obj);

/*
** PARABOLOIDE_C_
*/
t_color		*color_paraboloide(t_scene *scene, t_dis *obj, t_vector *point);
double		inter_paraboloide(t_vector *v1, t_vector *v2,
				  t_vector *v3, double cons[2]);
t_vector	*create_p_paraboloide(t_dis *obj, t_eye *eye, t_vector *vision);
void		all_paraboloide(t_scene *scene, t_eye *eye,
				t_vector *vision, t_dis *obj);

/*
** ORB_C_
*/
t_color		*color_orb(t_scene *scene, t_dis *obj, t_vector *point);
double		inter_orb(t_vector *v1, t_vector *v3, double cons);
void		all_orb(t_scene *scene, t_eye *eye,
			t_vector *vison, t_dis *obj);
t_vector	*create_p_orb(t_dis *obj, t_eye *eye, t_vector *vision);

/*
** PLAN_C_
*/
t_color		*color_plan(t_scene *scene, t_dis *obj, t_vector *point);
double		inter_plan(t_vector *v1, t_vector *v3, double cons);
t_vector	*create_p_plan(t_dis *obj, t_eye *eye, t_vector *vision);
void		all_plan(t_scene *scene, t_eye *eye,
			 t_vector *vision, t_dis *obj);

#endif /* !INTERSECTION_H_ */
