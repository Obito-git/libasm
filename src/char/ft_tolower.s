global ft_tolower

section .text
ft_tolower:
    mov eax, edi
    cmp eax, 'A'
    jl .return_same
    cmp eax, 'Z'
    jg .return_same
    xor eax, 0x20
    ret

.return_same:
    ret