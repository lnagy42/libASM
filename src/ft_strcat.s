%define MACH_SYSCALL(val) (0x2000000 | val)
%define WRITE 4

section .text
    global _ft_strcat
    extern _ft_strlen

_ft_strcat:
    push rbp
    mov rbp, rsp

    sub rsp, 8
    push rdi
    call _ft_strlen
    pop rdi
    add rsp, 8

    push rdi
    ; lea rdi, [rdi + rax]
    add rdi, rax

    push rdi
    mov rdi, rsi
    call _ft_strlen
    pop rdi

    mov rcx, rax
    inc rcx
    
    cld
    rep movsb
    pop rax

    leave
    ret
