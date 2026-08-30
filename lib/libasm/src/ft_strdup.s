extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy
extern ft_bzero

SECTION .text
global ft_strdup

ft_strdup:
	; keep track of the input string
	mov r10, rdi
	; get the
	call ft_strlen
	; get the return value of `ft_strlen` and store pass to malloc
	inc rax
	mov r11, rax
	mov rdi, rax
	; add space for NULL terminator
	call malloc wrt ..plt

	; rdi address
	; rsi size N
	; move the malloc return addr into rdi
	mov rdi, rax
	; move the strlen return into rsi
	mov rsi, r11
	call ft_bzero


	; ; mov the malloc'ed address into rdi.
	; mov rdi, rax
	; mov rsi, r10
	; call ft_strcpy
	; ret

message:
	db "hai", 0
