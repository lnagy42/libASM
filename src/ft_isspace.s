%include "src/char_type.s"

section .text
    global _ft_isspace

_ft_isspace:
    push rbp
    mov rbp, rsp

    CHAR_TYPES ISSPACE

    leave
    ret