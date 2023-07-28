section .data
	hello db 'Hello, Holberton,', 0   ; Null-terminated string

section .text
	global main
	extern printf

main:
	; Prepare arguments for printf
	mov rdi, hello  ; Format string
	call printf     ; Call printf function

	; Exit the program
	mov rax, 60     ; System call number for exit
	xor rdi, rdi    ; Exit status 0
	syscall         ; Invoke syscall to exit the program
