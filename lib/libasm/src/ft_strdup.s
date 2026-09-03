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
	; keep track of the input string
	mov r10, rdi
	; get the
	call ft_strlen
	; get the return value of `ft_strlen` and store pass to malloc

	; move strlen result into r11
	mov r11, rax
	; add space for NULL terminator
	inc r11

	; add another 8 bytes for stack allignment, so we have 16
	sub rsp, 8
	mov rdi, r11
	call malloc wrt ..plt

	; rdi address
	; move the malloc return addr into rdi
	mov rdi, rax
	; rsi size N
	mov rsi, r11
	call bzero wrt ..plt

	add rsp, 8

	ret

	; call ft_bzero
	; ret


	; ; mov the malloc'ed address into rdi.
	; mov rdi, rax
	; mov rsi, r10
	; call ft_strcpy
	; ret

message:
	db "hai", 0
