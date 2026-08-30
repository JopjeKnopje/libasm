extern __errno_location
extern malloc

SECTION .text
global ft_strdup

ft_strdup:
	xor rax, rax
	xor rdi, rdi
	mov edi, DWORD 2048
	; mov edi, message
	call malloc wrt ..plt
	ret

message:
	db "hai", 0
