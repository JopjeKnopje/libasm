extern __errno_location



SECTION .text
; make `_test_func` a global symbol to expose it to the linker
global ft_write

ft_write:
	mov rax, 1
	syscall
	; if `rax` is negative we put `-1` in `rax` and set errno to the positive value
	test rax, rax

    call __errno_location wrt ..plt

	; the de-referenced data at address `rax` is `QWORD`
    mov    qword [rax], 123

	ret

__handle_error:
	mov rax, 4
	syscall
