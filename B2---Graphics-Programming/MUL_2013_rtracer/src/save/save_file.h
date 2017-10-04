/*
** save_file.h for save_file in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat Oct 11 13:16:48 2014 mar_b mar_b
** Last update Sun Oct 12 17:16:38 2014 charles viterbo
*/

#ifndef SAVE_FILE_H_
# define SAVE_FILE_H_

# include <stdio.h>
# include "rtracer.h"

/*
** HEADER_C_
*/
void	create_header(FILE *file, int file_size, int bpp);

/*
** SAVE_FILE_C_
*/
void	save_file(char *name, t_img *img);

#endif /* !SAVE_FILE_H_ */
