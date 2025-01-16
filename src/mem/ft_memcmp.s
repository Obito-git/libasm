global ft_memcmp

section .text
ft_memcmp:
    xor rcx, rcx                    ; initialize counter

.loop:
    cmp rcx, rdx                    ; cmp counter with 3rd arg
    jge .return_equal
    
    movzx rax, byte [rdi + rcx]     ; load 1st arg's unsigned byte to rax
    movzx rbx, byte [rsi + rcx]     ; load 2nd arg's unsigned byte to rbx
    cmp rax, rbx
    jne .return_not_equal

    inc rcx
    jmp .loop

.return_not_equal:
    sub rax, rbx
    ret

.return_equal:
    xor rax, rax
    ret