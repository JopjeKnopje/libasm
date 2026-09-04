global ft_strlen

section .note.GNU-stack
section .text
ft_strlen:
	; init our variable to 0
	xor rax, rax
.loop:
	; ZF is set when `RDI + RAX` is 0
	cmp byte [rdi + rax], 0
	je .done
	inc rax
	jmp .loop

.done
	ret
