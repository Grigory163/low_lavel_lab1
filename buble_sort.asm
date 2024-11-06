section .data

    format_size db "Enter the size of the array: ", 0

    format_elem db "m[%d]=", 0

    format_scanf db "%d", 0

    format_scanf_double db "%lf", 0


section .bss

    size resd 1

    i resd 1

    ptr resq 1


section .text

    extern printf, scanf, malloc

    global read_array


read_array:

    ; Сохранение регистров

    push rbp

    mov rbp, rsp

    sub rsp, 16            ; Резервируем место для локальных переменных


    ; Вызов printf для ввода размера массива

    mov rdi, format_size

    xor rax, rax           ; Очистка RAX для вызова printf

    call printf


    ; Вызов scanf для чтения размера

    mov rsi, size          ; Адрес переменной size

    mov rdi, format_scanf

    xor rax, rax           ; Очистка RAX для вызова scanf

    call scanf


    ; Выделение памяти для массива

    mov eax, dword [size]  ; Получаем значение size

    cvtsi2sd xmm0, eax     ; Преобразуем в double

    mov rdi, 8             ; Размер double

    mulsd xmm0, rdi        ; Умножаем size на размер double

    cvttsd2si rdi, xmm0    ; Преобразуем обратно в int

    call malloc            ; Выделяем память

    mov [ptr], rax         ; Сохраняем указатель на массив


    ; Инициализация i = 0

    mov dword [i], 0


loop_start:

    ; Ввод элемента массива

    mov eax, [i]

    mov esi, eax           ; Копируем i в esi

    mov rdi, format_elem

    xor rax, rax           ; Очистка RAX для вызова printf

    call printf


    ; Чтение элемента

    mov rax, [ptr]         ; Загружаем адрес массива

    mov rcx, [i]

    imul rcx, 8            ; Умножаем индекс на размер double

    add rax, rcx           ; Получаем адрес элемента

    mov rsi, rax           ; Указатель на элемент

    mov rdi, format_scanf_double

    xor rax, rax           ; Очистка RAX для вызова scanf

    call scanf


    ; Увеличение i

    inc dword [i]


    ; Проверка условия цикла

    mov eax, [i]

    cmp eax, [size]

    jl loop_start


    ; Возвращаем указатель на массив

    mov rax, [ptr]


    ; Восстановление регистров и возврат

    mov rsp, rbp

    pop rbp

    ret