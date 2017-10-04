##
## Makefile for Makefile in /root/rendu/PSU_2013_minitalk
##
## Made by mar_b mar_b
## Login   <mar_b@epitech.net>
##
## Started on  Mon Aug  4 23:28:41 2014 mar_b mar_b
## Last update Wed Aug  6 19:54:55 2014
##

SERVER_DIR = server
CLIENT_DIR = client

all:
	@make -C $(SERVER_DIR)
	@make -C $(CLIENT_DIR)

clean:
	@(cd $(SERVER_DIR) && $(MAKE) clean)
	@(cd $(CLIENT_DIR) && $(MAKE) clean)

fclean: clean
	@($(RM) $(SERVER_NAM))
	@($(RM) $(CLIENT_NAM))

re: fclean all

.PHONY: all clean fclean re
