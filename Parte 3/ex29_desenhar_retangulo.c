#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int base, altura;

    printf("Digite a base do retângulo: ");
    scanf("%d", &base);

    printf("Digite a altura do retângulo: ");
    scanf("%d", &altura);

    if (base <= 0 || altura <= 0) {
        printf("Retângulo inválido\n");
    } else {
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < base; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }

    return 0;
}