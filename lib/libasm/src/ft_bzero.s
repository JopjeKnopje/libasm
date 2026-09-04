global ft_bzero

section .note.GNU-stack
section .text
ft_bzero:
	; zero our counter
	xor rcx, rcx
.loop:
	; if counter is greater or equal to rsi
	cmp rcx, rsi
	jge .exit

	mov byte [rdi + rcx], 0
	inc rcx
	jmp .loop
.exit:
	; return the counter for debugging, the function signature has `void` so this will be ignored.
	mov rax, rcx
	ret
