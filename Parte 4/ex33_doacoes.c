#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    char nomeProjeto[100];

    printf("Digite o nome do projeto de caridade: ");
    fgets(nomeProjeto, sizeof(nomeProjeto), stdin);

    int qtdDoacoes;

    printf("Digite a quantidade de doações recebidas: ");
    scanf("%d", &qtdDoacoes);

    double meta;

    printf("Digite o valor da meta financeira: ");
    scanf("%lf", &meta);

    double doacoes[qtdDoacoes];
    double totalArrecadado = 0;

    for (int i = 0; i < qtdDoacoes; i++) {
        printf("Digite o valor da doação %d: ", (i + 1));
        scanf("%lf", &doacoes[i]);
        totalArrecadado += doacoes[i];
    }

    double maiorDoacao = doacoes[0];

    for (int i = 1; i < qtdDoacoes; i++) {
        if (doacoes[i] > maiorDoacao) {
            maiorDoacao = doacoes[i];
        }
    }

    printf("\n>> Resumo das Doações <<\n");
    printf("Projeto: %s", nomeProjeto);
    printf("Doações recebidas: ");

    for (int i = 0; i < qtdDoacoes; i++) {
        printf("%.0f", doacoes[i]);
        if (i < qtdDoacoes - 1) {
            printf(", ");
        }
    }

    printf("\n");

    printf("Total arrecadado: %.0f\n", totalArrecadado);
    printf("Maior doação: %.0f\n", maiorDoacao);

    if (totalArrecadado >= meta) {
        printf("Situação: Meta atingida\n");
    } else {
        printf("Situação: Meta não atingida\n");
    }

    return 0;
}