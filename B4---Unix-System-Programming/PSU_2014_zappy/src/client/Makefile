##
## Makefile for  in /home/viterb_c/rendu/PSU_2014_zappy/client
##
## Made by CHARLES VITERBO
## Login   <viterb_c@epitech.eu>
##
## Started on  Wed Apr 29 13:22:29 2015 CHARLES VITERBO
## Last update Thu Jul  2 13:49:32 2015 Raphael Teyssandier
##

INC_DIR		= ../../include
BIN_DIR		= ../../
PRINTF_DIR	= ../../libs/printf/
UTILS_DIR	= ../utils_cpp/

CXX	= g++

RM	= rm -f

CXXFLAGS	= -W -Wall -Werror -I$(INC_DIR) -I$(INC_DIR)/client

NAME	= $(BIN_DIR)/zappy_ai

SRCS	= main.cpp \
	  ClientAI.cpp \
	  ParseClient.cpp \
	  $(UTILS_DIR)Network.cpp \
	  $(UTILS_DIR)Parser.cpp \

OBJS	= $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_C)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
