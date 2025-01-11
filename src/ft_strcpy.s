global ft_strcpy

section .text
ft_strcpy:
    mov rax, rdi ;; copy dest (first arg) to return value
    xor rcx, rcx ;; initialize counter to 0

.loop:
    mov dl, byte [rsi + rcx]  ; Load byte from source
    mov byte [rax + rcx], dl  ; Store byte to destination
    cmp dl, 0                 ; Check if the byte is a null terminator
    je .done                  ; If it is, we're done
    inc rcx                   ; Increment counter
    jmp .loop                 ; Repeat

.done:
    ret
