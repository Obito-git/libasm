global ft_isalnum
extern ft_isalpha, ft_isdigit

section .text
ft_isalnum:
    call ft_isalpha
    cmp eax, 1
    je .return_true
    call ft_isdigit
    ret

.return_true:
    mov eax, 1
    ret