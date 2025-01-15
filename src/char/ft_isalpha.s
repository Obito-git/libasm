global ft_isalpha

section .text
ft_isalpha:
    cmp edi, 'A'
    jl .return_false
    cmp edi, 'Z'
    jle .return_true

    cmp edi, 'a'
    jl .return_false
    cmp edi, 'z'
    jg .return_false
    jmp .return_true


.return_true:
    mov eax, 1
    ret

.return_false:
    xor eax, eax
    ret
