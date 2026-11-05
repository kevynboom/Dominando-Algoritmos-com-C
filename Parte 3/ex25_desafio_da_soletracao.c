#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "");

    char palavraOriginal[100];
    char palavraSoletrada[500] = "";
    char letra[50];

    printf("Digite a palavra original: ");
    fgets(palavraOriginal, sizeof(palavraOriginal), stdin);

    palavraOriginal[strcspn(palavraOriginal, "\n")] = '\0';

    printf("Digite a palavra letra por letra (digite '0' para encerrar): \n");

    do {
        printf("Digite uma letra: ");
        fgets(letra, sizeof(letra), stdin);

        letra[strcspn(letra, "\n")] = '\0';

        if (strcmp(letra, "0") == 0) {
            break;
        }

        strcat(palavraSoletrada, letra);

    } while (1);

    printf("Palavra original: %s\n", palavraOriginal);
    printf("Palavra soletrada: %s\n", palavraSoletrada);

    return 0;
}