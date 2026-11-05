#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    double nota1, nota2, nota3;
    int faltas;

    printf("Digite a nota 1: ");
    scanf("%lf", &nota1);

    printf("Digite a nota 2: ");
    scanf("%lf", &nota2);

    printf("Digite a nota 3: ");
    scanf("%lf", &nota3);

    printf("Digite a quantidade de faltas: ");
    scanf("%d", &faltas);

    if (nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10 || nota3 < 0 || nota3 > 10 || faltas < 0) {
        printf("Parâmetros inválidos\n");
    } else {
        double media = (nota1 + nota2 + nota3) / 3.0;
        printf("Média: %.1f.\n", media);

        if (faltas > 4) {
            printf("Situação: Reprovado por Falta\n");
        } else if (media == 0) {
            printf("Situação: Desistente\n");
        } else if (media >= 8 && media <= 10) {
            printf("Situação: Aprovado com sucesso\n");
        } else if (media >= 6 && media < 8) {
            printf("Situação: Aprovado\n");
        } else if (media < 6) {
            printf("Situação: Recuperação\n");
        }
    }

    return 0;
}