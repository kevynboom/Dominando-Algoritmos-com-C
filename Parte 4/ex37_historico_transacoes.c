#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int transacoes[1000];
    int qtd = 0, operacoes = 0, valor, saldo = 0;

    while (operacoes < 1000) {
        printf("Digite o valor da transação (-1 para encerrar): ");
        scanf("%d", &valor);

        if (valor == -1) {
            break;
        }

        operacoes++;

        if (valor == 0) {
            if (qtd > 0) {
                qtd--;
            }
        } else {
            transacoes[qtd] = valor;
            qtd++;
        }
    }

    for (int i = 0; i < qtd; i++) {
        saldo += transacoes[i];
    }

    printf("\nSaldo final: %d\n", saldo);

    return 0;
}