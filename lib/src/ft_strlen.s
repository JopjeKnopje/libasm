; make `_start` a global symbol to expose it to the linker
global _test_func

_test_func:
	mov rax, 60
	mov rdi, 2
	syscall
