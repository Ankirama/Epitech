
##
## Makefile for Makefile in /home/ankirama
## 
## Made by Fabien martinez
## Login   <ankirama@epitech.net>
## 
## Started on  Sun Feb 27 10:48:37 2015 Fabien martinez
## Last update Sun Feb 22 07:16:00 2015 Fabien Martinez
##

LS_DIR 		= ls
UTILS_DIR	= ../utils
SERVER_DIR 	= ../..

CC	= gcc

RM	= rm -f

CFLAGS 	= -W -Wextra -Wall -D_BSD_SOURCE -I. -I../../includes
CFLAGS	+= -lmy -L../../libs/printf/

NAME	= $(SERVER_DIR)/serveur

SRCS	= $(LS_DIR)/my_ls.c \
	  $(LS_DIR)/my_date.c \
	  $(LS_DIR)/my_read.c \
	  $(LS_DIR)/my_check.c \
	  $(LS_DIR)/my_color.c \
	  $(LS_DIR)/my_path.c \
	  $(LS_DIR)/my_display.c \
	  $(LS_DIR)/my_display_l.c \
	  $(LS_DIR)/my_sort.c \
	  $(LS_DIR)/my_file.c \
	  $(LS_DIR)/my_options.c \
	  $(LS_DIR)/my_fun.c\
	  $(UTILS_DIR)/check_functions.c\
	  $(UTILS_DIR)/check_sysfunctions.c\
	  $(UTILS_DIR)/str_to_wordtab.c\
	  $(UTILS_DIR)/get_next_line.c\
	  builtins.c\
	  log.c\
	  signal.c\
	  functions.c\
	  check.c\
	  main.c\

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
