##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## TREE ROOT
##

# RULES
CLEAN	=	clean
FCLEAN	=	fclean

# PATHS
SERVER_PATH		=	step1-server/
CLIENT_PATH		=	step2-client/
MULCLIENT_PATH	=	step3-multiple-clients/

all:
	@$(MAKE) -C $(SERVER_PATH)
	@$(MAKE) -C $(CLIENT_PATH)
	@$(MAKE) -C $(MULCLIENT_PATH)

server:
	@$(MAKE) -C $(SERVER_PATH)

client:
	@$(MAKE) -C $(CLIENT_PATH)

multiple:
	@$(MAKE) -C $(MULCLIENT_PATH)

clean:
	@$(MAKE) $(CLEAN) -C $(SERVER_PATH)
	@$(MAKE) $(CLEAN) -C $(CLIENT_PATH)
	@$(MAKE) $(CLEAN) -C $(MULCLIENT_PATH)

fclean:
	@$(MAKE) $(FCLEAN) -C $(SERVER_PATH)
	@$(MAKE) $(FCLEAN) -C $(CLIENT_PATH)
	@$(MAKE) $(FCLEAN) -C $(MULCLIENT_PATH)

re: fclean all

.PHONY: all clean fclean re server client multiple