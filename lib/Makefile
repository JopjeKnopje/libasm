NAME := libasm.so

SRC_DIR := src
OBJ_DIR := obj


SRC_FILES := ft_strlen.s


SRC_LIST := $(addprefix($(SRC_DIR)/, $(SRC_FILES)))
OBJ_LIST = $(patsubst $(SRC_DIR)%.s, $(OBJ_DIR)%.o, $(SRCS))


$(NAME): $(OBJ_DIR) $(OBJ_LIST)
	ar rcs $(NAME) $(OBJ_LIST)
	nasm src/main.s -o obj/main.o -f elf64
	# ld obj/main.o -o app


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
