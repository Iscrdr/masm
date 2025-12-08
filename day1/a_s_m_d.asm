section .data
fmt: db " ( %d + %d ) * %d = %d",10,0

section .text

global main

extern printf

main:
    mov rax,3 ;
    mov rbx,5;
    add rbx,rax;
    mul rbx,2;

    mov rdi,fmt ;
    mov rsi,3
    mov rdx,5
    mov rcx,2
    mov r8,rbx
    xor rax , rax 
   
    call printf

    mov rax, 0
    ret