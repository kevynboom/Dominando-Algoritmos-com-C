#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int quantidadeVoltas;
    float tamanhoPista, tempoPrimeiraVolta, distanciaTotal, tempoTotal;

    printf("--- Performance do Piloto ---\n");
    printf("Digite o tamanho da pista em metros: ");
    scanf("%f", &tamanhoPista);

    printf("Digite a quantidade de voltas: ");
    scanf("%d", &quantidadeVoltas);

    printf("Digite o tempo da primeira volta em segundos: ");
    scanf("%f", &tempoPrimeiraVolta);

    distanciaTotal = (tamanhoPista * quantidadeVoltas) / 1000; 
    tempoTotal = (tempoPrimeiraVolta * quantidadeVoltas) / 60; 

    printf("\n--- Resultado ---\n");
    printf("Distância total da corrida: %.2f km\n", distanciaTotal);
    printf("Previsão de tempo: %.2f minutos\n", tempoTotal);

    return 0;
}