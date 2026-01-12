NAME = app

LIB_ASM		:= lib/libasm.so

CFLAGS		:= -Wall -Wextra -Werror
# CFLAGS += -g -fsanitize=address

IFLAGS         := -Iinclude -Ilib/include


SRC_DIR   := src
SRC_FILES := main.c

SRC_LIST := $(addprefix $(SRC_DIR)/, $(SRC_FILES))


OBJ_DIR  := obj
OBJ_LIST := $(patsubst $(SRC_DIR)%.s, $(OBJ_DIR)%.o, $(SRC_LIST))


all: lib_asm $(NAME)

$(NAME): $(OBJ_LIST)
	$(CC) $(OBJ_LIST) $(LIB_ASM) $(CFLAGS) $(IFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<


.PHONY: lib_asm
lib_asm:
	$(MAKE) -C lib

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) -C lib re

compile_commands:
	$(MAKE) | compiledb


TEST_DIR  	:= unit_tests
TEST_SRC_FILES	:= test_ft_strlen.c
TEST_SRC_LIST 	:= $(addprefix $(TEST_DIR)/, $(TEST_SRC_FILES))
TEST_BIN_DIR 	:= $(TEST_DIR)/bin
TEST_BIN_LIST	:= $(patsubst $(TEST_DIR)/%.c, $(TEST_BIN_DIR)/%, $(TEST_SRC_LIST))


$(TEST_BIN_DIR)/%: $(TEST_DIR)/%.c 
	@mkdir $(TEST_BIN_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) $< -o $@ -lcriterion $(LFLAGS)




test: lib_asm $(TEST_BIN_LIST)
	# for test in $(TEST_BIN_LIST) ; do ./$$test -j1 ; done
	echo $(TEST_BIN_LIST)

