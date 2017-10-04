/*
** header.c for header in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat Oct 11 11:15:20 2014 mar_b mar_b
** Last update Mon Oct  6 04:57:00 2014
*/

#include <stdio.h>
#include "utils.h"
#include "rtracer.h"

/*
** brief: the general header for bmp format with magic usw usw...
** @header: we will fill it
** @file_size: the total size (header1 + header2 + nbr_pixels)
*/
static void	_my_header1(unsigned char *header, int file_size)
{
  header[0] = 'B';
  header[1] = 'M';
  header[2] = file_size & 0xFF;
  header[3] = (file_size >> 8) & 0xFF;
  header[4] = (file_size >> 16) & 0xFF;
  header[5] = (file_size >> 24) & 0xFF;
  header[10] = 54;
}

/*
** brief: the specific hearder for the file
** @header: we will fill it
** @filze_size: the nbr pixels
** @bpp: bits per pixels (8, 16, 24, 32)
*/
static void	_my_header2(unsigned char *header, int file_size, int bpp)
{
  header[0] = 40;
  header[4] = WIDTH & 0xFF;
  header[5] = (WIDTH >> 8) & 0xFF;
  header[6] = (WIDTH >> 16) & 0xFF;
  header[7] = (WIDTH >> 24) & 0xFF;
  header[8] = HEIGHT & 0xFF;
  header[9] = (HEIGHT >> 8) & 0xFF;
  header[10] = (HEIGHT >> 16) & 0xFF;
  header[11] = (HEIGHT >> 24) & 0xFF;
  header[12] = 1;
  header[14] = bpp;
  header[20] = file_size & 0xFF;
  header[21] = (file_size >> 8) & 0xFF;
  header[22] = (file_size >> 16) & 0xFF;
  header[23] = (file_size >> 24) & 0xFF;
}

/*
** brief: we will create our header and write it into our file (bytes mode)
** @file: our file
** @file_zile: total size (header1+ header2 + nbr_pixels)
** @bpp: bits pers pixels (8, 16, 24, 32)
*/
void		create_header(FILE *file, int file_size, int bpp)
{
  unsigned char	header1[14];
  unsigned char	header2[40];

  init_buff(header1, 14);
  init_buff(header2, 40);
  _my_header1(header1, file_size);
  fwrite(header1, 1, 14, file);
  _my_header2(header2, file_size - 54, bpp);
  fwrite(header2, 1, 40, file);
}
