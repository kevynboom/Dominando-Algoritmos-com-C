#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int n;

    printf("Digite a quantidade de alunos da turma: ");
    scanf("%d", &n);

    double notas[n];
    double soma = 0;
    int aprovados = 0, reprovados = 0;

    for (int i = 0; i < n; i++) {
        printf("Digite a nota do aluno %d (0 a 10): ", (i + 1));
        scanf("%lf", &notas[i]);
        soma += notas[i];

        if (notas[i] >= 6.0) {
            aprovados++;
        } else {
            reprovados++;
        }
    }

    double maior = notas[0];
    double menor = notas[0];

    for (int i = 1; i < n; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
        if (notas[i] < menor) {
            menor = notas[i];
        }
    }

    double media = soma / n;

    printf("\n>> Resultado da Turma <<\n");
    printf("Notas informadas: ");

    for (int i = 0; i < n; i++) {
        printf("%.0f", notas[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("\n");

    printf("Média da turma: %.0f\n", media);
    printf("Maior nota: %.0f\n", maior);
    printf("Menor nota: %.0f\n", menor);
    printf("Aprovados: %d\n", aprovados);
    printf("Reprovados: %d\n", reprovados);

    if (aprovados == n) {
        printf("Situação geral: Todos os alunos foram aprovados\n");
    } else {
        printf("Situação geral: Nem todos os alunos foram aprovados\n");
    }

    return 0;
}