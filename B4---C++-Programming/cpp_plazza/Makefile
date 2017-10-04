##
## Makefile for  in /home/teyssa_r/rendu/cpp_plazza
## 
## Made by Raphael Teyssandier
## Login   <teyssa_r@epitech.net>
## 
## Started on  Thu Apr 16 21:18:05 2015 Raphael Teyssandier
## Last update Sun Apr 26 04:11:36 2015 Alexandre Chenevier
##

CXX	= g++

RM	= rm -f

NAME	= plazza

LDFLAGS	= -lpthread -lQtCore -lQtGui -std=c++11

CXXFLAGS = -W -Wall -Werror -I./includes -I/usr/include/Qt -I/usr/include/QtGui -g3
CXXFLAGS+= -I/usr/include/QtCore -I/usr/share/qt4/mkspecs/default -I.

DIR	= src

POSIX	= $(DIR)/posix

GRAPHIC	= $(DIR)/graphic

SRCS	= $(DIR)/main.cpp \
	  $(DIR)/Log.cpp \
	  $(POSIX)/PInNamedPipe.cpp \
	  $(POSIX)/POutNamedPipe.cpp \
	  $(POSIX)/PCondVar.cpp \
	  $(POSIX)/PMutex.cpp \
	  $(POSIX)/PScopedLock.cpp \
	  $(POSIX)/PThread.cpp \
	  $(DIR)/Ingredient.cpp \
	  $(DIR)/Pizzas.cpp \
	  $(DIR)/Kitchen.cpp \
	  $(GRAPHIC)/Graphic.cpp \
	  $(DIR)/Parser.cpp \
	  $(DIR)/Pizza.cpp \
	  $(GRAPHIC)/moc_Graphic.cpp \
	  $(DIR)/Cook.cpp \
	  $(DIR)/Command.cpp \
	  $(DIR)/Stock.cpp \

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)

$(GRAPHIC)/moc_Graphic.cpp: includes/Graphic.hh

$(GRAPHIC)/moc_Graphic.cpp: includes/Graphic.hh
	moc -o $(GRAPHIC)/moc_Graphic.cpp includes/Graphic.hh

clean:
	$(RM) $(OBJS)
	$(RM) $(GRAPHIC)/moc_Graphic.cpp

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean
