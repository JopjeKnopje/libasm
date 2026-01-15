NAME		:= app

CFLAGS		:= -Wall -Wextra -Werror
# CFLAGS += -g -fsanitize=address
IFLAGS		:= -Iinclude -Ilib/include


SRC_DIR		:= src
SRC_FILES	:= main.c
SRC_LIST	:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR		:= obj
OBJ_LIST	:= $(patsubst $(SRC_DIR)%.s, $(OBJ_DIR)%.o, $(SRC_LIST))

LIB_ASM		:= lib/libasm.a


all: lib_asm $(NAME)

$(NAME): lib_asm $(OBJ_LIST)
	$(CC) $(OBJ_LIST) $(LIB_ASM) $(CFLAGS) $(IFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir $(OBJ_DIR)


.PHONY: lib_asm
lib_asm:
	$(MAKE) -C lib

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re:
	$(MAKE) -C lib re

.PHONY: compile_commands
compile_commands:
	$(MAKE) | compiledb

.PHONY: run
run: all
	./$(NAME)


TEST_DIR  		:= unit_tests
TEST_SRC_FILES	:= test_ft_strlen.c \
				   test_ft_write.c
TEST_SRC_LIST	:= $(addprefix $(TEST_DIR)/, $(TEST_SRC_FILES))
TEST_BIN_DIR 	:= $(TEST_DIR)/bin
TEST_BIN_LIST	:= $(patsubst $(TEST_DIR)/%.c, $(TEST_BIN_DIR)/%, $(TEST_SRC_LIST))

TEST_FILE_NAMES := $(basename $(TEST_SRC_FILES))

_NULL  :=
_SPACE := $(NULL) #
_COMMA := ,

.PHONY: $(subst $(_SPACE), $(_COMMA), $(TEST_FILE_NAMES))
$(TEST_FILE_NAMES): lib_asm
	$(MAKE) $(TEST_BIN_DIR)/$@
	./$(TEST_BIN_DIR)/$@


$(TEST_BIN_DIR):
	mkdir $@

$(TEST_BIN_DIR)/%: $(TEST_DIR)/%.c | $(TEST_BIN_DIR) 
	$(CC) $(CFLAGS) $(IFLAGS)  $< -o $@ $(LIB_ASM) -lcriterion $(LFLAGS)

test: lib_asm $(TEST_BIN_LIST)
	for test in $(TEST_BIN_LIST) ; do ./$$test -j1 ; done
