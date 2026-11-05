#include <stdio.h>
#include <locale.h>

double* coletarDados(double dados[]) {
    printf("Digite a quantidade de açaís pequenos: ");
    scanf("%lf", &dados[0]);

    printf("Digite a quantidade de açaís médios: ");
    scanf("%lf", &dados[1]);

    printf("Digite a quantidade de açaís grandes: ");
    scanf("%lf", &dados[2]);

    printf("Digite o percentual de desconto: ");
    scanf("%lf", &dados[3]);

    return dados;
}

double processarPedido(double dados[]) {
    double total = dados[0] * 13.50 + dados[1] * 15.00 + dados[2] * 17.50;
    return total - (total * dados[3] / 100);
}

void exibirResultado(double dados[], double total) {
    printf("\nSeu pedido foi registrado.\n");
    printf("- Açaí P: %.0f\n", dados[0]);
    printf("- Açaí M: %.0f\n", dados[1]);
    printf("- Açaí G: %.0f\n", dados[2]);
    printf("\nDesconto de %.0f%% aplicado.\n", dados[3]);
    printf("Total R$ %.2f\n", total);
}

int main() {
    setlocale(LC_ALL, "");

    double dados[4];

    coletarDados(dados);
    double total = processarPedido(dados);
    exibirResultado(dados, total);

    return 0;
}