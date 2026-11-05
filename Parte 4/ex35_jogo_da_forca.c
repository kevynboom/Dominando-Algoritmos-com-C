#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "");

    char palavra[100];

    printf("Digite a palavra secreta: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    for (int i = 0; i < strlen(palavra); i++) {
        palavra[i] = toupper((unsigned char)palavra[i]);
    }

    for (int i = 0; i < 30; i++) {
        printf("\n");
    }

    char estado[strlen(palavra)];
    int erros = 0;

    for (int i = 0; i < strlen(palavra); i++) {
        estado[i] = '_';
    }

    while (erros < 7) {
        int acertou = 1;

        for (int i = 0; i < strlen(palavra); i++) {
            if (estado[i] == '_') {
                acertou = 0;
                break;
            }
        }

        if (acertou) {
            break;
        }

        char letra[10];

        printf("Digite uma letra: ");
        fgets(letra, sizeof(letra), stdin);
        letra[0] = toupper((unsigned char)letra[0]);

        int encontrou = 0;

        for (int i = 0; i < strlen(palavra); i++) {
            if (palavra[i] == letra[0]) {
                estado[i] = letra[0];
                encontrou = 1;
            }
        }

        if (!encontrou) {
            erros++;
        }

        printf("\nEstado: ");

        for (int i = 0; i < strlen(palavra); i++) {
            printf("%c%s", estado[i], i < strlen(palavra) - 1 ? " " : "\n");
        }

        printf("Erros: %d\n", erros);
    }

    int venceu = 1;

    for (int i = 0; i < strlen(palavra); i++) {
        if (estado[i] == '_') {
            venceu = 0;
            break;
        }
    }

    if (venceu) {
        printf("\nParabéns! Você descobriu a palavra.\n");
    } else {
        printf("\nVocê perdeu! A palavra era: %s\n", palavra);
    }

    return 0;
}