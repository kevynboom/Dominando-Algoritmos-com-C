#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int altura;

    printf("Digite a altura do triângulo: ");
    scanf("%d", &altura);

    if (altura <= 0) {
        printf("Triângulo inválido\n");
    } else {
        for (int i = 1; i <= altura; i++) {
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }

    return 0;
}