SECTION .text
global ft_strcmp

ft_strcmp:
	xor rcx, rcx
.loop:
	; move s1 into a tmp register.
	mov r10b, byte [rdi + rcx]
	; sub s1 from s2 and store result in s1.
	sub r10b, byte [rsi + rcx]
	; check if there was a diff between s1 and s2.
	cmp r10b, 0
	jnz .exit

	inc rcx
	jmp .loop

.exit:
	mov al, r10b
	ret
