#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int coletarInteiras() {
    int inteiras;
    printf("Quantidade de ingressos inteiras: ");
    scanf("%d", &inteiras);
    while (getchar() != '\n');
    return inteiras;
}

int coletarMeias() {
    int meias;
    printf("Quantidade de ingressos meias: ");
    scanf("%d", &meias);
    while (getchar() != '\n');
    return meias;
}

void coletarDia(char dia[]) {
    printf("Digite o dia da semana: ");
    fgets(dia, 100, stdin);
    dia[strcspn(dia, "\n")] = '\0';

    for (int i = 0; dia[i] != '\0'; i++) {
        dia[i] = tolower((unsigned char)dia[i]);
    }
}

int coletarNacional() {
    char resposta[100];

    printf("O filme é nacional? (Sim ou Não): ");
    fgets(resposta, 100, stdin);
    resposta[strcspn(resposta, "\n")] = '\0';

    return strcmp(resposta, "sim") == 0 || strcmp(resposta, "SIM") == 0;
}

double processarTotal(int inteiras, int meias, char dia[], int nacional) {
    double valorIngresso;

    if (strcmp(dia, "quarta-feira") == 0) {
        valorIngresso = nacional ? 5.00 : 14.50;
    } else {
        valorIngresso = nacional ? 5.00 : 28.50;
    }

    return (inteiras + meias) * valorIngresso;
}

void exibirResultado(double total) {
    printf("Total à pagar: R$ %.2f\n", total);
}

int main() {
    setlocale(LC_ALL, "");

    int inteiras = coletarInteiras();
    int meias = coletarMeias();

    char dia[100];
    coletarDia(dia);

    int nacional = coletarNacional();

    double total = processarTotal(inteiras, meias, dia, nacional);

    exibirResultado(total);

    return 0;
}