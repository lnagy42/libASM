%define MACH_SYSCALL(val) (0x2000000 | val)
%define WRITE 4

section .text
global _ft_strlen:

_ft_strlen:

    push rbp
    mov rbp, rsp        ; stack pointer in base pointer so we point on the last stack item

    xor al, al          ; clear al so we're sure its empty for scasb
    mov rcx, -1         ; max of size_t 
    cld                 ; met le flag de direction a 0
    repne scasb         ; while ([rdi] != al), keep scanning

    not rcx
    lea rax, [rcx - 1]

    leave               ; in this case leave == pop rbp
    ret
