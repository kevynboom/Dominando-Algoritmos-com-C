#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int n;

    printf("Digite a posição desejada: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Posição inválida.\n");
    } else if (n == 1 || n == 2) {
        printf("O valor na posição %d da sequência de Fibonacci é 1\n", n);
    } else {
        long long anterior = 1, atual = 1, proximo;

        for (int i = 3; i <= n; i++) {
            proximo = anterior + atual;
            anterior = atual;
            atual = proximo;
        }

        printf("O valor na posição %d da sequência de Fibonacci é %lld\n", n, atual);
    }

    return 0;
}