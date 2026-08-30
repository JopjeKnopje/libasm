extern __errno_location
extern malloc

SECTION .text
global ft_strdup

ft_strdup:
	mov rax, 2048
	call malloc wrt ..plt
	ret
