##
## Makefile for make in /home/mar_b/rendu/CPE_2013_Pushswap
##
## Made by mar_b mar_b
## Login   <mar_b@epitech.net>
##
## Started on  Sat May 17 19:53:20 2014 mar_b mar_b
## Last update Sat Jun  7 14:35:44 2014 mar_b mar_b
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I./operations/ -I.

NAME	= push_swap

SRCS	= main.c\
	  my_fun.c\
	  my_verbose.c\
	  my_list.c\
	  my_sort.c\
	  my_sort_la.c\
	  my_sort_lb.c\
	  ./operations/my_swap.c\
	  ./operations/my_changelist.c\
	  ./operations/my_mulope.c\
	  ./operations/my_rotate.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
