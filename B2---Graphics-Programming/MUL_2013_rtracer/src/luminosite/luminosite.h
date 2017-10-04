/*
** luminosite.h for  in /home/viterb_c/rendu/MUL_2013_rtracer/src/luminosite
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Mon Oct  6 15:47:00 2014 charles viterbo
** Last update Sun Oct 12 16:47:22 2014 mar_b mar_b
*/

#ifndef LUMINOSITE_H_
# define LUMINOSITE_H_

# include "objects.h"

/*
** ORB_C_
*/
t_color	*lumi_orb(t_scene *scene, t_orb *orb, t_vector *point);

/*
** CALC_C
*/
double	calc_angle(t_vector *p, t_vector *light, t_vector *n, t_vector *var);
double	calc_angle_amb(t_vector *n, t_vector *light,
		       t_vector *p, t_vector *var);

/*
** CONE_C_
*/
t_color	*lumi_cone(t_scene *scene, t_cone *cone, t_vector *point);

/*
** PARABOLOIDE_C_
*/
t_color	*lumi_paraboloide(t_scene *scene, t_para *para, t_vector *point);

/*
** PLAN_C_
*/
t_color	*lumi_plan(t_scene *scene, t_plan *plan, t_vector *point);

/*
** CYLINDER_C_
*/
t_color	*lumi_cyl(t_scene *scene, t_cylinder *cyl, t_vector *point);

#endif /* !LUMINOSITE_H_ */
