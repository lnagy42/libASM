%include "src/char_type.s"

section .text
    global _ft_memset

; *memset (void *s, int c, size_t n);
;           rdi      rsi     rdx
_ft_memset:
    push rbp
    mov rbp, rsp

    push rdi
    mov rcx, rdx
    mov rax, rsi
    rep stosb
    pop rax

    leave
    ret