/*
** objects.h for  in /home/viterb_c/rendu/MUL_2013_rtracer/src/objects
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Fri Oct  3 13:36:05 2014 charles viterbo
** Last update Sun Oct 12 18:35:34 2014 mar_b mar_b
*/

#ifndef OBJECTS_H_
# define OBJECTS_H_

# define NO_OBJ		-1
# define ORB		0
# define CONE		1
# define CYLIND		2
# define PLAN		3
# define PARA		4

typedef struct	s_vector
{
  double	x;
  double	y;
  double	z;
}		t_vector;

typedef struct	s_color
{
  int		r;
  int		g;
  int		b;
}		t_color;

typedef struct		s_light
{
  t_vector		*coord;
  t_color		*color;
  char			puiss;
  struct s_light	*next;
}			t_light;

typedef struct	s_eye
{
  t_vector	*coord;
  t_vector	*rot;
  struct s_eye	*next;
}		t_eye;

typedef struct	s_orb
{
  t_vector	*coord;
  double	radius;
  t_color	*color;
  double	brill;
  t_vector	*pn;
  t_vector	*limit_up;
  t_vector	*limit_low;
  char		perlin;
  struct s_orb	*next;
}		t_orb;

typedef struct	s_plan
{
  t_vector	*coord;
  double	trans;
  t_vector	*rot;
  t_color	*color;
  double	brill;
  t_vector	*pn;
  t_vector	*limit_up;
  t_vector	*limit_low;
  struct s_plan	*next;
}		t_plan;

typedef struct	s_cone
{
  t_vector	*coord;
  double	angle;
  t_vector	*rot;
  t_color	*color;
  double	brill;
  double	hyper;
  t_vector	*pn;
  t_vector	*limit_up;
  t_vector	*limit_low;
  struct s_cone	*next;
}		t_cone;

typedef struct		s_cylinder
{
  t_vector		*coord;
  double		radius;
  t_vector		*rot;
  t_color		*color;
  double		brill;
  t_vector		*pn;
  t_vector		*limit_up;
  t_vector		*limit_low;
  struct s_cylinder	*next;
}			t_cylinder;

typedef struct	s_para
{
  t_vector	*coord;
  double	type;
  double	cst;
  t_vector	*rot;
  t_color	*color;
  double	brill;
  t_vector	*pn;
  t_vector	*limit_up;
  t_vector	*limit_low;
  struct s_para	*next;
}		t_para;

typedef struct	s_scene
{
  t_eye		*list_eye;
  t_orb		*list_orb;
  t_plan	*list_plan;
  t_cone	*list_cone;
  t_light	*list_light;
  t_cylinder	*list_cyl;
  t_para	*list_para;
  char		ambiance;
}		t_scene;

typedef struct	s_dis
{
  char		type;
  void		*element;
  double	k;
}		t_dis;

/*
** ORB_C_
*/
void	create_orb(t_scene **scene, char **arr);
void	free_orb(t_scene *scene);

/*
** EYE_C_
*/
void	create_eye(t_scene **scene, char **arr);
void	free_eye(t_scene *scene);

/*
** CONE_C_
*/
void	create_cone(t_scene **scene, char **arr);
void	free_cone(t_scene *scene);

/*
** PARABOLOIDE_C_
*/
void	create_paraboloide(t_scene **scene, char **arr);
void	free_paraboloide(t_scene *scene);

/*
** PLAN_C_
*/
void	create_plan(t_scene **scene, char **arr);
void	free_plan(t_scene *scene);

/*
** CYLINDER_C_
*/
void	create_cylinder(t_scene **scene, char **arr);
void	free_cylinder(t_scene *scene);

/*
** LIGHT_C_
*/
void	create_light(t_scene **scene, char **arr);
void	free_light(t_scene *scene);

#endif	/* !OBJECTS_H_ */
