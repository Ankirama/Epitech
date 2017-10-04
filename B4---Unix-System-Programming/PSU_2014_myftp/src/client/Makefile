##
## Makefile for Makefile in /home/ankirama
## 
## Made by Fabien martinez
## Login   <ankirama@epitech.net>
## 
## Started on  Sun Feb 27 10:48:37 2015 Fabien martinez
## Last update Sat Feb 21 19:17:53 2015 Fabien Martinez
##

UTILS_DIR	= ../utils
DIR		= ../..

CC	= gcc

RM	= rm -f

CFLAGS	= -Wextra -Wall -Werror -I. -I../../includes
CFLAGS	+= -lmy -L../../libs/printf/

NAME	= $(DIR)/client

SRCS	= main.c\
	  utils.c\
	  signal.c\
	  functions.c\
	  $(UTILS_DIR)/check_functions.c\
	  $(UTILS_DIR)/get_next_line.c\
	  $(UTILS_DIR)/check_sysfunctions.c\
	  $(UTILS_DIR)/str_to_wordtab.c\

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) ../../libs/printf/libmy.a

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
