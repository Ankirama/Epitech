##
## Makefile for Makefile in /home/mar_b/rendu/colle3_mar_b
##
## Made by mar_b mar_b
## Login   <mar_b@epitech.net>
##
## Started on  Tue Sep  9 19:04:40 2014 mar_b mar_b
## Last update Tue Sep  9 22:19:01 2014 mar_b mar_b
##

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wall -Wextra
CFLAGS	+= -I./

NAME	= calculator

SRCS	= main.c\
	  fun.c\
	  nbr.c\
	  error.c\
	  my_op.c\
	  parser.c\
	  str.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
