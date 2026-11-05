#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int qtd;

    printf("Digite a quantidade de dias monitorados: ");
    scanf("%d", &qtd);

    double pesos[qtd];
    double maiorPeso = 0, menorPeso = 0;
    int diaMaior = 0, diaMenor = 0;

    for (int i = 0; i < qtd; i++) {
        printf("Digite o peso do dia %d (kg): ", i + 1);
        scanf("%lf", &pesos[i]);

        if (i == 0 || pesos[i] > maiorPeso) {
            maiorPeso = pesos[i];
            diaMaior = i + 1;
        }

        if (i == 0 || pesos[i] < menorPeso) {
            menorPeso = pesos[i];
            diaMenor = i + 1;
        }
    }

    printf("\nPesos informados: ");

    for (int i = 0; i < qtd; i++) {
        printf("%.0f%s", pesos[i], i < qtd - 1 ? ", " : "\n");
    }

    printf("Maior peso: %.0f kg (Dia %d)\n", maiorPeso, diaMaior);
    printf("Menor peso: %.0f kg (Dia %d)\n", menorPeso, diaMenor);

    printf("\nGráfico de evolução:\n");

    for (int i = 0; i < qtd; i++) {
        int barras = (int)(pesos[i] / 5);

        printf("Dia %d | ", i + 1);

        for (int j = 0; j < barras; j++) {
            printf("■");
        }

        printf(" %.0f\n", pesos[i]);
    }

    return 0;
}