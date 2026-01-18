NAME		:= libasm.a

SRC_DIR		:= src
SRC_FILES	:= ft_write.s
SRC_LIST	:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR		:= obj
OBJ_LIST	:= $(patsubst $(SRC_DIR)%.s, $(OBJ_DIR)%.o, $(SRC_LIST))


$(NAME): $(OBJ_LIST)
	ar rcs $(NAME) $(OBJ_LIST)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	nasm -o $@ $< -f elf64

$(OBJ_DIR):
	mkdir -p $@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean 
	$(MAKE)
