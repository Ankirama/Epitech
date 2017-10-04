##
## Makefile for Makefile in /home/mar_b/rendu/Piscine-C-Jour_11/do-op
##
## Made by Fabien Martinez
## Login   <mar_b@epitech.net>
##
## Started on  Mon Mar 24 10:01:34 2014 Fabien Martinez
## Last update Mon Mar 24 16:38:13 2014 Fabien Martinez
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS 	+= -ansi -pedantic
CFLAGS	+= -I.

NAME	= do-op

SRCS	= do-op.c \
	  my_fun.c \
	  my_nbr.c \
	  operations.c \

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
