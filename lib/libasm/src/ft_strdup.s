extern __errno_location
extern malloc
extern bzero
extern ft_strlen
extern ft_strcpy
extern ft_bzero

SECTION .text
global ft_strdup
ft_strdup:
	xor rax, rax
	; save input string on stack
	mov r13, rdi
	call ft_strlen
	; space for NULL terminator
	inc rax
	mov rdi, rax
	call malloc wrt ..plt

	; mov the malloc'ed address into rdi.
	mov rdi, rax
	; get rsi input string
	mov rsi, r13
	; add rsp, 8
	call ft_strcpy
	ret


message:
	db "hai", 0
