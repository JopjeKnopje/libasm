NAME		:= app

CFLAGS		:= -Wall -Wextra -Werror
# CFLAGS += -g -fsanitize=address
IFLAGS		:= -I include -I lib/libasm/include


SRC_DIR		:= src
SRC_FILES	:= main.c
SRC_LIST	:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR		:= obj
OBJ_LIST	:= $(patsubst $(SRC_DIR)%.s, $(OBJ_DIR)%.o, $(SRC_LIST))

LIB_ASM		:= lib/libasm/libasm.a


all: lib_asm $(NAME)

$(NAME): lib_asm $(OBJ_LIST)
	$(CC) $(OBJ_LIST) $(LIB_ASM) $(CFLAGS) $(IFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir $(OBJ_DIR)


.PHONY: lib_asm
lib_asm:
	$(MAKE) -C lib/libasm

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
TEST_SRC_FILES	:= test_ft_write.c
TEST_SRC_LIST	:= $(addprefix $(TEST_DIR)/, $(TEST_SRC_FILES))
TEST_BIN_DIR 	:= $(TEST_DIR)/bin
TEST_BIN_LIST	:= $(patsubst $(TEST_DIR)/%.c, $(TEST_BIN_DIR)/%, $(TEST_SRC_LIST))

TEST_UNITY_ROOT	:= lib/Unity
TEST_UNITY_SRC	:= $(TEST_UNITY_ROOT)/src/unity.c
TEST_IFLAGS		:= -I $(TEST_UNITY_ROOT)/src

$(TEST_BIN_DIR):
	mkdir $@

$(TEST_BIN_DIR)/%: $(TEST_DIR)/%.c $(LIB_ASM) | $(TEST_BIN_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) $(TEST_UNITY_SRC) $(TEST_IFLAGS) $< -o $@ $(LIB_ASM) 

.PHONY: test
test: lib_asm $(TEST_BIN_LIST)
	for test in $(TEST_BIN_LIST) ; do ./$$test -j1 ; done
