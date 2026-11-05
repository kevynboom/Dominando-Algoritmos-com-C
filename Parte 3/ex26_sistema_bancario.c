#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    double saldo = 0;
    int opcao;

    do {
        printf("Digite a opção (0-Sair, 1-Consultar, 2-Depositar, 3-Sacar): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Fim.\n");
                break;
            case 1:
                printf("Saldo atual: R$ %.0f\n", saldo);
                break;
            case 2: {
                printf("Digite o valor do depósito: ");
                double deposito;
                scanf("%lf", &deposito);

                if (deposito < 0) {
                    printf("Valor inválido\n");
                } else {
                    saldo += deposito;
                }
                break;
            }
            case 3: {
                printf("Digite o valor do saque: ");
                double saque;
                scanf("%lf", &saque);

                if (saque < 0) {
                    printf("Valor inválido\n");
                } else if (saque > saldo) {
                    printf("Saldo insuficiente\n");
                } else {
                    saldo -= saque;
                }
                break;
            }
            default:
                printf("Opção inválida\n");
        }
    } while (opcao != 0);

    return 0;
}