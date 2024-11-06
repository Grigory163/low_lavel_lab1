#include <stdio.h>

int main() {
    int number;
    int is_prime = 1; // Предполагаем, что число простое
    int i = 2;

    printf("Введите число: ");
    scanf("%d", &number);

    if (number <= 1) {
        is_prime = 0; // Число не простое
        goto end;
    }

loop:
    if (i * i > number) goto end; // Если i^2 больше number, выходим из цикла
    if (number % i == 0) {
        is_prime = 0; // Найден делитель, число не простое
        goto end;
    }
    i++; // Увеличиваем i
    goto loop; // Возвращаемся к началу цикла

end:
    if (is_prime) {
        printf("%d является простым числом.\n", number);
    } else {
        printf("%d не является простым числом.\n", number);
    }

    return 0;
}

