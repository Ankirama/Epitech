##
## Makefile for Makefile in /home/bourde_g/rendu/Piscine-C-lib/my
##
## Made by Gauthier Bourdenx
## Login   <bourde_g@epitech.net>
##
## Started on  Mon Mar 24 10:09:53 2014 Gauthier Bourdenx
## Last update Sat Mar 29 18:23:13 2014 Fabien Martinez
##

SRC	= my_put_nbr.c \
	  my_strcmp.c \
	  my_strlen.c \
	  my_capitalize.c \
	  my_putstr.c \
	  my_strcpy.c \
	  my_strlowcase.c \
	  my_find_prime_sup.c \
	  my_revstr.c \
	  my_str_isalpha.c \
	  my_strncat.c \
	  my_getnbr.c \
	  my_showmem.c \
	  my_str_islower.c \
	  my_strncmp.c \
	  my_isneg.c \
	  my_showstr.c \
	  my_str_isnum.c \
	  my_strncpy.c \
	  my_is_prime.c \
	  my_sort_int_tab.c \
	  my_str_isprintable.c \
	  my_strstr.c \
	  my_power_rec.c \
	  my_square_root.c \
	  my_str_isupper.c \
	  my_strupcase.c \
	  my_putchar.c \
	  my_strcat.c \
	  my_strlcat.c \
	  my_swap.c \
	  my_strdup.c \
	  my_sort_int_tab.c

NAME	= libmy.a

OBJ	= $(SRC:.c=.o)

INCLUDE	= my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp $(NAME) ../../Piscine-C-lib
	cp $(INCLUDE) ../../Piscine-C-include

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re: fclean all
