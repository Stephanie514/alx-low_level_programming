section .data
    hello db "Hello, Holberton", 0
    format db "%s", 10, 0

section .text
    extern printf

global main
main:
    ; Prepare arguments for printf
    mov rdi, format
    mov rsi, hello
    xor rax, rax  ; Clear rax register

    ; Call printf
    call printf

    ; Exit the program
    mov eax, 0x60  ; Exit syscall number
    xor edi, edi   ; Exit status 0
    syscall

