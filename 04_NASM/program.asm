%include 'library.asm'

section .data
        m_array dd 1, 0, 1, 1, 0, 1, 1, 1, 1, 0
        count dd 10

section .text
        global _start

_start:
        xor eax, eax
        mov ecx, [count]
        mov ebx, m_array

        push 0

        mov edx, [ebx]
        cmp edx, 0
        jle null_after_one

        inc eax
        dec ecx

next_element:
        cmp ecx, 1
        jl final_check

        add ebx, 4
        mov edx, [ebx]
        cmp edx, 0
        jle null_after_one

        inc eax
        dec ecx
        jmp next_element

null_after_one:
        cmp eax, [esp]
        jg increase_esp
        jmp reset_eax

increase_esp:
        mov [esp], eax
        jmp reset_eax

reset_eax:
        xor eax, eax
        dec ecx
        jmp next_element

final_check:
        cmp eax, [esp]
        jle output
        mov [esp], eax
        jmp output

output:
        xor eax, eax
        pop eax
        call print_number
        call exit