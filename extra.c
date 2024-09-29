#include <stdio.h>
int main() {
    float N1, N2, PPD, EU, N3, notaFinal;
    int fezEU, fezN3;
    // Leitura e validação das notas principais
    printf("Digite as notas N1, N2 e PPD, separadas por espaço:\n");
    scanf("%f %f %f", &N1, &N2, &PPD);
    if ((N1 < 0 || N1 > 4.5) || (N2 < 0 || N2 > 4.5) || (PPD < 0 || PPD > 1)) {
        printf("Erro 3: Nota inválida.\n");
        return 1; // Encerra o programa com código de erro
    }
    // Verifica se fez o Exame Unificado
    printf("Fez o Exame Unificado? (0 - Não / 1 - Sim): ");
    scanf("%d", &fezEU);
    if (fezEU == 1) {
        printf("Digite a nota do Exame Unificado: ");
        scanf("%f", &EU);
        if (EU < 0 || EU > 1) {
            printf("Erro 3: Nota inválida.\n");
            return 1; // Encerra o programa com código de erro
        }
    }
    // Verifica se fez a N3
    printf("Fez a N3? (0 - Não / 1 - Sim): ");
    scanf("%d", &fezN3);
    if (fezN3 == 1) {
        printf("Digite a nota N3: ");
        scanf("%f", &N3);
        if (N3 < 0 || N3 > 4.5) {
            printf("Erro 3: Nota inválida.\n");
            return 1; // Encerra o programa com código de erro
        }
    }
    // Calcula a nota final
    notaFinal = N1 + N2 + PPD;
    // Substitui a menor nota se fez N3
    if (fezN3 == 1) {
        if (N1 < N2 && N1 < N3) {
            notaFinal = notaFinal - N1 + N3;
        } else if (N2 < N1 && N2 < N3) {
            notaFinal = notaFinal - N2 + N3;
        }
    }
    // Adiciona a nota do Exame Unificado se fez
    if (fezEU == 1) {
        notaFinal = (notaFinal + EU) / 2;
    }
    // Verifica se a nota final é válida
    if (notaFinal < 0 || notaFinal > 10) {
        printf("Erro: Nota final fora do intervalo permitido.\n");
        return 1;
    }
    // Mostra a nota final e se foi aprovado ou reprovado
    printf("Nota final: %.2f\n", notaFinal);
    if (notaFinal >= 5.0) {
        printf("Aprovado!\n");
    } else {
        printf("Reprovado.\n");
    }
    return 0;
}
