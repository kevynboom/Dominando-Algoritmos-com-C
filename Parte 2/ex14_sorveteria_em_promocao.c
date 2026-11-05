#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    double gramas;

    printf("Digite o peso em gramas: ");
    scanf("%lf", &gramas);

    if (gramas <= 0) {
        printf("Peso Inválido\n");
    } else {
        double total = (gramas / 100.0) * (gramas >= 1000 ? 3.00 : 3.50);
        printf("O total é R$ %.2f\n", total);
    }

    return 0;
}