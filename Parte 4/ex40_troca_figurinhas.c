#include <stdio.h>
#include <locale.h>

int existe(int vetor[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            return 1;
        }
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "");

    printf("Digite a quantidade de figurinhas do jogador 1: ");
    int qtd1;
    scanf("%d", &qtd1);

    int jogador1[qtd1];

    for (int i = 0; i < qtd1; i++) {
        printf("Digite o número da figurinha %d do jogador 1: ", i + 1);
        scanf("%d", &jogador1[i]);
    }

    printf("Digite a quantidade de figurinhas do jogador 2: ");
    int qtd2;
    scanf("%d", &qtd2);

    int jogador2[qtd2];

    for (int i = 0; i < qtd2; i++) {
        printf("Digite o número da figurinha %d do jogador 2: ", i + 1);
        scanf("%d", &jogador2[i]);
    }

    int comuns = 0, exclusivas1 = 0, exclusivas2 = 0;

    printf("\nFigurinhas em comum: ");
    int primeiro = 1;

    for (int i = 0; i < qtd1; i++) {
        if (existe(jogador2, qtd2, jogador1[i]) && !existe(jogador1, i, jogador1[i])) {
            printf("%s%d", primeiro ? "" : ", ", jogador1[i]);
            primeiro = 0;
            comuns++;
        }
    }

    if (primeiro) {
        printf("Nenhuma");
    }

    printf("\n\nApenas jogador A: ");
    primeiro = 1;

    for (int i = 0; i < qtd1; i++) {
        if (!existe(jogador2, qtd2, jogador1[i]) && !existe(jogador1, i, jogador1[i])) {
            printf("%s%d", primeiro ? "" : ", ", jogador1[i]);
            primeiro = 0;
            exclusivas1++;
        }
    }

    if (primeiro) {
        printf("Nenhuma");
    }

    printf("\nApenas jogador B: ");
    primeiro = 1;

    for (int i = 0; i < qtd2; i++) {
        if (!existe(jogador1, qtd1, jogador2[i]) && !existe(jogador2, i, jogador2[i])) {
            printf("%s%d", primeiro ? "" : ", ", jogador2[i]);
            primeiro = 0;
            exclusivas2++;
        }
    }

    if (primeiro) {
        printf("Nenhuma");
    }

    int trocas = exclusivas1 < exclusivas2 ? exclusivas1 : exclusivas2;

    printf("\n\nQuantidade de trocas possíveis: %d\n", trocas);

    return 0;
}