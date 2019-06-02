%include "src/char_type.s"

section .text
    global _ft_isprint

_ft_isprint:
    push rbp
    mov rbp, rsp

    CHAR_TYPES ISPRINT

    leave
    ret