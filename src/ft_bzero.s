
%define MACH_SYSCALL(val) 0x2000000 | val
%define WRITE 4
%define STDOUT 1

section .text
    global _ft_bzero:

_ft_bzero:
    mov rcx, rsi
    mov rax, 0
    rep stosb
    ret