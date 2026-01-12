NAME := app

$(NAME): src/main.s
	nasm src/main.s -o $(NAME) -f elf64
	chmod +x $(NAME)
