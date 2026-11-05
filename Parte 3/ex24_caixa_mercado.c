#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    double valor, total = 0;

    do {
        printf("Digite o valor do produto (0 para encerrar): ");
        scanf("%lf", &valor);

        if (valor == 0) {
            break;
        }

        if (valor < 0) {
            printf("Valor inválido: %.0f\n", valor);
        } else {
            total += valor;
        }
    } while (1);

    printf("Em quantas vezes deseja parcelar (0 ou 1 para à vista, > 1 para parcelado)? ");
    int parcelas;
    scanf("%d", &parcelas);

    if (parcelas <= 1) {
        printf("Pagamento à vista: R$ %.2f\n", total);
    } else {
        double valorParcela = total / parcelas;
        printf("Total da compra: R$ %.2f\n", total);
        printf("Parcelado em %dx de R$ %.2f\n", parcelas, valorParcela);
    }

    return 0;
}