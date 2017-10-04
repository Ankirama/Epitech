##
## Makefile for make in /home/mar_b/rendu/MUL_2013_wolf3d
##
## Made by mar_b mar_b
## Login   <mar_b@epitech.net>
##
## Started on  Sat May 17 19:53:20 2014 mar_b mar_b
## Last update Sun Jun 15 17:29:06 2014 mar_b mar_b
##

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Werror -Wextra
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -DM_PI=3.14159265358979323846

LDFLAGS	= -L/usr/X11/lib -lmlx -lXext -lX11 -I/usr/X11/include -lm -I.

NAME	= wolf3d

SRCS	= main.c\
	  my_pret.c\
	  my_minimap.c\
	  my_fun.c\
	  my_wall.c\
	  my_calc.c\
	  my_init.c\
	  get_next_line.c\
	  my_free.c\
	  my_key.c\
	  my_pixel.c\
	  my_error.c\
	  my_img.c\

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
