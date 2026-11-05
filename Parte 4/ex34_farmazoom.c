#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int qtd;

    printf("Digite a quantidade de medicamentos: ");
    scanf("%d", &qtd);

    int farmaciaA[qtd], farmaciaB[qtd];
    int maisBaratosA = 0, maisBaratosB = 0, mesmoPreco = 0, totalA = 0, totalB = 0;

    for (int i = 0; i < qtd; i++) {
        printf("Digite o preço do medicamento %d na Farmácia A: ", i + 1);
        scanf("%d", &farmaciaA[i]);
        totalA += farmaciaA[i];
    }

    for (int i = 0; i < qtd; i++) {
        printf("Digite o preço do medicamento %d na Farmácia B: ", i + 1);
        scanf("%d", &farmaciaB[i]);
        totalB += farmaciaB[i];
    }

    printf("\nFARMAZOOM\n");
    printf("Farmácia A: ");

    for (int i = 0; i < qtd; i++) {
        printf("%d%s", farmaciaA[i], i < qtd - 1 ? ", " : "\n");
    }

    printf("Farmácia B: ");

    for (int i = 0; i < qtd; i++) {
        printf("%d%s", farmaciaB[i], i < qtd - 1 ? ", " : "\n");
    }

    for (int i = 0; i < qtd; i++) {
        if (farmaciaA[i] < farmaciaB[i]) {
            maisBaratosA++;
        } else if (farmaciaB[i] < farmaciaA[i]) {
            maisBaratosB++;
        } else {
            mesmoPreco++;
        }
    }

    printf("\nProdutos mais Baratos\n");
    printf("Na Farmácia A: %d\n", maisBaratosA);
    printf("Na Farmácia B: %d\n", maisBaratosB);
    printf("Mesmo preço: %d\n", mesmoPreco);

    printf("\nTotal\n");
    printf("Farmácia A: R$ %d\n", totalA);
    printf("Farmácia B: R$ %d\n", totalB);

    printf("\nMelhor opção\n");

    if (totalA < totalB) {
        printf("Farmácia A\n");
    } else if (totalB < totalA) {
        printf("Farmácia B\n");
    } else {
        printf("Empate\n");
    }

    return 0;
}