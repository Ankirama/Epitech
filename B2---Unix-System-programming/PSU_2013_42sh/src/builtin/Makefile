##
## Makefile for Makefile in /home/zighed_a/scripts
## 
## Made by zighed_a zighed_a
## Login   <zighed_a@epitech.net>
## 
## Started on  Wed May 21 16:58:20 2014 zighed_a zighed_a
## Last update Wed Oct  1 19:03:33 2014 zighed_a zighed_a
##

CC = cc

RM = rm -rf

CFLAGS = -W -Werror -ansi -pedantic

NAME = my_echo

SRCS = my_echo.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
