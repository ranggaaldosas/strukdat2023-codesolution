#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

// Struktur untuk dynamic array
typedef struct {
    char **data;
    int size;
    int capacity;
} DynamicArray;

// Fungsi untuk menginisialisasi dynamic array
void initializeDynamicArray(DynamicArray *array, int initialCapacity) {
    array->data = new char*[initialCapacity];
    if (array->data == nullptr) {
        perror("new");
        exit(1);
    }
    array->size = 0;
    array->capacity = initialCapacity;
}

// Fungsi untuk menambahkan elemen ke dynamic array
void pushToDynamicArray(DynamicArray *array, const char *str) {
    if (array->size >= array->capacity) {
        // Jika kapasitas terlampaui, alokasikan lebih banyak memori
        array->capacity *= 2;
        char **temp = new char*[array->capacity];
        if (temp == nullptr) {
            perror("new");
            exit(1);
        }
        memcpy(temp, array->data, sizeof(char*) * array->size);
        delete[] array->data;
        array->data = temp;
    }

    // Salin input ke dalam dynamic array
    array->data[array->size] = new char[strlen(str) + 1];
    if (array->data[array->size] == nullptr) {
        perror("new");
        exit(1);
    }
    strcpy(array->data[array->size], str);
    array->size++;
}

// Fungsi pembanding untuk qsort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Fungsi untuk membersihkan dynamic array
void cleanDynamicArray(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        delete[] array->data[i];
    }
    delete[] array->data;
    array->size = 0;
    array->capacity = 0;
}

// Fungsi untuk memeriksa jumlah huruf 'O' dalam sebuah string
int countOs(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'O' || str[i] == 'o') {
            count++;
        }
    }
    return count;
}

int main() {
    DynamicArray data;
    initializeDynamicArray(&data, 10);
    char input[100];
    while (1) {
        fgets(input, sizeof(input), stdin);

        // Menghapus karakter newline dari input
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "gasss") == 0) {
            break;
        }

        // Memeriksa apakah input memiliki maksimal 2 huruf 'O'
        if (countOs(input) <= 2) {
            pushToDynamicArray(&data, input);
        }
    }

    // Mengurutkan data berdasarkan alfabet
    qsort(data.data, data.size, sizeof(char *), compare);

    for (int i = 0; i < data.size; i++) {
        printf("%s\n", data.data[i]);
    }

    // Membersihkan dynamic array
    cleanDynamicArray(&data);

    return 0;
}
