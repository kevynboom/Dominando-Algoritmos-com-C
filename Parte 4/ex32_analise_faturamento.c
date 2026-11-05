#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int n;

    printf("Digite a quantidade de meses analisados: ");
    scanf("%d", &n);

    double faturamento[n];

    for (int i = 0; i < n; i++) {
        printf("Digite o faturamento do mês %d: ", (i + 1));
        scanf("%lf", &faturamento[i]);
    }

    int cresceu = 1, caiu = 1, constante = 1;

    for (int i = 1; i < n; i++) {
        if (faturamento[i] > faturamento[i - 1]) {
            caiu = 0;
            constante = 0;
        } else if (faturamento[i] < faturamento[i - 1]) {
            cresceu = 0;
            constante = 0;
        }
    }

    printf("\n>> Análise de Faturamento <<\n");
    printf("Faturamento informado: ");

    for (int i = 0; i < n; i++) {
        printf("%.0f", faturamento[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("\n");

    if (constante) {
        printf("Situação: Constante\n");
    } else if (cresceu) {
        printf("Situação: Crescimento\n");
    } else if (caiu) {
        printf("Situação: Queda\n");
    } else {
        printf("Situação: Sem padrão\n");
    }

    return 0;
}