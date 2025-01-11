Libasm 2s

| **64-bit** | **32-bit** | **16-bit** | **8-bit** |                            **Function-Call Role**                            |                            **Syscall Role**                             |       **Save Convention**       | **Additional Notes**                                                                                                    |
|:----------:|:----------:|:----------:|:---------:|:----------------------------------------------------------------------------:|:-----------------------------------------------------------------------:|:-------------------------------:|:------------------------------------------------------------------------------------------------------------------------|
|  **RAX**   |    EAX     |     AX     |    AL     | - Return value register (integers/pointers)<br/>- Accumulator for arithmetic |      - **Syscall number** (input)<br/>- **Return value** (output)       |   **Caller-saved** (volatile)   | Often used for multiplication/division (high part with RDX). Overwritten by syscalls.                                   |
|  **RBX**   |    EBX     |     BX     |    BL     |                     - General-purpose usage in functions                     |               - Not used by default for syscall arguments               | **Callee-saved** (non-volatile) | Must be restored by callee if used.                                                                                     |
|  **RCX**   |    ECX     |     CX     |    CL     |      - **4th argument** (func calls)<br/>- Often used for loops/shifts       | - Not used for direct syscall args (the 4th arg is in **R10** on Linux) |   **Caller-saved** (volatile)   | Overwritten by most calls; store if you need its value preserved.                                                       |
|  **RDX**   |    EDX     |     DX     |    DL     |                       - **3rd argument** (func calls)                        |                       - **3rd syscall argument**                        |   **Caller-saved** (volatile)   | High half of results in 128-bit multiply/div instructions with RAX.                                                     |
|  **RSI**   |    ESI     |     SI     |    SIL    |                       - **2nd argument** (func calls)                        |                       - **2nd syscall argument**                        |   **Caller-saved** (volatile)   | Source pointer for string ops (`MOVS`, `LODS`).                                                                         |
|  **RDI**   |    EDI     |     DI     |    DIL    |                       - **1st argument** (func calls)                        |                       - **1st syscall argument**                        |   **Caller-saved** (volatile)   | Destination pointer for string ops (`MOVS`, `STOS`).                                                                    |
|  **RBP**   |    EBP     |     BP     |    BPL    |                          - Frame pointer (if used)                           |                 - Not used for syscall args by default                  | **Callee-saved** (non-volatile) | Often used to maintain stack frames; must be restored if used as GP register.                                           |
|  **RSP**   |    ESP     |     SP     |    SPL    |            - **Stack pointer** (not used for register-based args)            |             - Stack pointer is the same concept in syscalls             |        *(Special role)*         | Must always point to valid stack location. Not freely used for general-purpose.                                         |
|   **R8**   |    R8D     |    R8W     |    R8B    |                       - **5th argument** (func calls)                        |                       - **5th syscall argument**                        |   **Caller-saved** (volatile)   | Additional scratch register.                                                                                            |
|   **R9**   |    R9D     |    R9W     |    R9B    |                       - **6th argument** (func calls)                        |                       - **6th syscall argument**                        |   **Caller-saved** (volatile)   | Additional scratch register.                                                                                            |
|  **R10**   |    R10D    |    R10W    |   R10B    |                     - Scratch register in function calls                     |                  - **4th syscall argument** (on Linux)                  |   **Caller-saved** (volatile)   | Often used for preserving RCX across syscalls (since RCX is used for the return address in `syscall` instruction).      |
|  **R11**   |    R11D    |    R11W    |   R11B    |                     - Scratch register in function calls                     |       - Overwritten by syscall to store flags in some mechanisms        |   **Caller-saved** (volatile)   | Caller must save it if it wants to keep its value around a syscall. Also used for saving flags on `SYSENTER`/`SYSCALL`. |
|  **R12**   |    R12D    |    R12W    |   R12B    |                           - General-purpose usage                            |                 - Not used for syscall args by default                  | **Callee-saved** (non-volatile) | Must be preserved if used.                                                                                              |
|  **R13**   |    R13D    |    R13W    |   R13B    |                           - General-purpose usage                            |                 - Not used for syscall args by default                  | **Callee-saved** (non-volatile) | Must be preserved if used.                                                                                              |
|  **R14**   |    R14D    |    R14W    |   R14B    |                           - General-purpose usage                            |                 - Not used for syscall args by default                  | **Callee-saved** (non-volatile) | Must be preserved if used.                                                                                              |
|  **R15**   |    R15D    |    R15W    |   R15B    |                           - General-purpose usage                            |                 - Not used for syscall args by default                  | **Callee-saved** (non-volatile) | Must be preserved if used.                                                                                              |

---

## Quick Reference

- **Function Call (System V AMD64) Integer/Pointer Arguments**
    1. RDI
    2. RSI
    3. RDX
    4. RCX
    5. R8
    6. R9

- **Syscall (Linux x86-64) Arguments**
    1. RDI
    2. RSI
    3. RDX
    4. R10
    5. R8
    6. R9

- **Syscall Number**: RAX
- **Syscall Return Value**: RAX

- **Caller-Saved (Volatile) Registers**:  
  RAX, RCX, RDX, RSI, RDI, R8, R9, R10, R11

- **Callee-Saved (Non-Volatile) Registers**:  
  RBX, RBP, R12, R13, R14, R15

- **RSP**: Special stack pointer register; must remain valid at all times.

- **Return Value** (function or syscall): RAX  
