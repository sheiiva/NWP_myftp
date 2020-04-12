##
## EPITECH PROJECT, 2019
## TESTS
## File description:
## MAKEFILE
##

NAME 	= 	critests

CC		= 	gcc
LD		=	$(CC)

LIB			=	lib
PRINT		=	@echo -e
RM			=	@rm -f

ADD_COVERAGE	=	'CFLAGS	+=	--coverage'
ADD_LCRITERION	=	'LDLIBS	+=	-lcriterion'

ROOT_PATH		=	../
I_PATH			=	include/
SERVER_PATH		=	$(ROOT_PATH)server/
SERVER_LIB		= 	$(SERVER_PATH)libsrc/
SERVER_I_PATH	=	$(SERVER_PATH)$(I_PATH)
CLIENT_PATH		=	$(ROOT_PATH)client/
CLIENT_LIB		= 	$(CLIENT_PATH)libsrc/
CLIENT_I_PATH	=	$(CLIENT_PATH)$(I_PATH)


override CFLAGS	    +=	-W -Wall -Wextra -Wextra -I./$(SERVER_I_PATH) -I./$(CLIENT_I_PATH) --coverage
override LDFLAGS    += 	-L./$(SERVER_LIB) -L./$(CLIENT_LIB)
override LDLIBS     +=	-lcriterion -lserver -lclient


TEST_SRC		=	sources/
REC_FUNC		=	generic/

SRC 	= 	$(REC_FUNC)redirect.c

OBJ 	= 	$(SRC:.c=.o)


$(NAME): $(OBJ)
	$(PRINT) "\n------->\tCOMPILED TESTS SRC DEPENDECIES.\n"
	$(MAKE) $(LIB) -C $(SERVER_PATH) $(ADD_COVERAGE) $(ADD_LCRITERION)
	$(MAKE) $(LIB) -C $(CLIENT_PATH) $(ADD_COVERAGE) $(ADD_LCRITERION)
	$(PRINT) "\n------->\tLET'S LINK IT ALL.\n"
	$(LD) $^ -o $@ $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	$(PRINT) "\n------->\tCONGRATS!"
	$(PRINT) "\n\n"
	./$(NAME)
	$(PRINT) "\n\n"

all: $(NAME)

clean:
	$(PRINT) "\n------->\tREMOVE TESTS TMP FILES\n"
	$(RM) $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean: clean
	$(PRINT) "------->\tREMOVE TESTS\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re