global ft_strcpy

section .note.GNU-stack
SECTION .text
ft_strcpy:
	xor rcx, rcx
.loop:
	; check if we're at the end of src
	cmp byte [rsi + rcx], 0
	je .done
	mov r10b, [rsi + rcx]
	mov byte [rdi + rcx], r10b
	inc rcx
	jmp .loop

.done:
	mov rax, rdi
	ret
