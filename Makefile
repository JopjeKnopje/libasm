NAME = app

LIB_ASM		:= lib/libasm.so

CFLAGS		:= -Wall -Wextra -Werror
# CFLAGS += -g -fsanitize=address

INC         := -Iinclude 


SRC_DIR   := src
SRC_FILES := main.c

SRC_LIST := $(addprefix $(SRC_DIR)/, $(SRC_FILES))


OBJ_DIR  := obj
OBJ_LIST := $(patsubst $(SRC_DIR)%.s, $(OBJ_DIR)%.o, $(SRC_LIST))


all: lib_asm $(NAME)

$(NAME): $(OBJ_LIST)
	$(CC) $(OBJ_LIST) $(LIB_ASM) $(CFLAGS) $(INC) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<


.PHONY: lib_asm
lib_asm:
	$(MAKE) -C lib

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

compile_commands:
	$(MAKE) | compiledb

