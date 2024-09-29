#include <stdio.h>
#include <limits.h>

int main() {
    unsigned char uc;     // Variável sem sinal, permite apenas valores de 0 a 255
    int i;                // Variável com sinal, permite valores de -2147483648 a 2147483647

    // Atribuindo um valor maior que o limite permitido para unsigned char
    uc = 300; // O valor máximo permitido é 255
    printf("Valor atribuído a 'unsigned char' (300): %u\n", uc);

    // Atribuindo um valor maior que o limite permitido para int
    i = INT_MAX + 1; // O valor máximo permitido é 2147483647
    printf("Valor atribuído a 'int' (INT_MAX + 1): %d\n", i);

    return 0;
}