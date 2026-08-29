extern __errno_location

SECTION .text
global ft_read

ft_read:
	mov rax, 0
	syscall
	cmp rax, 0
	jl .error
	ret

.error:
	; we need to grab the abs return code from the write syscall
	neg rax
	; save the abs in `rax`
	mov rdi, rax
	; get the address of `errno`
    call __errno_location wrt ..plt
	; de-reference the address and write our error code to it
    mov [rax], rdi
	; return -1
	mov rax, -1
	ret

