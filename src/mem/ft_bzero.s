global ft_bzero

section .text
ft_bzero:
    xor rcx, rcx        ; initialize counter

.loop:
    cmp rcx, rsi
    jge .done
    mov byte [rdi + rcx], 0
    inc rcx
    jmp .loop

.done:
    ret