#include <stdio.h>
#include <locale.h>

int coletarOpcao() {
    exibirMenu();

    int opcao;
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    return opcao;
}

void exibirMenu() {
    printf("\nMenu de Opções\n");
    printf("1. Consultar Saldo\n");
    printf("2. Realizar Depósito\n");
    printf("3. Realizar Saque\n");
    printf("0. Sair\n");
}

double coletarValor(char operacao[]) {
    double valor;

    printf("Digite o valor para %s: ", operacao);
    scanf("%lf", &valor);

    return valor;
}

double processarDeposito(double saldo, double valor) {
    return valor < 0 ? saldo : saldo + valor;
}

double processarSaque(double saldo, double valor) {
    return valor < 0 || valor > saldo ? saldo : saldo - valor;
}

void exibirSaldo(double saldo) {
    printf("Saldo atual: R$ %.2f\n", saldo);
}

void exibirMensagem(char mensagem[]) {
    printf("%s\n", mensagem);
}

int main() {
    setlocale(LC_ALL, "");

    double saldo = 0;
    int opcao;

    do {
        opcao = coletarOpcao();

        switch (opcao) {
            case 1:
                exibirSaldo(saldo);
                break;

            case 2: {
                double deposito = coletarValor("depósito");

                if (deposito < 0) {
                    exibirMensagem("Valor inválido");
                } else {
                    saldo = processarDeposito(saldo, deposito);
                    exibirSaldo(saldo);
                }
                break;
            }

            case 3: {
                double saque = coletarValor("saque");

                if (saque < 0) {
                    exibirMensagem("Valor inválido");
                } else if (saque > saldo) {
                    exibirMensagem("Saldo insuficiente");
                } else {
                    saldo = processarSaque(saldo, saque);
                    exibirSaldo(saldo);
                }
                break;
            }

            case 0:
                exibirMensagem("Sistema encerrado.");
                break;

            default:
                exibirMensagem("Opção inválida");
        }

    } while (opcao != 0);

    return 0;
}