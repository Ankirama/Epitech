##
## Makefile for Makefile in /home/mar_b/rendu/CPE-2013-BSQ
##
## Made by mar_b mar_b
## Login   <mar_b@epitech.net>
##
## Started on  Tue May  6 13:57:30 2014 mar_b mar_b
## Last update Wed May  7 12:15:45 2014 mar_b mar_b
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -ansi -pedantic -g3

NAME	= bsq

SRCS	= bsq.c\
	  get_next_line.c\
	  my_fun.c\
	  my_fun2.c

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
