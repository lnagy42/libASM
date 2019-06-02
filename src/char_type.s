%ifndef CHAR_TYPES_S
%define CHAR_TYPES_S

%define ISUPPER 0b00000001
%define ISLOWER 0b00000010
%define ISDIGIT 0b00000100
%define ISPRINT 0b00001000
%define ISASCII 0b00010000
%define ISBLANK 0b00100000
%define ISSPACE 0b01000000

section .text
extern char_table

%macro CHAR_TYPES 1
    mov rax, 0                      ;set return to 0
    cmp rdi, 127                    ;check if is ascii
    jg char_type_end                ;jmp if greater

    lea rax, [rel char_table]       ;load char table
    movzx rax, byte[rax + rdi]      ; == add rax, rdi
char_type_end:
    and al, %1                      ;apply mask and store result in al | %1 == first arg of macro
    setnz al                        ;42FileChecker (al ? 1 : 0)
%endmacro

%endif