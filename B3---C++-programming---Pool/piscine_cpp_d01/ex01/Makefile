##
## Makefile for Makefile in /home/user/rendu/piscine_cpp_d01/ex01
##
## Made by 
## Login   
##
## Started on  Wed Jan  7 10:59:18 2015 
## Last update Wed Jan  7 11:26:41 2015 
##

CC	= gcc

RM	= rm -f

CFLAGS	= -Wextra -Werror -Wall -std=gnu99

NAME	= menger

SRCS	= main.c\
	  menger.c

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
