SECTION .text
; make `_test_func` a global symbol to expose it to the linker
global ft_write

ft_write:
	mov rax, 1
	syscall
	mov rax, rdx
	ret
