global ft_isspace

section .text

; Somehow my nasm doesn't translate properly char to ascii val
ft_isspace:
    xor eax, eax

    cmp edi, 0x0C    ; '\f'
    je .return_true

    cmp edi, 0x09    ; '\t'
    je .return_true

    cmp edi, 0x20    ; ' ' 
    je .return_true

    cmp edi, 0x0A    ; '\n' 
    je .return_true

    cmp edi, 0x0D    ; '\r' 
    je .return_true

    cmp edi, 0x0B    ; '\v' 
    je .return_true

    ret

.return_true:
    mov eax, 1
    ret
