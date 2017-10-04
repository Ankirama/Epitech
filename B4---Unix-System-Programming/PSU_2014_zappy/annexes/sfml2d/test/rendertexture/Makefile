##
## Makefile for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d/test/isomap
## 
## Made by David Tang
## Login   <tang_i@epitech.net>
## 
## Started on  Tue Jun 23 18:49:33 2015 David Tang
## Last update Tue Jun 23 18:49:54 2015 David Tang
##

SRCS		=	main.cpp

OBJS		=	$(SRCS:.cpp=.o)

RM		=	rm -f

CXX		=	g++

CXXFLAGS	=	-W -Wall -Wextra -Iinc

LIBFLAGS	=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

NAME		=	atest

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CXX) -o $(NAME) $(OBJS) $(LIBFLAGS)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	re fclean clean all
