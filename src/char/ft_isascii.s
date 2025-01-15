global ft_isascii

section .text
ft_isascii:
    cmp edi, 0x0      
    jl .return_false
    cmp edi, 0x7F
    jg .return_false

    mov eax, 1
    ret

.return_false:
    xor eax, eax
    ret
