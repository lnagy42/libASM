%include "src/char_type.s"

section .text
    global _ft_toupper

_ft_toupper:
    push rbp
    mov rbp, rsp

    CHAR_TYPES ISLOWER
    jz end
    sub rdi, 32
end:
    mov rax, rdi
    leave
    ret