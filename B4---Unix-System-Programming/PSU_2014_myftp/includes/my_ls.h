/*
** my_ls.h for my_ls in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Apr 23 13:27:01 2014 Fabien Martinez
** Last update Fri May  2 15:06:57 2014 Fabien Martinez
*/

#ifndef MY_LS_H_
# define MY_LS_H_

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <errno.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <sys/stat.h>
# include <time.h>

# include "my_display.h"
# include "my_printf.h"

# define RECURSIVE	0
# define REVERSE	1
# define DIRC		2
# define LONG		3
# define TIME		4
# define GROUP		5
# define NOTSORT	6
# define OWNER		7
# define INDICATOR	8
# define ALL		9
# define INFGRP		10
# define BACKUP		11
# define SIZE		12
# define QUOTE		13

extern int	g_fd;

int	my_ls(char **arr, int fd, char *ignored);

#endif /* !MY_LS_H_ */
