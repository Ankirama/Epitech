##
## Makefile for Makefile in /home/ankirama
## 
## Made by Fabien martinez
## Login   <ankirama@epitech.net>
## 
## Started on  Sun Feb 27 10:48:37 2015 Fabien martinez
## Last update Fri Mar  6 22:33:28 2015 Fabien martinez
##

SERVER_DIR 	= src/server
CLIENT_DIR 	= src/client
PRINTF_DIR	= libs/printf

SERVER_NAME	= $(SERVER_DIR)/server
CLIENT_NAME	= $(CLIENT_DIR)/client

all:
	make -C $(PRINTF_DIR)
	make -C $(SERVER_DIR)
	make -C $(CLIENT_DIR)

client:
	make -C $(PRINTF_DIR)
	make -C $(CLIENT_DIR)

server:
	make -C $(PRINTF_DIR)
	make -C $(SERVER_DIR)

clean:
	make -C $(PRINTF_DIR) clean
	make -C $(SERVER_DIR) clean
	make -C $(CLIENT_DIR) clean

fclean:
	make -C $(PRINTF_DIR) fclean
	make -C $(SERVER_DIR) fclean
	make -C $(CLIENT_DIR) fclean

re: fclean all

.PHONY: all client server clean fclean re
