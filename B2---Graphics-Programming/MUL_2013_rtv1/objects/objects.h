/*
** objects.h for parser in /home/mar_b/rendu/MUL_2013_rtv1/parser_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul 15 09:34:49 2014 mar_b mar_b
** Last update Thu Jul 24 23:54:49 2014 mar_b
*/

#ifndef OBJECTS_H_
# define OBJECTS_H_

typedef struct	s_vector
{
  float		x;
  float		y;
  float		z;
}		t_vector;

typedef struct		s_spots
{
  float			x;
  float			y;
  float			z;
  struct s_spots	*next;
}			t_spots;

typedef struct		s_planes
{
  float			k;
  float			z;
  float			ang_x;
  float			ang_y;
  float			ang_z;
  unsigned int		color;
  struct s_planes	*next;
}			t_planes;

typedef struct		s_spheres
{
  float			k;
  float			x;
  float			y;
  float			z;
  float			radius;
  unsigned int		color;
  struct s_spheres	*next;
}			t_spheres;

typedef struct		s_cones
{
  float			k;
  float			cst;
  float			x;
  float			y;
  float			z;
  float			ang_x;
  float			ang_y;
  float			ang_z;
  unsigned int		color;
  struct s_cones	*next;
}			t_cones;

typedef struct		s_cylinders
{
  float			k;
  float			x;
  float			y;
  float			z;
  float			ang_x;
  float			ang_y;
  float			ang_z;
  float			radius;
  unsigned int		color;
  struct s_cylinders	*next;
}			t_cylinders;

typedef struct	s_scene
{
  t_vector	*eye;
  t_spots	*spots;
  t_planes	*planes;
  t_spheres	*spheres;
  t_cones	*cones;
  t_cylinders	*cylinders;
}		t_scene;

/*
** objects.c
*/
int		travel_string(const char *str, int *i);

/*
** sphere.c
*/
void		add_sphere(t_scene **scene, const char *str);
float		calc_inter_spheres(t_scene *scene, t_vector *dis,
				   t_vector *eye, unsigned int *color);

/*
** plane.c
*/
void		add_plane(t_scene **scene, const char *str);
float		calc_inter_planes(t_scene *scene, t_vector *dis,
				  t_vector *eye, unsigned int *color);

/*
** cylinder.c
*/
void		add_cylinder(t_scene **scene, const char *str);
float		calc_inter_cylinders(t_scene *scene, t_vector *dis,
				     t_vector *eye, unsigned int *color);

/*
** cone.c
*/
void		add_cone(t_scene **scene, const char *str);
float		calc_inter_cones(t_scene *scene, t_vector *dis,
				 t_vector *eye, unsigned int *color);

/*
** free.c
*/
void		free_spheres(t_spheres *spheres);
void		free_spots(t_spots *spots);
void		free_planes(t_planes *planes);
void		free_cones(t_cones *cones);
void		free_cylinders(t_cylinders *cylinders);

#endif /* !OBJECTS_H_ */
