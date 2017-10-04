##
## Makefile for  in /home/viterb_c/rendu/PSU_2014_zappy/server
##
## Made by CHARLES VITERBO
## Login   <viterb_c@epitech.eu>
##
## Started on  Sun Apr 26 18:13:20 2015 CHARLES VITERBO
## Last update Sat Jun 27 19:05:47 2015 CHARLES VITERBO
##

INC_DIR		= ../../include
BIN_DIR		= ../..
PRINTF_DIR	= ../../libs/printf/
UTILS_DIR	= ../utils
ACTIONS_DIR	= actions
MAP_DIR		= map
GFX_DIR		= graphic_cmds

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wall -Wextra -D_BSD_SOURCE -I$(INC_DIR) -I$(INC_DIR)/server
CFLAGS	+= -lmy -L$(PRINTF_DIR)

NAME	= $(BIN_DIR)/zappy_server

SRCS	= $(UTILS_DIR)/check_functions.c \
	  $(UTILS_DIR)/check_sysfunctions.c \
	  $(UTILS_DIR)/check_sysfunctions2.c \
	  $(UTILS_DIR)/get_next_line.c \
	  $(UTILS_DIR)/str_to_wordtab.c \
	  $(UTILS_DIR)/list.c \
	  $(UTILS_DIR)/list2.c \
	  $(UTILS_DIR)/list3.c \
	  $(UTILS_DIR)/nbr.c \
	  $(UTILS_DIR)/conv.c \
	  $(UTILS_DIR)/time.c \
	  $(UTILS_DIR)/log.c\
	  $(ACTIONS_DIR)/available.c \
	  $(ACTIONS_DIR)/broadcast.c \
	  $(ACTIONS_DIR)/dead.c\
	  $(ACTIONS_DIR)/kick.c \
	  $(ACTIONS_DIR)/fork.c \
	  $(ACTIONS_DIR)/incantation.c \
	  $(ACTIONS_DIR)/inventory.c \
	  $(ACTIONS_DIR)/movement.c \
	  $(ACTIONS_DIR)/objects.c \
	  $(ACTIONS_DIR)/show.c \
	  $(ACTIONS_DIR)/annexes_show.c \
	  $(ACTIONS_DIR)/debug.c \
	  $(MAP_DIR)/manipulate_map.c \
	  $(GFX_DIR)/error.c\
	  $(GFX_DIR)/graphic.c\
	  $(GFX_DIR)/egg.c\
	  $(GFX_DIR)/map.c\
	  $(GFX_DIR)/player.c\
	  $(GFX_DIR)/player2.c\
	  $(GFX_DIR)/player3.c\
	  $(GFX_DIR)/server.c\
	  $(GFX_DIR)/team.c\
	  main.c\
	  team.c \
	  close.c \
	  check_fd.c\
	  create_server.c\
	  create_client.c\
	  check_params.c\
	  interpret_message.c \
	  port.c \
	  read.c \
	  send.c \
	  signal.c \
	  welcome.c\

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(PRINTF_DIR)libmy.a

debug: CFLAGS += -g3
debug: re

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
