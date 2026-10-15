#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    float valorCompra;
    float desconto;
    float valorDesconto;
    float valorFinal;

    printf("--- Calculadora de Desconto ---\n");
    printf("Digite o valor da compra: R$");
    scanf("%f", &valorCompra);

    printf("Digite a porcentagem de desconto: ");
    scanf("%f", &desconto);
    
    valorDesconto = valorCompra * desconto / 100; // Calculando o valor do desconto
    valorFinal = valorCompra - valorDesconto; // Calculando o valor final

    printf("\n--- Resultado ---\n");
    printf("Valor da compra: R$%.2f\n", valorCompra);
    printf("Desconto: %.2f%%\n", desconto);
    printf("Valor do desconto: R$%.2f\n", valorDesconto);
    printf("Valor final: R$%.2f\n", valorFinal);

    return 0;
}