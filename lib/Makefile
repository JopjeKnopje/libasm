NAME := libasm.so

SRC_DIR := src
OBJ_DIR := obj


SRC_FILES := ft_strlen.s


SRC_LIST := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ_LIST := $(patsubst $(SRC_DIR)%.s, $(OBJ_DIR)%.o, $(SRC_LIST))


$(NAME): $(OBJ_LIST)
	ar rcs $(NAME) $(OBJ_LIST)



$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s $(OBJ_DIR) 
	nasm -o $@ $< -f elf64

$(OBJ_DIR):
	@mkdir -p $@

.PHONY: test
test:
	echo $(SRC_LIST)
	echo $(OBJ_LIST)

