##
## Makefile for  in /home/teyssa_r/rendu/cpp_abstractvm
## 
## Made by Raphael Teyssandier
## Login   <teyssa_r@epitech.net>
## 
## Started on  Thu Feb 26 13:22:52 2015 Raphael Teyssandier
## Last update Thu Feb 26 13:28:37 2015 Raphael Teyssandier
##

CXX		= g++

RM		= rm -f

NAME		= avm

CXXFLAGS	= -W -Wall -Werror

SRCS		= main.cpp\
	  	  CalculStack.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
