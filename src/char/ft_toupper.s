global ft_toupper

section .text
ft_toupper:
    mov eax, edi
    cmp eax, 'a'
    jl .return_same
    cmp eax, 'z'
    jg .return_same
    xor eax, 0x20
    ret

.return_same:
    ret