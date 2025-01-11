global ft_write
extern __errno_location

section .text
ft_write:

    mov rax, 1                      ; Syscall number for sys_write
    syscall                         ; Invoke the syscall

    test rax, rax                   ; Check if rax is negative
    js .error                       ; Jump to .error if the Sign Flag is set (rax < 0)

    ret                             ; Success: return number of bytes written

.error:
    neg rax                         ; Convert rax to positive errno
    mov rcx, rax                    ; Store positive errno in rcx
    call __errno_location wrt ..plt ; rax now contains the address of errno
    mov [rax], ecx                  ; Set *errno to the positive errno value
    mov rax, -1                     ; Return -1 to indicate error
    ret
