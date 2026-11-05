#include <stdio.h>
#include <locale.h>

int coletarMeses() {
    int meses;

    printf("Quantidade de meses analisados: ");
    scanf("%d", &meses);

    return meses;
}

void coletarFaturamento(double faturamentos[], int meses) {
    for (int i = 0; i < meses; i++) {
        printf("Faturamento do mês %d: ", i + 1);
        scanf("%lf", &faturamentos[i]);
    }
}

void processarAnalise(double faturamentos[], int meses, char situacao[]) {
    int crescimento = 1, queda = 1, constante = 1;

    for (int i = 1; i < meses; i++) {
        if (faturamentos[i] < faturamentos[i - 1]) crescimento = 0;
        if (faturamentos[i] > faturamentos[i - 1]) queda = 0;
        if (faturamentos[i] != faturamentos[i - 1]) constante = 0;
    }

    if (constante) {
        sprintf(situacao, "Constante");
    } else if (crescimento) {
        sprintf(situacao, "Crescimento");
    } else if (queda) {
        sprintf(situacao, "Queda");
    } else {
        sprintf(situacao, "Sem padrão");
    }
}

void exibirResultado(double faturamentos[], int meses, char situacao[]) {
    printf("\n>> Análise de Faturamento <<\n");
    printf("Faturamento informado: ");

    for (int i = 0; i < meses; i++) {
        printf("%.2f", faturamentos[i]);

        if (i < meses - 1) {
            printf(", ");
        }
    }

    printf("\nSituação: %s\n", situacao);
}

int main() {
    setlocale(LC_ALL, "");

    int meses = coletarMeses();

    double faturamentos[meses];

    coletarFaturamento(faturamentos, meses);

    char situacao[20];
    processarAnalise(faturamentos, meses, situacao);

    exibirResultado(faturamentos, meses, situacao);

    return 0;
}