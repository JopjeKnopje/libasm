SECTION .text
global ft_strlen

ft_strlen:
	; init our variable to 0
	mov r10, 0
loop:
	add r10, 1
	mov bx, [rax + r10]
	; ZF gets set when `BX` is 0
	cmp bx, 0
	; jump back to loop when "not zero" aka when ZF is not set.
	jnz loop

	mov rax, r10
	ret

