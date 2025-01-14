global ft_strcmp

section .text
ft_strcmp:
    xor rcx, rcx                ; Initialize counter (index) to 0

.loop:
    mov al, byte [rdi + rcx]    ; Load byte from the first string into al
    mov bl, byte [rsi + rcx]    ; Load byte from the second string into bl
    cmp al, bl                  ; Compare the two bytes
    jne .not_equal_ret          ; If they are not equal, jump to .not_equal_ret

    cmp al, 0                   ; Check if we've reached the null terminator
    je .equal_ret               ; If yes, strings are equal, jump to .equal_ret

    inc rcx                     ; Increment the counter (move to the next byte)
    jmp .loop                   ; Repeat the loop

.not_equal_ret:
    xor rax, rax                ; Clear rax (prepare for result)
    mov al, byte [rdi + rcx]    ; Load differing byte from the first string into al
    sub al, byte [rsi + rcx]    ; Subtract the differing byte from the second string
    movsx rax, al               ; Sign-extend the result to 64-bit (rax)
    ret                         ; Return the result (difference between the two bytes)

.equal_ret:
    xor rax, rax                ; Set rax to 0 (strings are equal)
    ret                         ; Return 0
