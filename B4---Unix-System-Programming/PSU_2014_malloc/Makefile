##
## Makefile for malloc in /home/ankirama
## 
## Made by 
## Login   <ankirama@epitech.net>
## 
## Started on  Tue Jan 27 10:25:16 2015 
## Last update Sun Feb 15 10:36:22 2015 
##

CC		= gcc

RM		= rm -f

CFLAGS		= -W -Wall -Wextra -Werror
CFLAGS		+= -fPIC -c -pthread

LDFLAGS		= -shared

NAME		= libmy_malloc_$(HOSTTYPE).so

LINK_NAME	= libmy_malloc.so

SRCS		= free_utils.c\
		  malloc_utils.c\
		  realloc_utils.c\
		  functions.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)
		ln -s $(NAME) $(LINK_NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(LINK_NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
