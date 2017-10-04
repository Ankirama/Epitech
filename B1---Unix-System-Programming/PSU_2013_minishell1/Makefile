##
## Makefile for Makefile in /home/mar_b/rendu/PSU_2013_minishell1
##
## Made by mar_b mar_b
## Login   <mar_b@epitech.net>
##
## Started on  Mon Jun 16 02:53:30 2014 mar_b mar_b
## Last update Sun Jun 22 14:45:38 2014 mar_b mar_b
##

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

LDFLAGS	= -I.

NAME	= mysh

SRCS	= main.c\
	  my_error.c\
	  my_exec.c\
	  my_set_var.c\
	  my_list.c\
	  my_list2.c\
	  my_str.c\
	  my_env.c\
	  my_check.c\
	  my_fun.c\
	  my_pwd.c\
	  my_free.c\
	  my_builtin.c\
	  my_str_to_wordtab.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
