global ft_strcmp

section .note.GNU-stack
section .text

ft_strcmp:
	xor rcx, rcx
.loop:
	movzx r10w, byte [rdi + rcx]
	movzx r11w, byte [rsi + rcx]

	inc rcx

	; check if chars in string match
	cmp r10w, r11w
	jne .exit

	; check if chars are \0
	cmp r10w, 0
	je .exit

	jmp .loop
.exit:
	; move preserving the sign bit
	sub r10w, r11w
	movsx rax, r10w
	ret
