global ft_memcpy

section .text
ft_memcpy:
    mov rax, rdi

    test rdx, rdx
    jz .return

    dec rdx

.loop:
    mov bl, byte [rsi + rdx]
    mov byte [rdi + rdx], bl

    dec rdx                     ; sets Sign Flag (SF) when it becomes unsigned
    jns .loop                   ; jump not signed

.return:
    ret
