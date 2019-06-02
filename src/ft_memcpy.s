%include "src/char_type.s"

section .text
    global _ft_memcpy
    extern _malloc
    extern _ft_strlen

; *memcpy(void *dest, const void *src, size_t n);
;           rdi         rsi              rdx
_ft_memcpy:
    push rbp
    mov rbp, rsp

    push rdi
    mov rcx, rdx
    rep movsb
    pop rax

_end:
    leave
    ret

