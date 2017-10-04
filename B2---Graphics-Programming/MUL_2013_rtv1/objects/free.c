/*
** free.c for free in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jul 24 23:38:10 2014 mar_b
** Last update Thu Jul 24 23:54:58 2014 mar_b
*/

#include <stdlib.h>
#include "objects.h"

/*
** brief: it will free our struct
*/
void		free_spheres(t_spheres *spheres)
{
  t_spheres	*tmp;

  while (spheres != NULL)
    {
      tmp = spheres;
      spheres = spheres->next;
      free(tmp);
    }
}

/*
** brief: it will free our struct
*/
void		free_spots(t_spots *spots)
{
  t_spots	*tmp;

  while (spots != NULL)
    {
      tmp = spots;
      spots = spots->next;
      free(tmp);
    }
}

/*
** brief: it will free our struct
*/
void		free_planes(t_planes *planes)
{
  t_planes	*tmp;

  while (planes != NULL)
    {
      tmp = planes;
      planes = planes->next;
      free(tmp);
    }
}

/*
** brief: it will free our struct
*/
void		free_cones(t_cones *cones)
{
  t_cones      	*tmp;

  while (cones != NULL)
    {
      tmp = cones;
      cones = cones->next;
      free(tmp);
    }
}

/*
** brief: it will free our struct
*/
void		free_cylinders(t_cylinders *cylinders)
{
  t_cylinders	*tmp;

  while (cylinders != NULL)
    {
      tmp = cylinders;
      cylinders = cylinders->next;
      free(tmp);
    }
}
