#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    setlocale(LC_ALL, "");

    printf("--- CALCULADORA ---\n");
    printf("Operações aceitas:\nSoma(+), subtração(-), multiplicacao(*), divisão(/), resto(%%) e potência(^)\n\n");

    double n1, n2;
    char op[50];

    printf("Digite o primeiro número: ");
    scanf("%lf", &n1);

    while (getchar() != '\n');

    printf("Digite a operação: ");
    fgets(op, sizeof(op), stdin);

    printf("Digite o segundo número: ");
    scanf("%lf", &n2);

    op[strcspn(op, "\n")] = '\0';

    for (int i = 0; op[i] != '\0'; i++) {
        op[i] = tolower((unsigned char)op[i]);
    }

    if (strcmp(op, "+") == 0 || strcmp(op, "soma") == 0) {
        printf("%.2f + %.2f = %.2f\n", n1, n2, n1 + n2);
    } else if (strcmp(op, "-") == 0 || strcmp(op, "subtracao") == 0) {
        printf("%.2f - %.2f = %.2f\n", n1, n2, n1 - n2);
    } else if (strcmp(op, "*") == 0 || strcmp(op, "multiplicacao") == 0) {
        printf("%.2f * %.2f = %.2f\n", n1, n2, n1 * n2);
    } else if (strcmp(op, "/") == 0 || strcmp(op, "divisao") == 0) {
        printf("%.2f / %.2f = %.2f\n", n1, n2, n1 / n2);
    } else if (strcmp(op, "%") == 0 || strcmp(op, "resto") == 0) {
        printf("%.2f %% %.2f = %.2f\n", n1, n2, fmod(n1, n2));
    } else if (strcmp(op, "^") == 0 || strcmp(op, "potencia") == 0) {
        printf("%.2f ^ %.2f = %.2f\n", n1, n2, pow(n1, n2));
    } else {
        printf("Operação não suportada\n");
    }

    return 0;
}