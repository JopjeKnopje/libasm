global ft_strcmp

section .note.GNU-stack
section .text
ft_strcmp:
	xor rcx, rcx
.loop:
	; move s1 into a 16-bit register, the reason we need a 16-bit reg instead of a 8-bit.
	; is because when we `SUB` we might get a signed bit, which needs to fit in the resulting register.
	movzx r10w, byte [rdi + rcx]
	movzx r11w, byte [rsi + rcx]
	; sub s1 from s2 and store result in s1.
	sub r10w, r11w
	; check if there was a diff between s1 and s2.
	cmp r10w, 0
	jnz .exit

	inc rcx
	jmp .loop
.exit:
	; move preserving the sign bit
	movsx rax, r10w
	ret
