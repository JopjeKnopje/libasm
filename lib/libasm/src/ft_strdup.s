extern __errno_location
extern malloc
extern bzero
extern ft_strlen
extern ft_strcpy
extern ft_bzero

SECTION .text
global ft_strdup
; inherently 8 bytes op stack
ft_strdup:
	xor rax, rax
	; save input string on stack
	push qword rdi
	call ft_strlen
	; get the return value of `ft_strlen` and store pass to malloc
	; space for NULL terminator
	inc rax
	mov rdi, rax
	call malloc wrt ..plt

	; mov the malloc'ed address into rdi.
	mov rdi, rax
	pop qword rsi
	call ft_strcpy
	ret


message:
	db "hai", 0
