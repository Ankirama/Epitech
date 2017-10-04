##
## Makefile for Makefile in /home/ankirama
##
## Made by Fabien Martinez
## Login   <ankirama@epitech.net>
##
## Started on  Tue Mar 24 21:43:27 2015 Fabien Martinez
## Last update Fri Mar 27 15:36:16 2015 Fabien Martinez
##

CXX	= g++

RM	= rm -f

DIR	= src

DIR_LIBS = libs

CXXFLAGS = -W -Wall -Wextra -I./includes

LDFLAGS	= -ldl

LIB_1_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

LIB_2_FLAGS = -lncurses

LIB_3_FLAGS = -lGL -lGLU -lglut -lGLEW

NAME	= nibbler

SRCS	= $(DIR)/main.cpp\
	  $(DIR)/DLLoader.cpp\
	  $(DIR)/gameLogic/Food.cpp\
	  $(DIR)/gameLogic/GameLogic.cpp\
	  $(DIR)/gameLogic/PieceSnake.cpp\
	  $(DIR)/gameLogic/Snake.cpp\

SRCS_LIB_1 = $(DIR)/libs/LibSFML.cpp\
	  $(DIR)/gameLogic/Food.cpp\
	  $(DIR)/gameLogic/GameLogic.cpp\
	  $(DIR)/gameLogic/PieceSnake.cpp\
	  $(DIR)/gameLogic/Snake.cpp

SRCS_LIB_2 = $(DIR)/libs/LibNCURSES.cpp\
	  $(DIR)/gameLogic/Food.cpp\
	  $(DIR)/gameLogic/GameLogic.cpp\
	  $(DIR)/gameLogic/PieceSnake.cpp\
	  $(DIR)/gameLogic/Snake.cpp

SRCS_LIB_3 = $(DIR)/libs/LibOPENGL.cpp\
	  $(DIR)/gameLogic/Food.cpp\
	  $(DIR)/gameLogic/GameLogic.cpp\
	  $(DIR)/gameLogic/PieceSnake.cpp\
	  $(DIR)/gameLogic/Snake.cpp

OBJS	= $(SRCS:.cpp=.o)

all:	$(NAME) $(SFML)

$(NAME): $(OBJS)
	 $(CXX) -shared -fPIC -I./includes -o $(DIR_LIBS)/LibSFML.so $(SRCS_LIB_1) $(LIB_1_FLAGS)
	 $(CXX) -shared -fPIC -I./includes -o $(DIR_LIBS)/LibNCURSES.so $(SRCS_LIB_2) $(LIB_2_FLAGS)
	 $(CXX) -shared -fPIC -I./includes -o $(DIR_LIBS)/LibOPENGL.so $(SRCS_LIB_3) $(LIB_3_FLAGS)
	 $(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) $(DIR_LIBS)/LibSFML.o
	$(RM) $(DIR_LIBS)/LibNCURSES.o
	$(RM) $(DIR_LIBS)/LibOPENGL.o

fclean: clean
	$(RM) $(NAME)
	$(RM) $(DIR_LIBS)/LibSFML.so
	$(RM) $(DIR_LIBS)/LibNCURSES.so
	$(RM) $(DIR_LIBS)/LibOPENGL.so

re: fclean all

.PHONY: all clean fclean re
