%include "src/char_type.s"
%define MACH_SYSCALL(val) 0x2000000 | val
%define WRITE 4
%define STDOUT 1

section .text
    global _ft_putchar_fd

_ft_putchar_fd:
    push rbp
    mov rbp, rsp

    push rdi
    mov rdi, rsi
    lea rsi, [rsp]
    mov rdx, 1
    mov rax, MACH_SYSCALL(WRITE)
    syscall
    pop rdi

    leave
    ret
