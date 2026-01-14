SECTION .rodata
msg: db "Test 123", 10
msg_len: equ $-msg

SECTION .text
; make `_test_func` a global symbol to expose it to the linker
global ft_strlen

ft_strlen:
	mov eax, 8
	; mov edx, 1
	ret 
