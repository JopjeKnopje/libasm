// make `_start` a global symbol to expose it to the linker
global _start

_start:
	mov rax, 60
	mov rdi, 2
	syscall
