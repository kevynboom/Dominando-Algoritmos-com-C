#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    double ganhos, gastos;

    printf("Digite o total de ganhos: ");
    scanf("%lf", &ganhos);

    printf("Digite o total de gastos: ");
    scanf("%lf", &gastos);

    if (ganhos >= gastos) {
        printf("Você está dentro do orçamento!\n");
    } else {
        printf("Você está fora do orçamento! Não gaste mais!\n");
    }

    return 0;
}