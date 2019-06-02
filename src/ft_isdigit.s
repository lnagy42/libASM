%include "src/char_type.s"

section .text
    global _ft_isdigit

_ft_isdigit:
    push rbp
    mov rbp, rsp

    CHAR_TYPES ISDIGIT

    leave
    ret