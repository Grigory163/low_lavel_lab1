#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Таблица для вычисления CRC32
uint32_t crc32_table[256];

// Функция для инициализации таблицы CRC32
void init_crc32_table() {
    uint32_t polynomial = 0xedb88320;
    for (uint32_t i = 0; i < 256; i++) {
        uint32_t crc = i;
        for (uint32_t j = 8; j > 0; j--) {
            if (crc & 1) {
                crc = (crc >> 1) ^ polynomial;
            } else {
                crc >>= 1;
            }
        }
        crc32_table[i] = crc;
    }
}

// Функция для вычисления CRC32
uint32_t calculate_crc32(const char *data) {
    uint32_t crc = 0xffffffff;
    while (*data) {
        uint8_t byte = *data++;
        crc = (crc >> 8) ^ crc32_table[(crc ^ byte) & 0xff];
    }
    return crc ^ 0xffffffff;
}

int main() {
    char input[256];

    // Инициализация таблицы CRC32
    init_crc32_table();

    // Запрос ввода строки
    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);
    
    // Удаление символа новой строки, если он есть
    input[strcspn(input, "\n")] = 0;

    // Вычисление и вывод CRC32
    uint32_t crc32_result = calculate_crc32(input);
    printf("CRC32: %08x\n", crc32_result);

    return 0;
}

