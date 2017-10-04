##
## Makefile for Makefile in /home/mar_b/rendu/PSU_2014_my_printf
##
## Made by Fabien Martinez
## Login   <mar_b@epitech.net>
##
## Started on  Fri Apr 11 13:50:00 2014 Fabien Martinez
## Last update Sun Apr 20 22:37:59 2014 Fabien Martinez
##

UTILS_DIR	= ../../src/utils

AR	= ar rc

RANLIB	= ranlib

CFLAGS	= -W -Wall -Wextra -I. -I../../includes

NAME	= libmy.a

RM	= rm -f

SRCS	= $(UTILS_DIR)/check_sysfunctions.c\
	  my_printf.c \
	  my_putnbr.c \
	  my_check.c \
	  my_perror.c \
	  my_create_ptr.c \
	  my_create_ptr2.c \
	  my_opt_functions.c \
	  my_str.c \
	  my_len.c \
	  my_showstr.c \
	  my_va_nbr.c \
	  my_va_str.c \
	  my_va_nbr_long.c \
	  my_va_nbr_short.c \
	  my_va_base_long.c \
	  my_va_base_short.c \
	  my_va_base.c \
	  my_fun.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
