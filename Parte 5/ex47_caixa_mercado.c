#include <stdio.h>
#include <locale.h>

double processarTotal(double total, double valor) {
    return total + valor;
}

void exibirValorInvalido(double valor) {
    printf("Valor inválido: %.2f\n", valor);
}

double coletarCompras() {
    double total = 0;
    double valor;

    do {
        char entrada[100];

        printf("Digite o valor da compra (0 para encerrar): ");
        fgets(entrada, 100, stdin);

        for (int i = 0; entrada[i] != '\0'; i++) {
            if (entrada[i] == ',') {
                entrada[i] = '.';
            }
        }

        sscanf(entrada, "%lf", &valor);

        if (valor < 0) {
            exibirValorInvalido(valor);
        } else {
            total = processarTotal(total, valor);
        }

    } while (valor != 0);

    return total;
}

int coletarParcelas() {
    int parcelas;

    printf("Em quantas vezes deseja parcelar? ");
    scanf("%d", &parcelas);

    return parcelas;
}

double processarParcela(double total, int parcelas) {
    return total / parcelas;
}

void exibirResultado(double total, int parcelas, double valorParcela) {
    if (parcelas <= 1) {
        printf("Pagamento à vista: R$ %.2f\n", total);
    } else {
        printf("Total da compra: R$ %.2f\n", total);
        printf("Parcelado em %dx de R$ %.2f\n", parcelas, valorParcela);
    }
}

int main() {
    setlocale(LC_ALL, "");

    double total = coletarCompras();
    int parcelas = coletarParcelas();
    double valorParcela = parcelas > 1 ? processarParcela(total, parcelas) : total;

    exibirResultado(total, parcelas, valorParcela);

    return 0;
}