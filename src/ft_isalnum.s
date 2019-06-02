%include "src/char_type.s"

section .text
    global _ft_isalnum

_ft_isalnum:
    push rbp
    mov rbp, rsp

    CHAR_TYPES ISDIGIT | ISLOWER | ISUPPER

    leave
    ret