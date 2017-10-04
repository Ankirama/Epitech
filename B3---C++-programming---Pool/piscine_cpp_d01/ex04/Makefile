##
## Makefile for Makefile in /home/mar_b/rendu/piscine_cpp_d01/ex01
##
## Made by Fabien Martinez
## Login   <mar_b@epitech.net>
##
## Started on  Wed Jan  7 10:59:18 2015 Fabien Martinez
## Last update Thu Jan  8 08:31:48 2015 Fabien Martinez
##

CC	= gcc

RM	= rm -f

CFLAGS	= -Wextra -Werror -Wall -std=gnu99

NAME	= menger_face

SRCS	= main.c\
	  bitmap_header.c\
	  drawing.c\
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
