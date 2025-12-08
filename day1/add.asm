section .data
fmt: db " %d + %d = %d",10,0


section .text

global main

extern printf

main:
    ; 计算 5 + 6
    mov rax , 5
    mov rbx , 6
    add rax , rbx

    ; 调用 printf 输出结果
    mov rdi , fmt      ; 格式字符串
    mov rsi , 5        ; 第一个参数
    mov rdx , 6        ; 第二个参数
    mov rcx , rax      ; 第三个参数 (结果)
    xor rax , rax      ; 清零 rax 寄存器 (printf 调用约定要求)
    call printf

    mov rax, 0
    ret

