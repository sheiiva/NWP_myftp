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
SELECT_PATH		=	step4-select/

all:
	@$(MAKE) -C $(SERVER_PATH)
	@$(MAKE) -C $(CLIENT_PATH)
	@$(MAKE) -C $(MULCLIENT_PATH)
	@$(MAKE) -C $(SELECT_PATH)

server:
	@$(MAKE) -C $(SERVER_PATH)

client:
	@$(MAKE) -C $(CLIENT_PATH)

multiple: client
	@$(MAKE) -C $(MULCLIENT_PATH)

select: client
	@$(MAKE) -C $(SELECT_PATH)

clean:
	@$(MAKE) $(CLEAN) -C $(SERVER_PATH)
	@$(MAKE) $(CLEAN) -C $(CLIENT_PATH)
	@$(MAKE) $(CLEAN) -C $(MULCLIENT_PATH)
	@$(MAKE) $(CLEAN) -C $(SELECT_PATH)

fclean:
	@$(MAKE) $(FCLEAN) -C $(SERVER_PATH)
	@$(MAKE) $(FCLEAN) -C $(CLIENT_PATH)
	@$(MAKE) $(FCLEAN) -C $(MULCLIENT_PATH)
	@$(MAKE) $(FCLEAN) -C $(SELECT_PATH)

re: fclean all

.PHONY: all clean fclean re server client multiple