##
## Makefile for Makefile in /home/user/colle_06_HBX_
##
## Made by 
## Login   
##
## Started on  Tue Sep 30 20:17:50 2014 
## Last update Tue Sep 30 22:14:33 2014 
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
