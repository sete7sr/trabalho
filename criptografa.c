#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_MESSAGE_LENGTH 100

double func_val(int x, int b) {
    double a0 = 186.752;
    double a1 = -148.235;
    double a2 = 34.5049;
    double a3 = -3.5091;
    double a4 = 0.183166;
    double a5 = -0.00513554;
    double a6 = 0.0000735464;
    double a7 = -4.22038e-7;

    return round(a0 + a1 * x + a2 * pow(x, 2) + a3 * pow(x, 3) + a4 * pow(x, 4) + a5 * pow(x, 5) + a6 * pow(x, 6) + a7 * pow(x, 7) + b);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int b;
    printf("Digite a mensagem a ser criptografada: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strlen(message) - 1] = '\0'; // remove o caractere de newline

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    for (int i = 0; i < strlen(message); i++) {
        int x = i + 1;
        int val = func_val(x, b);
        printf("%02X", val);
    }
    printf("\n");

    return 0;
}
