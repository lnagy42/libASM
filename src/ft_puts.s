%include "src/char_type.s"
%define MACH_SYSCALL(val) 0x2000000 | val
%define WRITE 4
%define STDOUT 1

section .text
    global _ft_puts
    extern _ft_strlen

; ssize_t write(int fildes, const void *buf, size_t nbyte)
_ft_puts:
    push rbp
    mov rbp, rsp

    sub rsp, 8
    push rdi
    call _ft_strlen
    pop rsi
    add rsp, 8

    mov rdx, rax
    mov rdi, STDOUT
    mov rax, MACH_SYSCALL(WRITE)
    syscall

    leave
    ret