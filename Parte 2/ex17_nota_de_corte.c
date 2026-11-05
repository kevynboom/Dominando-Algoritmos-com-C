#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    double notaCandidato, notaCorte, notaMinima;

    printf("Digite a nota do candidato: ");
    scanf("%lf", &notaCandidato);

    printf("Digite a nota de corte: ");
    scanf("%lf", &notaCorte);

    printf("Digite a nota mínima para aprovação: ");
    scanf("%lf", &notaMinima);

    printf("Situação candidato:\n");

    if (notaCandidato >= notaMinima) {
        printf("Aprovado\n");
    } else if (notaCandidato < notaCorte) {
        printf("Reprovado\n");
    } else {
        printf("Lista de Espera\n");
    }

    return 0;
}