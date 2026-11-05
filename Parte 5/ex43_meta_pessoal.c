#include <stdio.h>
#include <locale.h>

void coletarMeta(char meta[]) {
    printf("Descrição da meta: ");
    fgets(meta, sizeof(char) * 100, stdin);
}

double coletarValorMeta() {
    double valorMeta;
    printf("Valor necessário para atingir a meta: R$ ");
    scanf("%lf", &valorMeta);
    return valorMeta;
}

double coletarSalario() {
    double salario;
    printf("Salário mensal: R$ ");
    scanf("%lf", &salario);
    return salario;
}

double coletarDespesas() {
    double despesas;
    printf("Total das despesas mensais: R$ ");
    scanf("%lf", &despesas);
    return despesas;
}

void processarDados(double valorMeta, double salario, double despesas, double resultados[]) {
    double saldo = salario - despesas;
    double reserva = saldo * 0.30;
    double disponivel = saldo - reserva;
    double prazo = disponivel > 0 ? valorMeta / disponivel : -1;

    resultados[0] = saldo;
    resultados[1] = reserva;
    resultados[2] = disponivel;
    resultados[3] = prazo;
}

void exibirResultado(char meta[], double valorMeta, double salario, double despesas, double resultados[]) {
    printf("\nMeta: %s (R$ %.2f)\n", meta, valorMeta);
    printf("Salário: R$ %.2f - Despesas: R$ %.2f\n", salario, despesas);

    printf("\nSaldo após despesas: R$ %.2f\n", resultados[0]);
    printf("Reserva fixa (30%%): R$ %.2f\n", resultados[1]);
    printf("Valor disponível para a meta: R$ %.2f por mês\n", resultados[2]);

    if (resultados[3] >= 0) {
        printf("Prazo estimado para atingir a meta: %.2f meses\n", resultados[3]);
    } else {
        printf("Não há valor disponível para atingir a meta.\n");
    }
}

int main() {
    setlocale(LC_ALL, "");

    char meta[100];
    double resultados[4];

    coletarMeta(meta);
    double valorMeta = coletarValorMeta();
    double salario = coletarSalario();
    double despesas = coletarDespesas();

    processarDados(valorMeta, salario, despesas, resultados);

    exibirResultado(meta, valorMeta, salario, despesas, resultados);

    return 0;
}