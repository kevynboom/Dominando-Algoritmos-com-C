#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int pequeno, medio, grande;
    float desconto, valorTotal, valorDesconto, valorFinal;

    printf("--- Venda de Açaí ---\n");
    printf("Digite a quantidade de açaí pequeno: ");
    scanf("%d", &pequeno);

    printf("Digite a quantidade de açaí médio: ");
    scanf("%d", &medio);

    printf("Digite a quantidade de açaí grande: ");
    scanf("%d", &grande);

    printf("Digite a porcentagem de desconto: ");
    scanf("%f", &desconto);

    valorTotal = (pequeno * 13.50) + (medio * 15.00) + (grande * 17.50); 
    valorDesconto = valorTotal * desconto / 100; 
    valorFinal = valorTotal - valorDesconto; 

    printf("\n--- Resultado ---\n");
    printf("Açaí pequeno: %d\n", pequeno);
    printf("Açaí médio: %d\n", medio);
    printf("Açaí grande: %d\n", grande);
    printf("Valor total: R$%.2f\n", valorTotal);
    printf("Desconto: %.2f%%\n", desconto);
    printf("Valor final: R$%.2f\n", valorFinal);

    return 0;
}