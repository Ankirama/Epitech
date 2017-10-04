/*
** error.c for  in /home/teyssa_r/rendu/MUL_2013_rtracer/src/utils
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Sun Oct 12 16:02:37 2014 teyssa_r teyssa_r
** Last update Sun Oct 12 16:02:38 2014 teyssa_r teyssa_r
*/

#include <stdlib.h>
#include "utils.h"

/*
** brief : write an error and exit
** @err : the error
*/
void	my_puterror(char *err)
{
  my_write(2, err, my_strlen(err));
  exit(EXIT_FAILURE);
}

/*
** brief : if object unvalid
** @err : the oobject unvalid
*/
void	my_warning_obj(char *obj)
{
  my_write(2, "warning: ", my_strlen("warning: "));
  my_write(2, obj, my_strlen(obj));
  my_write(2, WAR_OBJ, my_strlen(WAR_OBJ));
}
