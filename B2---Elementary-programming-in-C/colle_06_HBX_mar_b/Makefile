##
## Makefile for Makefile in /home/mar_b/colle_06_HBX_mar_b
##
## Made by mar_b mar_b
## Login   <mar_b@epitech.net>
##
## Started on  Tue Sep 30 20:17:50 2014 mar_b mar_b
## Last update Tue Sep 30 22:14:33 2014 mar_b mar_b
##

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wall -Wextra

NAME	= text_count

SRCS	= main.c\
	  fun.c\
	  nbr.c\
	  my_sort.c\
	  list.c\
          travel.c\
	  my_strcmp.c

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
