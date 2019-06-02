%include "src/char_type.s"
%define MACH_SYSCALL(val) 0x2000000 | val
%define WRITE 4
%define STDOUT 1

section .text
    global _ft_putchar

_ft_putchar:
    push rbp
    mov rbp, rsp

    push rdi
    lea rsi, [rsp]
    mov rdi, STDOUT
    mov rdx, 1
    mov rax, MACH_SYSCALL(WRITE)
    syscall
    mov rax, rsi

    leave
    ret
