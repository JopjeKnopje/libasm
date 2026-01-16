SECTION .rodata
msg: db "Test 123", 10
msg_len: equ $-msg

SECTION .text
; make `_test_func` a global symbol to expose it to the linker
global ft_write


; ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ft_write:
	mov rax, 1
	mov rdi, 1
	mov	rsi, $msg
	mov rdx, $msg_len
	syscall
	ret ; rax or rdx
