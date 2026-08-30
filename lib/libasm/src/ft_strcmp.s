SECTION .text
global ft_strcmp

; rdi dst
; rsi src
ft_strcmp:
	xor rcx, rcx
.loop:
	; move s1 into a tmp register
	mov r10, [rdi + rcx]
	; sub s1 from s2 and store result in s1
	sub r10, [rsi + rcx]

	cmp r10, 0
	jnz .done

	mov byte r10, [rsi + rcx]
	mov qword [rdi + rcx], byte r10
	inc rcx
	jmp .loop

.done:
	mov rax, r10
	ret
