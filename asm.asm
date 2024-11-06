section .data
    prompt db "Введите число: ", 0
    output_prime db "%d da.", 10, 0
    output_not_prime db "%d net.", 10, 0
    format_input db "%d", 0 ; Формат для scanf

section .bss
    number resd 1 ; Резервируем место для числа
    is_prime resb 1 ; Переменная для хранения, является ли число простым

section .text
    extern printf, scanf
    global main

main:
    ; Запрос числа у пользователя
    push prompt
    call printf
    add esp, 4

    ; Считываем число
    push number
    push format_input ; Формат для scanf
    call scanf
    add esp, 8

    ; Проверяем, является ли число простым
    mov eax, [number]
    cmp eax, 1
    je not_prime ; Если число = 1, оно не простое
    cmp eax, 2
    je print_prime ; Если число = 2, оно простое

    mov ecx, 2 ; Начинаем с 2
    mov byte [is_prime], 1 ; Предполагаем, что число простое

check_loop:
    mov eax, [number]
    xor edx, edx ; Очищаем EDX
    div ecx ; Делим number на i
    cmp edx, 0 ; Если остаток = 0, число не простое
    je not_prime

    ; Проверяем, если i*i > number
    mov eax, ecx
    mul ecx ; EAX = i * i
    cmp eax, [number] ; Сравниваем i^2 с number
    jg end_check ; Если i^2 > number, выходим из цикла

    inc ecx ; Увеличиваем i
    jmp check_loop ; Возвращаемся к началу цикла

not_prime:
    mov byte [is_prime], 0 ; Число не простое

end_check:
    ; Вывод результата
    mov eax, [number] ; Получаем число
    push eax
    cmp byte [is_prime], 1
    je print_prime

    push eax
    push output_not_prime
    call printf
    add esp, 8
    jmp end_program

print_prime:
    push eax
    push output_prime
    call printf
    add esp, 8

end_program:
    ; Завершаем программу
    ret

