##
## Makefile for Makefile in /home/mar_b/rendu/MUL_2013_fdf
##
## Made by Fabien Martinez
## Login   <mar_b@epitech.net>
##
## Started on  Tue Apr 29 23:16:57 2014 Fabien Martinez
## Last update Fri May  9 10:29:26 2014 mar_b mar_b
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -ansi -pedantic -g3
CFLAGS	+= -L /usr/X11/lib -lmlx -lXext -lX11 -I /usr/X11/include

NAME	= fdf

SRCS	= fdf.c \
	  my_pixel.c \
	  my_str_to_wordtab.c \
	  my_tab.c \
	  my_convert.c \
	  my_display.c \
	  my_fun.c \
	  get_next_line.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
