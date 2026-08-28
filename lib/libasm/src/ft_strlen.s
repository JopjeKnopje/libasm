SECTION .text
global ft_strlen

ft_strlen:
	; init our variable to 0
	mov r10, 0
loop:
	; get char value from pointer passed into the function.
	mov rbx, [rax + r10]
	; increment our counter.
	add r10, 1
	; ZF gets set when `BX` is 0
	cmp rbx, 0
	; jump back to loop when "not zero" aka when ZF is not set.
	jnz loop

	mov rax, r10
	ret

