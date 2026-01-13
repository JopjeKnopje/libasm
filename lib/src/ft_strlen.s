; make `_test_func` a global symbol to expose it to the linker
global test_func

test_func:
	mov rax, 60
	mov rdi, 2
	syscall

