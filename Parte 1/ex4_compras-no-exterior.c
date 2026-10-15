#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    float valorReais;
    float valorDolar;
    float cotacao = 5.42;

    printf("--- Conversor de Real para Dólar ---\n");
    printf("Digite o valor em reais: R$");
    scanf("%f", &valorReais);

    valorDolar = valorReais / cotacao; // Calculando o valor em dólares

    printf("\n--- Resultado ---\n");
    printf("Valor em reais: R$%.2f\n", valorReais);
    printf("Valor em dólares: US$%.2f\n", valorDolar);

    return 0;
}