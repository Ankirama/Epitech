
##
## Makefile for Makefile in /home/ankirama
##
## Made by Fabien martinez
## Login   <ankirama@epitech.net>
##
## Started on  Sun Feb 27 10:48:37 2015 Fabien martinez
## Last update Wed Apr  1 10:32:25 2015 Fabien Martinez
##

UTILS_DIR	= ../utils
SERVER_DIR 	= ../..

CC	= gcc

RM	= rm -f

CFLAGS 	= -W -Wextra -Wall -D_BSD_SOURCE -I../../includes
CFLAGS	+= -lmy -L../../libs/printf/

NAME	= $(SERVER_DIR)/server

SRCS	= $(UTILS_DIR)/check_functions.c \
	  $(UTILS_DIR)/check_sysfunctions.c \
	  $(UTILS_DIR)/get_next_line.c \
	  $(UTILS_DIR)/str_to_wordtab.c \
	  $(UTILS_DIR)/list.c \
	  $(UTILS_DIR)/list2.c \
	  $(UTILS_DIR)/nbr.c \
	  main.c\
	  read.c\
	  port.c\
	  create_server.c\
	  close.c\
	  signal.c\
	  cmd_nick.c\
	  cmd_join.c\
	  cmd_part.c\
	  cmd_names.c\
	  cmd_list.c\
	  cmd_privmsg.c\
	  cmd_users.c\
	  cmd_quit.c\
	  interpret_message.c\
	  send.c\
	  channel.c\
	  welcome.c \

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
