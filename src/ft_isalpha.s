%include "src/char_type.s"

section .text
    global _ft_isalpha

_ft_isalpha:
    push rbp
    mov rbp, rsp

    CHAR_TYPES ISUPPER | ISLOWER

    leave
    ret