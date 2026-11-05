#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "");

    char cor1[50];
    char cor2[50];

    printf("Digite a primeira cor: ");
    fgets(cor1, sizeof(cor1), stdin);

    printf("Digite a segunda cor: ");
    fgets(cor2, sizeof(cor2), stdin);

    cor1[strcspn(cor1, "\n")] = '\0';
    cor2[strcspn(cor2, "\n")] = '\0';

    int ehPrimaria1 = strcmp(cor1, "Vermelho") == 0 || strcmp(cor1, "Azul") == 0 || strcmp(cor1, "Amarelo") == 0;
    int ehPrimaria2 = strcmp(cor2, "Vermelho") == 0 || strcmp(cor2, "Azul") == 0 || strcmp(cor2, "Amarelo") == 0;

    if (!ehPrimaria1 || !ehPrimaria2) {
        printf("Apenas cores primárias são aceitas.\n");
    } else if ((strcmp(cor1, "Vermelho") == 0 && strcmp(cor2, "Azul") == 0) || (strcmp(cor1, "Azul") == 0 && strcmp(cor2, "Vermelho") == 0)) {
        printf("A combinação resulta em:\nRoxo\n");
    } else if ((strcmp(cor1, "Vermelho") == 0 && strcmp(cor2, "Amarelo") == 0) || (strcmp(cor1, "Amarelo") == 0 && strcmp(cor2, "Vermelho") == 0)) {
        printf("A combinação resulta em:\nLaranja\n");
    } else if ((strcmp(cor1, "Azul") == 0 && strcmp(cor2, "Amarelo") == 0) || (strcmp(cor1, "Amarelo") == 0 && strcmp(cor2, "Azul") == 0)) {
        printf("A combinação resulta em:\nVerde\n");
    } else {
        printf("A combinação resulta em:\n%s\n", cor1);
    }

    return 0;
}