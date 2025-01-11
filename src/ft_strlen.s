global ft_strlen

section .text
ft_strlen:
    xor rax, rax          ; Set RAX to 0 (Rax contains function return value)
.loop:
    cmp byte [rdi + rax], 0  ; Compare the byte at (rdi + rax) with 0
    je .done              ; If zero, jump to .done
    inc rax               ; Increment counter
    jmp .loop             ; Jump back to .loop
.done:
    ret                   ; Return length in RAX
