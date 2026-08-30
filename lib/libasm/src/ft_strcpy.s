extern __errno_location

SECTION .text
global ft_strcpy

; rdi dst
; rsi src
ft_strcpy:
	xor rcx, rcx
.loop:
	; check if we're at the end of src
	cmp byte [rsi + rcx], 0
	je .done
	mov byte r10, [rsi + rcx]
	mov qword [rdi + rcx], byte r10
	inc rcx
	jmp .loop

.done:
	mov rax, rdi
	ret
