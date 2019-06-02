%define MACH_SYSCALL(val) (0x2000000 | val)
%define READ 3
%define WRITE 4
%define CLOSE 5
%define STDOUT 1
%define BUFF_SIZE 1

section .bss
buffer: resb BUFF_SIZE

section .text
global _ft_cat

; ssize_t write(int fd, void *buf, size_t count)
               ; rdi        rsi         rdx

; void cat(int fd)
            ; rdi
_ft_cat:
    push rbp
    mov rbp, rsp

read:
    push rdi
    lea rsi, [rel buffer]
    mov rdx, BUFF_SIZE
    mov rax, MACH_SYSCALL(READ)
    syscall
    jc end
    cmp rax, 0
    jle end

    mov rdi, STDOUT
    mov rdx, rax
    mov rax, MACH_SYSCALL(WRITE)
    syscall
    pop rdi
    jmp read

end:
    leave
    ret


