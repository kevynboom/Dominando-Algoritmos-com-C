#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    float valorReais, valorDolar, cotacao = 5.42;

    printf("--- Conversor de Real para Dólar ---\n");
    printf("Digite o valor em reais: R$");
    scanf("%f", &valorReais);

    valorDolar = valorReais / cotacao;

    printf("\n--- Resultado ---\n");
    printf("Valor em reais: R$%.2f\n", valorReais);
    printf("Valor em dólares: US$%.2f\n", valorDolar);

    return 0;
}