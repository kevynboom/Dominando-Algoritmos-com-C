#include <stdio.h>
#include <locale.h>

double* coletarDados(double dados[]) {
    printf("Digite o tamanho da pista em metros: ");
    scanf("%lf", &dados[0]);

    printf("Digite a quantidade de voltas: ");
    scanf("%lf", &dados[1]);

    printf("Digite o tempo da primeira volta em segundos: ");
    scanf("%lf", &dados[2]);

    return dados;
}

double* processarDados(double dados[], double resultados[]) {
    resultados[0] = (dados[0] * dados[1]) / 1000;
    resultados[1] = (dados[2] * dados[1]) / 60;

    return resultados;
}

void exibirResultado(double resultados[]) {
    printf("\nAnálise Preditiva Concluída\n");
    printf("--\n");
    printf("Distância total a ser percorrida: %.2f km.\n", resultados[0]);
    printf("Previsão de conclusão: %.1f minutos.\n", resultados[1]);
}

int main() {
    setlocale(LC_ALL, "");

    double dados[3];
    double resultados[2];

    coletarDados(dados);
    processarDados(dados, resultados);
    exibirResultado(resultados);

    return 0;
}