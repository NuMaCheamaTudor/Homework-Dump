section .data
    prompt db "Introduceti un numar (radiani): ", 0
    format db "%lf", 0
    format_result db "sin(%.10f) = %.10f", 10, 0

section .bss
    num resq 1
    result resq 1

section .text
    extern scanf
    extern printf
    global main

main:
    ; Afișează prompt-ul și citește numărul
    sub rsp, 8                      ; aliniaza stiva pe 16 bytes
    mov rdi, prompt
    call printf

    ; Citește numărul în 'num'
    mov rdi, format
    mov rsi, num
    call scanf

    ; Apelează funcția pentru calculul sinusului
    mov rdi, num
    call sin_taylor

    ; Afișează rezultatul
    mov rdi, format_result
    mov rsi, [num]
    mov rdx, [result]
    call printf

    ; Termină programul
    xor eax, eax
    add rsp, 8                      ; curata spatiul alocat pe stiva
    ret

sin_taylor:
    ; Salvare registru RBP
    push rbp
    mov rbp, rsp

    ; Pregătire variabile pentru serie Taylor
    fld qword [rdi]  ; st(0) = x

    ; Inițializare sumă (result) cu valoarea lui x
    fld st0          ; st(0) = x, st(1) = x
    fst qword [result]

    ; x^3 și factorial 3!
    fld st0          ; st(0) = x, st(1) = x, st(2) = x
    fmul st0         ; st(0) = x^2, st(1) = x, st(2) = x
    fmul qword [rdi] ; st(0) = x^3, st(1) = x, st(2) = x

    ; Inițializare termen și semn
    mov rax, 1       ; rax = 1 (factorial)
    mov ecx, 1       ; ecx = 1 (index)
    fld1             ; st(0) = 1.0, st(1) = x^3, st(2) = x, st(3) = x

.sin_series:
    ; Calculează (-1)^n * x^(2n+1) / (2n+1)!
    fld st1          ; st(0) = x^(2n+1), st(1) = x^3, st(2) = x, st(3) = x
    fdiv st0, st2    ; st(0) = x^(2n+1) / (2n+1)!, st(1) = x^3, st(2) = x, st(3) = x

    ; Verificăm semnul (-1)^n
    test ecx, 1
    jz .positive
    fchs
.positive:
    ; Adăugare/Scădere la sumă
    fadd qword [result]
    fst qword [result]

    ; Incrementare index și recalculare termen
    inc ecx
    cmp ecx, 10
    jl .sin_series

    ; Restaurare registru RBP
    mov rsp, rbp
    pop rbp

    ; Returnare
    ret
