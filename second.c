#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Таблица для вычисления CRC32
uint32_t crc32_table[256];

// Функция для инициализации таблицы CRC32
void init_crc32_table() {
    uint32_t polynomial = 0xedb88320;
    uint32_t i = 0;

init_loop:
    if (i >= 256) goto end_init;
    
    uint32_t crc = i;
    uint32_t j = 8;

inner_loop:
    if (j == 0) goto store_crc;
    
    if (crc & 1) {
        crc = (crc >> 1);
        crc ^= polynomial;
    } else {
        crc >>= 1;
    }
    j--;
    goto inner_loop;

store_crc:
    crc32_table[i] = crc;
    i++;
    goto init_loop;

end_init:
    return;
}

// Функция для вычисления CRC32
uint32_t calculate_crc32(const char *data) {
    uint32_t crc = 0xffffffff;

data_loop:
    if (*data == 0) goto end_data_loop;

    uint8_t byte = *data;
    data++;

    crc = (crc >> 8);
    crc ^= crc32_table[(crc ^ byte) & 0xff];

    goto data_loop;

end_data_loop:
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

