global ft_isdigit

section .text
ft_isdigit:
    cmp edi, '0'
    jl .return_false
    cmp edi, '9'
    jg .return_false

    mov eax, 1
    ret

.return_false:
    xor eax, eax
    ret
