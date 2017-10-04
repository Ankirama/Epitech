##
## Makefile for Makefile in /home/ankirama
##
## Made by Fabien martinez
## Login   <fabien.martinez@epitech.eu>
##
## Started on  Sun Feb 27 10:48:37 2015 Fabien martinez
## Last update Fri Jun 26 03:32:35 2015 Raphael Teyssandier
##

SERVER_DIR 	= src/server
CLIENT_DIR 	= src/client
CLIGRP_DIR 	= src/client_graph
PRINTF_DIR	= libs/printf

SERVER_NAME	= $(SERVER_DIR)/server
CLIENT_NAME	= $(CLIENT_DIR)/client
CLIGRP_NAME	= $(CLIGRP_DIR)/client

all:
	make -C $(PRINTF_DIR)
	make -C $(SERVER_DIR)
	make -C $(CLIENT_DIR)
	make -C $(CLIGRP_DIR)

debug:
	make -C $(PRINTF_DIR) debug
	make -C $(SERVER_DIR) debug
	make -C $(CLIGRP_DIR) debug

zappy_ai:
	make -C $(PRINTF_DIR)
	make -C $(CLIENT_DIR)

zappy_server:
	make -C $(PRINTF_DIR)
	make -C $(SERVER_DIR)

zappy_graph:
	make -C $(CLIGRP_DIR)

clean:
	make -C $(PRINTF_DIR) clean
	make -C $(SERVER_DIR) clean
	make -C $(CLIENT_DIR) clean
	make -C $(CLIGRP_DIR) clean

fclean:
	make -C $(PRINTF_DIR) fclean
	make -C $(SERVER_DIR) fclean
	make -C $(CLIENT_DIR) fclean
	make -C $(CLIGRP_DIR) fclean

re: fclean all

.PHONY: all zappy_server zappy_graph zappy_graph clean fclean re
