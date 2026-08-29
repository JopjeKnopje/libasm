SECTION .text
global ft_strlen

ft_strlen:
	; init our variable to 0
	xor r10, r10
loop:
	; ZF is set when `RDI + r10` is 0
	cmp byte [rdi + r10], 0
	inc r10
	; jump back to loop when "not zero" aka when ZF is not set.
	jnz loop

	mov rax, r10
	ret
