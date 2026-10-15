#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    float tamanhoPista;
    int quantidadeVoltas;
    float tempoPrimeiraVolta;

    float distanciaTotal;
    float tempoTotal;

    printf("--- Performance do Piloto ---\n");
    printf("Digite o tamanho da pista em metros: ");
    scanf("%f", &tamanhoPista);

    printf("Digite a quantidade de voltas: ");
    scanf("%d", &quantidadeVoltas);

    printf("Digite o tempo da primeira volta em segundos: ");
    scanf("%f", &tempoPrimeiraVolta);

    distanciaTotal = (tamanhoPista * quantidadeVoltas) / 1000; // Calculando a distância total em quilômetros
    tempoTotal = (tempoPrimeiraVolta * quantidadeVoltas) / 60; // Calculando o tempo total em minutos

    printf("\n--- Resultado ---\n");
    printf("Distância total da corrida: %.2f km\n", distanciaTotal);
    printf("Previsão de tempo: %.2f minutos\n", tempoTotal);

    return 0;
}