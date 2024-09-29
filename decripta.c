#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Função que calcula o valor da equação polinomial para uma dada posição e o valor b

int calcular_funcao(int x, int b) {
    double a0 = 186.752;
    double a1 = -148.235;
    double a2 = 34.5049;
    double a3 = -3.5091;
    double a4 = 0.183166;
    double a5 = -0.00513554;
    double a6 = 0.0000735464;
    double a7 = -4.22038e-7;

    // Cálculo do valor polinomial
    double resultado = a0 + (a1 + b) * x + a2 * pow(x, 2) + a3 * pow(x, 3) + a4 * pow(x, 4) + a5 * pow(x, 5) + a6 * pow(x, 6) + a7 * pow(x, 7);

    // Retorna o valor arredondado
    return round(resultado);
}

// Essa função converte pares de caracteres de uma string hexadecimal para o valor numérico que eles representam
int converter_hex_para_decimal(char *caractere) {
    return strtol(caractere, NULL, 16);
}

// Função que descriptografa uma única mensagem

void descriptografar_mensagem(char *mensagem, int b) {
    int tamanho = strlen(mensagem);
    int posicao = 1; // Começa na posição 1 para os cálculos

    // Percorre a mensagem de dois em dois caracteres
    for (int i = 0; i < tamanho; i += 2) {
        // Extrai os dois caracteres da mensagem
        char caractere[3];
        caractere[0] = mensagem[i];
        caractere[1] = mensagem[i + 1];
        caractere[2] = '\0'; // Finaliza a string

        // Converte os dois caracteres hexadecimais para um valor decimal
        int valor = converter_hex_para_decimal(caractere);

        // Se o valor for 0, interrompe o processo (fim da mensagem)
        if (valor == 0) {
            break;
        }

        // Calcula o resultado da função para a posição atual e o valor de b
        int resultado = calcular_funcao(posicao, b);

        // Se o resultado for diferente de zero, imprime o caractere correspondente
        if (resultado != 0) {
            printf("%c", (char) valor);
        }

        posicao++; 
    }

    printf("\n"); 
}

// Função principal para o fluxo do programa
// Esta função é responsável por controlar o fluxo principal, recebendo as entradas do usuário e chamando as outras funções
void descriptografar_mensagens() {
    int num_casos;
    printf("Digite o número de mensagens a ser decriptada: ");
    scanf("%d", &num_casos);

    // Loop para processar cada caso
    for (int i = 0; i < num_casos; i++) {
        int b;
        printf("\nDigite o valor para B: ");
        scanf("%d", &b);

        printf("\nDigite a mensagem: ");
        char mensagem[101];
        scanf("%s", mensagem);

        // Chama a função para descriptografar uma única mensagem
        descriptografar_mensagem(mensagem, b);
    }
}

int main() {
    // Inicia o processo de descriptografia chamando a função principal
    descriptografar_mensagens();
    return 0;
}
