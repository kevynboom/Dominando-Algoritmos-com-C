#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int dia;
    scanf("%d", &dia);

    switch (dia) {
        case 0:
            printf("Domingo\n");
            break;
        case 1:
            printf("Segunda-feira\n");
            break;
        case 2:
            printf("Terça-feira\n");
            break;
        case 3:
            printf("Quarta-feira\n");
            break;
        case 4:
            printf("Quinta-feira\n");
            break;
        case 5:
            printf("Sexta-feira\n");
            break;
        case 6:
            printf("Sábado\n");
            break;
        default:
            printf("Dia da semana inválido\n");
    }

    return 0;
}