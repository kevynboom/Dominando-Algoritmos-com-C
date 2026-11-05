#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "");

    int qtdInteiras, qtdMeias;
    char diaSemana[50];
    char nacional[50];

    printf("Digite a quantidade de ingressos inteiras: ");
    scanf("%d", &qtdInteiras);

    printf("Digite a quantidade de ingressos meias: ");
    scanf("%d", &qtdMeias);

    while (getchar() != '\n');

    printf("Digite o dia da semana: ");
    fgets(diaSemana, sizeof(diaSemana), stdin);

    printf("O filme é nacional (Sim ou Não)? ");
    fgets(nacional, sizeof(nacional), stdin);

    diaSemana[strcspn(diaSemana, "\n")] = '\0';
    nacional[strcspn(nacional, "\n")] = '\0';

    double precoIngresso = 28.50;

    if (strcasecmp(nacional, "Sim") == 0) {
        precoIngresso = 5.00;
    } else if (strcasecmp(diaSemana, "Quarta-feira") == 0) {
        precoIngresso = 14.50;
    }

    double total = (qtdInteiras * precoIngresso) + (qtdMeias * (precoIngresso / 2.0));
    printf("Total à pagar:\nR$ %.2f\n", total);

    return 0;
}