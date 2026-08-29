SECTION .text
global ft_strlen

ft_strlen:
	; init our variable to 0
	cmp rdi, 0
	jz end
	xor r10, r10
loop:
	; get char value from pointer passed into the function.
	; mov rbx, [rdi + r10]
	; increment our counter.
	inc r10
	; ZF gets set when `BX` is 0
	cmp byte [rdi + r10], 0
	; jump back to loop when "not zero" aka when ZF is not set.
	jnz loop

	mov rax, r10
	ret

end:
	mov rax, 0
	ret
