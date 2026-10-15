#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int pessoas;

    printf("--- Churrasco de Domingo ---\n");
    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &pessoas);

    // Quantidade de cada alimento por pessoa
    float carnePorPessoa = 0.300;
    float linguicaPorPessoa = 0.200;
    float frangoPorPessoa = 0.150;

    // Preço por kg
    float precoCarne = 50.00;
    float precoLinguica = 28.00;
    float precoFrango = 22.00;

    // Quantidade total em kg
    float carneTotal = carnePorPessoa * pessoas;
    float linguicaTotal = linguicaPorPessoa * pessoas;
    float frangoTotal = frangoPorPessoa * pessoas;

    // Custo de cada alimento
    float custoCarne = carneTotal * precoCarne;
    float custoLinguica = linguicaTotal * precoLinguica;
    float custoFrango = frangoTotal * precoFrango;

    // Custo total e valor por pessoa
    float custoTotal = custoCarne + custoLinguica + custoFrango;
    float valorPorPessoa = custoTotal / pessoas;

    printf("\n--- Resultado ---\n");
    printf("Carne: %.2f kg - R$%.2f\n", carneTotal, custoCarne);
    printf("Linguiça: %.2f kg - R$%.2f\n", linguicaTotal, custoLinguica);
    printf("Frango: %.2f kg - R$%.2f\n", frangoTotal, custoFrango);

    printf("\nCusto total: R$%.2f\n", custoTotal);
    printf("Cada pessoa deve pagar: R$%.2f\n", valorPorPessoa);

    return 0;
}