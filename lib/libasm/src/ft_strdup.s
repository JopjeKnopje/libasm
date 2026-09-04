extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy

global ft_strdup

section .note.GNU-stack
section .text
ft_strdup:
	; zero output regiser
	xor rax, rax
	; save input string on stack
	push rdi
	call ft_strlen

	; space for NULL terminator
	inc rax
	mov rdi, rax
	call malloc wrt ..plt

	mov rdi, rax
	pop rsi
	call ft_strcpy
	ret
