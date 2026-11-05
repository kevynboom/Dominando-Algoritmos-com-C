#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    float peso, altura, imc;

    printf("--- Calculadora de IMC ---\n");
    printf("Digite o seu peso em kg: ");
    scanf("%f", &peso);

    printf("Digite a sua altura em metros: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura); 

    printf("\n--- Resultado ---\n");
    printf("Peso: %.2f kg\n", peso);
    printf("Altura: %.2f m\n", altura);
    printf("IMC: %.2f\n", imc);

    return 0;
}