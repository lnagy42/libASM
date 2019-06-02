%include "src/char_type.s"

section .text
    global _ft_isascii

_ft_isascii:
    push rbp
    mov rbp, rsp

    CHAR_TYPES ISASCII

    leave
    ret