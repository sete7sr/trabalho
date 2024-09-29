#include <stdio.h>
#include <limits.h>

// Função para exibir os limites numéricos de diferentes tipos de variáveis
void displayNumericLimits() {
    printf("+-------------------------------------------------------------------+\n");
    printf("| Tipo\t\t\t\t\t| Mínimo\t\t| Máximo\t\t\t\n");
    printf("+-------------------------------------------------------------------+\n");
    printf("| char\t\t\t\t\t| %d\t\t\t| %d\t\t\t\n", CHAR_MIN, CHAR_MAX);
    printf("| int\t\t\t\t\t| %d\t\t| %d\t\t\t\n", INT_MIN, INT_MAX);
    printf("| short int\t\t\t\t| %d\t\t| %d\t\t\t\n", SHRT_MIN, SHRT_MAX);
    printf("| unsigned int\t\t\t\t| 0\t\t\t| %u\t\t\t\n", UINT_MAX);
    printf("| long int\t\t\t\t| %ld\t\t| %ld\t\t\t\n", LONG_MIN, LONG_MAX);
    printf("| unsigned long int\t\t\t| 0\t\t\t| %lu\t\t\t\n", ULONG_MAX);
    printf("| long long int\t\t\t\t| %lld\t| %lld\t\t\t\n", LLONG_MIN, LLONG_MAX);
    printf("| unsigned long long int\t\t| 0\t\t\t| %llu\t\t\t\n", ULLONG_MAX);
    printf("+-------------------------------------------------------------------+\n");
}

// Função para demonstrar overflow em unsigned int
void demonstrateUnsignedIntOverflow(unsigned int value) {
    printf("\nValor de unsigned int antes do overflow: %u\n", value);
    value++;
    printf("Valor de unsigned int após overflow: %u\n", value);
}

// Função para demonstrar underflow em short int
void demonstrateShortIntUnderflow(short int value) {
    printf("\nValor de short int antes do underflow: %d\n", value);
    value--;
    printf("Valor de short int após underflow: %d\n", value);
}

int main() {
    // Exibe os limites dos tipos inteiros
    displayNumericLimits();

    // Demonstra o erro de overflow com unsigned int
    unsigned int unsignedIntValue;
    printf("\nInsira um valor para 'unsigned int' (próximo a %u para overflow): ", UINT_MAX);
    scanf("%u", &unsignedIntValue);
    demonstrateUnsignedIntOverflow(unsignedIntValue);

    // Demonstra o erro de underflow com short int
    short int shortIntValue;
    printf("\nInsira um valor para 'short int' (próximo a %d para underflow): ", SHRT_MIN);
    scanf("%hd", &shortIntValue);
    demonstrateShortIntUnderflow(shortIntValue);

    return 0;
}