extern ft_strcpy, ft_strlen, malloc
global ft_strdup

section .text
ft_strdup:
    test rdi, rdi            ; Check if src is NULL
    jz .return_null          ; Return NULL if src is NULL

    push rdi                 ; Save src on stack
    call ft_strlen           ; Get length of src in rax
    add rax, 1               ; Add 1 for null-terminator
    mov rdi, rax             ; Pass size to malloc
    call malloc wrt ..plt    ; Allocate memory for new string
    test rax, rax            ; Check if malloc returned NULL
    jz .cleanup_and_return   ; Jump if malloc failed

    pop rsi                  ; Restore src as 2nd arg to strcpy
    mov rdi, rax             ; Set destination (new string) as 1st arg
    call ft_strcpy           ; Copy src to new string
    ret                      ; Return pointer to new string in rax

.cleanup_and_return:
    pop rax                  ; Clean up the saved src from the stack
.return_null:
    mov rax, 0               ; Return NULL (rax = 0)
    ret
