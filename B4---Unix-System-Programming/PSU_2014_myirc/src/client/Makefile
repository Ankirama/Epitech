##
## Makefile for Makefile in /home/ankirama
## 
## Made by Fabien martinez
## Login   <ankirama@epitech.net>
## 
## Started on  Sun Feb 27 10:48:37 2015 Fabien martinez
## Last update Thu Apr 16 13:39:52 2015 Alexandre Chenevier
##

UTILS_DIR	= ../utils
DIR		= ../..

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wextra -Wall -I../../includes
CFLAGS	+= -lmy -L../../libs/printf/

NAME	= $(DIR)/client

SRCS	= $(UTILS_DIR)/list.c \
	  $(UTILS_DIR)/list2.c \
	  $(UTILS_DIR)/nbr.c\
	  $(UTILS_DIR)/str_to_wordtab.c\
	  main.c\
	  select.c\
	  func_fill.c\
	  loop_function.c\
	  check_channel.c

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
