global ft_calloc
extern ft_bzero, malloc

section .text
ft_calloc:
    mov rax, rdi            ; mov first arg to rax
    mul rsi                 ; multiply by second arg

    push rax                ; save multiplied value (total size) on stack

    mov rdi, rax            ; put total size as first malloc arg
    call malloc wrt ..plt   ; Allocate memory

    cmp rax, 0              ; if malloc returns null
    je .return

    pop rsi                 ; restore total size to second ft_bzero arg
    mov rdi, rax            ; put allocated ptr to first ft_bzero arg
    call ft_bzero

    mov rax, rdi            ; put allocated ptr as return value

.return:
    ret
