##
## Makefile for  in /home/tang_i/temp/zappy/2d
## 
## Made by David Tang
## Login   <tang_i@epitech.net>
## 
## Started on  Fri Jun 19 01:06:59 2015 David Tang
## Last update Sun Jul  5 18:21:15 2015 David Tang
##

INC_DIR		= ../../include
BIN_DIR		= ../../
PRINTF_DIR	= ../../libs/printf/
UTILS_DIR	= ../utils_cpp/
CLIENT_DIR	= ../client

CXX		= g++

RM		= rm -f

CXXFLAGS        = -W -Wall -Wextra -I$(INC_DIR) -I$(INC_DIR)/client_graph

SRCS		= main.cpp \
		  TilesIndex.cpp \
		  Music.cpp \
		  Texture.cpp \
		  CommandEngine.cpp \
		  GameEngine.cpp \
		  Font.cpp \
		  Tile.cpp \
		  CellR.cpp\
		  Item.cpp\
		  $(UTILS_DIR)Network.cpp \
		  $(UTILS_DIR)Parser.cpp \
		  Map.cpp \
		  Character.cpp \
		  HUDVertical.cpp\
		  HUD.cpp \
		  HUDLeft.cpp \

OBJS		= $(SRCS:.cpp=.o)

LIBFLAGS	= -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

NAME		= $(BIN_DIR)zappy_graph

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(LIBFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

debug: CXXFLAGS += -g3
debug: re

re: fclean all

.PHONY:	re fclean clean all
