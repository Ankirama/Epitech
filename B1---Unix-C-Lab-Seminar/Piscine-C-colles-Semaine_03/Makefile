##
## Makefile for Makefile in /home/mar_b/rendu/Piscine-C-colles-Semaine_03
##
## Made by Fabien Martinez
## Login   <mar_b@epitech.net>
##
## Started on  Sat Mar 29 08:23:31 2014 Fabien Martinez
## Last update Sun Mar 30 03:14:01 2014 Fabien Martinez
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS 	+= -lmy -L../Piscine-C-lib/
CFLAGS	+= -I../Piscine-C-include/

NAME	= colle3

SRCS	= main.c \
	  my_colle.c \
	  my_init.c \
	  my_perror.c \
	  my_perror2.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
