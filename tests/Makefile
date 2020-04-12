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

TEST_SRC		=	sources/
REC_FUNC		=	generic/

ROOT_PATH		=	../
I_PATH			=	include/
LIB_PATH		=	$(ROOT_PATH)lib/
LIB_I_PATH		=	$(LIB_PATH)my/$(I_PATH)
SOURCE_PATH		=	$(ROOT_PATH)sources/
SOURCE_LIB		= 	$(ROOT_PATH)sources/libsrc/
SOURCE_I_PATH	=	$(ROOT_PATH)$(I_PATH)

override CFLAGS	    +=	-W -Wall -Wextra -Wextra -I./$(I_PATH) -I./$(SOURCE_I_PATH) -I./$(LIB_I_PATH) --coverage
override LDFLAGS    += 	-L./$(SOURCE_LIB) -L./$(LIB_PATH)
override LDLIBS     +=	-lcriterion -lsrc -lmy

SRC 	= 	$(REC_FUNC)redirect.c

OBJ 	= 	$(SRC:.c=.o)

$(NAME): $(OBJ)
	$(PRINT) "\n------->\tCOMPILED TESTS SRC DEPENDECIES.\n"
	@$(MAKE) -C $(LIB_PATH) $(ADD_COVERAGE) $(ADD_LCRITERION)
	@$(MAKE) $(LIB) -C $(SOURCE_PATH) $(ADD_COVERAGE) $(ADD_LCRITERION)
	$(LD) $^ -o $@ $(CFLAGS) $(LDFLAGS) $(LDLIBS)
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