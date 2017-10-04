##
## Makefile for makefile in /home/mar_b/rendu/colle1_mar_b
##
## Made by mar_b mar_b
## Login   <mar_b@epitech.net>
##
## Started on  Tue Aug 26 19:47:36 2014 mar_b mar_b
## Last update Tue Aug 26 22:09:47 2014 mar_b mar_b
##

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wextra
CFLAGS	+= -I./

NAME	= fractals

SRCS	= main.c\
	  fun.c\
	  my_check_arg.c\
	  nbr.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
