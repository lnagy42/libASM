%include "src/char_type.s"

section .text
    global _ft_tolower

_ft_tolower:
    push rbp
    mov rbp, rsp

    CHAR_TYPES ISUPPER
    jz end
    add rdi, 32
end:
    mov rax, rdi
    leave
    ret