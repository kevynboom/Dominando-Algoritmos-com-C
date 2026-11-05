#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "");

    char cor[50];

    printf("Digite a cor atual do semáforo: ");
    fgets(cor, sizeof(cor), stdin);

    if (strcasecmp(cor, "Vermelho\n") == 0) {
        printf("Espere\n");
    } else if (strcasecmp(cor, "Verde\n") == 0) {
        printf("Atravesse\n");
    } else {
        printf("Farol inoperante\n");
    }

    return 0;
}