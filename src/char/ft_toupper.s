global ft_toupper

section .text
ft_toupper:
    mov eax, edi
    cmp eax, 0x61
    jl .return_same
    cmp eax, 0x7A
    jg .return_same
    xor eax, 0x20
    ret

.return_same:
    ret