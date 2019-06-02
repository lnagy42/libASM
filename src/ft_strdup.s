%define MACH_SYSCALL(val) (0x2000000 | val)
%define WRITE 4

section .text
global _ft_strdup
extern _ft_strlen
extern _malloc
extern _ft_memcpy

; char	*ft_strdup(const char *s1)
                        ; rdi
_ft_strdup:
    push rbp
    mov rbp, rsp

    push rdi                ; keep rdi's pointer
    call _ft_strlen

    inc rax                 ; inc len + 1 for \0
    push rax                ; keep len
    mov rdi, rax            ; set rdi to len
    call _malloc
    cmp rax, 0
    jz _end
    pop rdx                 ; take back len in rdx for memcpy

    pop rsi                 ; take back src for memcpy
    mov rdi, rax            ; mov malloc's return in rdi -> dest of memcpy
    call _ft_memcpy

_end:
    leave
    ret


