##
## EPITECH PROJECT, 2019
## SERVER
## File description:
## Makefile
##

ROOT_PATH			=	../
SRC_PATH			=	sources/
INCLUDE_PATH		=	include/
LIBSRC_PATH         =   libsrc/

NAME 		= 	$(ROOT_PATH)myftp
SRC_LIB 	= 	$(LIBSRC_PATH)libserver.a


INCLUDES		=	-I./$(INCLUDE_PATH)				\
					-I./$(INCLUDE_PATH)defines		\

override CFLAGS 	+=	-W -Wall -Werror -Wextra $(INCLUDES)
override LDFLAGS 	+=
override LDLIBS 	+=

COMMANDS_PATH		=	$(SRC_PATH)commands/

TEST_SRC		=	$(SRC_PATH)arguments_handler.c	\
					$(SRC_PATH)client_handler.c	\
					$(SRC_PATH)execute.c			\
					$(SRC_PATH)fd_handler.c			\
					$(SRC_PATH)io_handler.c			\
					$(SRC_PATH)server.c				\
					$(SRC_PATH)socket_handler.c		\
					$(COMMANDS_PATH)cmd_help.c		\
					$(COMMANDS_PATH)cmd_log.c		\
					$(COMMANDS_PATH)cmd_noop.c		\

TESTOBJ		= 	$(TEST_SRC:.c=.o)

SRC				=	$(SRC_PATH)main.c				\
					$(TEST_SRC)

OBJ 		= 	$(SRC:.c=.o)

CC			= 	gcc
LD			=	$(CC)
PRINT		=	@echo -e
RM          =   @rm -f

$(NAME): $(OBJ)
	$(PRINT) "\n------->\tCOMPILED SERVER SRC DEPENDENCIES.\n\nLET'S LINK IT ALL:\n"
	$(LD) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
	$(PRINT) "\n------->\tCONGRATS !\n"

$(SRC_LIB): $(TESTOBJ)
	$(PRINT) "\n------->\tCOMPILED SERVER SRC DEPENDENCIES.\n\nLET'S PACK SERVER LIB:\n"
	@mkdir $(LIBSRC_PATH)
	$(AR) rc $@ $^
	$(PRINT) "\n------->\tCONGRATS ! YOUR SERVER LIB HAS BEEN CREATED.\n"

all: $(NAME)

lib: $(SRC_LIB)

clean:
	$(PRINT) "\n------->\tREMOVE TMP FILES\n"
	$(RM) $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean: clean
	$(PRINT) "------->\tREMOVE BINARY\n"
	$(RM) $(NAME)
	$(PRINT) "------->\tREMOVE SERVER'S LIBRARY\n"
	$(RM) $(SRC_LIB)
	$(RM) -r $(LIBSRC_PATH)

re: fclean all

.PHONY: all clean fclean re