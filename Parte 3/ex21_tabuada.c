#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, (numero * i));
    }

    return 0;
}