#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int main() {
    setlocale(LC_ALL, "");

    char curso[50];
    char isento[50];
    double desconto;

    printf("Digite a sigla do curso: ");
    fgets(curso, sizeof(curso), stdin);

    printf("É isento (sim ou não)? ");
    fgets(isento, sizeof(isento), stdin);

    printf("Digite o desconto em (%%): ");
    scanf("%lf", &desconto);

    curso[strcspn(curso, "\n")] = '\0';
    isento[strcspn(isento, "\n")] = '\0';

    for (int i = 0; curso[i] != '\0'; i++) {
        curso[i] = toupper((unsigned char)curso[i]);
    }

    for (int i = 0; isento[i] != '\0'; i++) {
        isento[i] = tolower((unsigned char)isento[i]);
    }

    double valor = 0;
    int encontrado = 1;

    if (strcmp(curso, "SI") == 0) {
        valor = 900.00;
    } else if (strcmp(curso, "ADS") == 0) {
        valor = 750.00;
    } else if (strcmp(curso, "CS") == 0) {
        valor = 1150.00;
    } else if (strcmp(curso, "EC") == 0) {
        valor = 1300.00;
    } else if (strcmp(curso, "ES") == 0) {
        valor = 950.00;
    } else {
        encontrado = 0;
    }

    if (!encontrado) {
        printf("Curso não encontrado\n");
    } else {
        if (strcmp(isento, "sim") == 0) {
            valor = 0.0;
        } else if (desconto > 0) {
            valor = valor - (valor * (desconto / 100.0));
        }

        printf("Valor da mensalidade:\nR$ %.2f\n", valor);
    }

    return 0;
}