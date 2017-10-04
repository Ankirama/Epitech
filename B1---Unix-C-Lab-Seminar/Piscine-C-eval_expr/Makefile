##
## Makefile for Makefile in /home/mar_b/rendu/Piscine-C-eval_expr
##
## Made by Fabien Martinez
## Login   <mar_b@epitech.net>
##
## Started on  Thu Mar 27 21:21:28 2014 Fabien Martinez
## Last update Sun Mar 30 17:09:52 2014 Fabien Martinez
##

CC	= gcc

RM	= rm -f

CFLAGS += -Wextra -Werror -Wall
CFLAGS += -ansi -pedantic
CFLAGS += -lmy -L../Piscine-C-lib/
CFLAGS += -I../Piscine-C-include/

NAME	= eval_expr

SRCS	= doop.c \
	  my_format_str.c \
	  eval_expr.c \
	  my_fun.c \
	  my_int_to_string.c \
	  my_nbr.c \
	  my_parenth.c \
	  my_str.c \
	  my_wordtab_fun.c \
	  operations.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
