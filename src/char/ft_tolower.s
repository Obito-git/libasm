global ft_tolower

section .text
ft_tolower:
    mov eax, edi
    cmp eax, 0x41
    jl .return_same
    cmp eax, 0x5A
    jg .return_same
    xor eax, 0x20
    ret

.return_same:
    ret