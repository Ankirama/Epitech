##
## Makefile for Makefile in /home/user/rendu/CPE-2013-BSQ
##
## Made by 
## Login   
##
## Started on  Tue May  6 13:57:30 2014 
## Last update Wed May  7 12:15:45 2014 
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
