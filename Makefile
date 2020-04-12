##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## ROOT
##

NAME		=	ALL_RULE
CLIENT 		= 	CLIENT_RULE
SERVER 		= 	SERVER_RULE

SERVER_PATH	=	server/
CLIENT_PATH	=	client/
TST_PATH	=	tests/

CLEAN		=	clean
FCLEAN		=	fclean

$(NAME):
	@$(MAKE) -C $(SERVER_PATH)
	@$(MAKE) -C $(CLIENT_PATH)

all: $(NAME)

$(CLIENT):
	@$(MAKE) -C $(CLIENT_PATH)

client: $(CLIENT)

$(SERVER):
	@$(MAKE) -C $(SERVER_PATH)

server: $(SERVER)

clean:
	@$(MAKE) $(CLEAN) -C $(SERVER_PATH)
	@$(MAKE) $(CLEAN) -C $(CLIENT_PATH)
	@$(MAKE) $(CLEAN) -C $(TST_PATH)

fclean:
	@$(MAKE) $(FCLEAN) -C $(SERVER_PATH)
	@$(MAKE) $(FCLEAN) -C $(CLIENT_PATH)
	@$(MAKE) $(FCLEAN) -C $(TST_PATH)

re: fclean all

tests_run: fclean
	@$(MAKE) -C $(TST_PATH)

.PHONY: all clean fclean re tests_run server client
