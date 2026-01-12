NAME := app




$(NAME): src/main.s
	nasm src/main.s -o obj/main.o -f elf64
	ld obj/main.o -o app 
