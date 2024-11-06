#include <stdio.h>

int is_prime(int number) {
    if (number <= 1) {
        return 0; // Числа меньше или равные 1 не являются простыми
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0; // Найден делитель, число не простое
        }
    }
    return 1; // Число простое
}

int main() {
    int number;

    printf("Введите число: ");
    scanf("%d", &number);

    if (is_prime(number)) {
        printf("%d является простым числом.\n", number);
    } else {
        printf("%d не является простым числом.\n", number);
    }

    return 0;
}