/*
** wolf3d.h<2> for my_include in /tmp/Wolf3D
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jun 11 14:06:46 2014 mar_b mar_b
** Last update Sun Jun 15 03:57:54 2014 mar_b mar_b
*/

#ifndef WOLF3D_H_
# define WOLF3D_H_

# define WIDTH		800
# define HEIGHT		600
# define WIDTH_MINI	200
# define HEIGHT_MINI	200

# define ID_WALL	0x424242
# define ID_GROUND	0x004600
# define ID_SKY		0x33CCFF

# define ID_KEYP	2
# define ID_KEYR	3

# define ID_UP		65362
# define ID_DOWN	65364
# define ID_LEFT	65361
# define ID_RIGHT       65363
# define ID_ESCAPE	65307

typedef struct	s_vector
{
  float		x;
  float		y;
}		t_vector;

typedef struct	s_move
{
  t_vector	*pos;
  int		id_ang;
  float	        range_k;
  float		sin_ang[25];
  float		cos_ang[25];
}		t_move;

typedef struct	s_img
{
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
}		t_img;

typedef struct	s_labyrinth
{
  int		x;
  int		y;
  char		**patrn;
}		t_labyrinth;

typedef struct	s_ptr
{
  void		*mlx;
  void		*win;
  void		*img;
  void		*mini;
  void		*sky;
  t_img		*sky_p;
  t_img		*pic;
  t_img		*mini_p;
  t_labyrinth	*lab;
  t_move	*move;
}		t_ptr;

#endif /* !WOLF3D_H_ */
