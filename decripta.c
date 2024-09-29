#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Função para calcular o valor da função
int func_val(int x, int b) {
    double a0 = 186.752;
    double a1 = -148.235;
    double a2 = 34.5049;
    double a3 = -3.5091;
    double a4 = 0.183166;
    double a5 = -0.00513554;
    double a6 = 0.0000735464;
    double a7 = -4.22038e-7;

    double resultado = a0 + (a1 + b) * x + a2 * pow(x, 2) + a3 * pow(x, 3) + a4 * pow(x, 4) + a5 * pow(x, 5) + a6 * pow(x, 6) + a7 * pow(x, 7);

    return round(resultado);
}

int main() {
    int num_casos;
    printf("digite o numero de mensagens a ser decriptada: ");
    scanf("%d", &num_casos);

    for (int i = 0; i < num_casos; i++) {
        int b;
        printf("\nDigite o valor para B: ");
        scanf("%d", &b);

        printf("\ndigite a mensagem: ");
        char mensagem[101];
        scanf("%s", mensagem);

        int tamanho = strlen(mensagem);
        int posicao = 1;

        for (int j = 0; j < tamanho; j += 2) {
            char caractere[3];
            caractere[0] = mensagem[j];
            caractere[1] = mensagem[j + 1];
            caractere[2] = '\0';

            int valor = strtol(caractere, NULL, 16);

            if (valor == 0) {
                break;
            }

            int resultado = func_val(posicao, b);

            if (resultado != 0) {
                printf("%c", (char) valor);
            }

            posicao++;
        }

        printf("\n");
    }

    return 0;
}