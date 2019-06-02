%include "src/char_type.s"

section .text
    global _ft_isblank

_ft_isblank:
    push rbp
    mov rbp, rsp

    CHAR_TYPES ISBLANK

    leave
    ret