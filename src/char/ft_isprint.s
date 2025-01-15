global ft_isprint

section .text
ft_isprint:
    cmp edi, 0x1F
    jle .return_false
    cmp edi, 0x7F
    jge .return_false

    mov eax, 1
    ret

.return_false:
    xor eax, eax
    ret
