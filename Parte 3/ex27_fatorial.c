#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    if (numero <= 0) {
        printf("Parâmetro inválido.\n");
    } else {
        long long fatorial = 1;

        for (int i = 1; i <= numero; i++) {
            fatorial *= i;
        }

        printf("O fatorial de %d é %lld.\n", numero, fatorial);
    }

    return 0;
}