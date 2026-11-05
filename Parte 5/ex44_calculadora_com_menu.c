#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

double coletarPrimeiroValor() {
    double valor;
    printf("Digite o primeiro valor: ");
    scanf("%lf", &valor);
    return valor;
}

double coletarSegundoValor() {
    double valor;
    printf("Digite o segundo valor: ");
    scanf("%lf", &valor);
    return valor;
}

void coletarOperacao(char operacao[]) {
    while (getchar() != '\n');

    printf("\n===== CALCULADORA =====\n");
    printf("1. Soma\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Resto\n");
    printf("6. Potência\n");
    printf("Escolha uma operação: ");

    fgets(operacao, 100, stdin);
    operacao[strcspn(operacao, "\n")] = '\0';

    for (int i = 0; operacao[i] != '\0'; i++) {
        operacao[i] = tolower((unsigned char)operacao[i]);
    }
}

double processarDados(double valor1, double valor2, char operacao[]) {
    if (strcmp(operacao, "1") == 0 || strcmp(operacao, "soma") == 0) {
        return valor1 + valor2;
    } else if (strcmp(operacao, "2") == 0 || strcmp(operacao, "subtração") == 0 || strcmp(operacao, "subtracao") == 0) {
        return valor1 - valor2;
    } else if (strcmp(operacao, "3") == 0 || strcmp(operacao, "multiplicação") == 0 || strcmp(operacao, "multiplicacao") == 0) {
        return valor1 * valor2;
    } else if (strcmp(operacao, "4") == 0 || strcmp(operacao, "divisão") == 0 || strcmp(operacao, "divisao") == 0) {
        return valor2 != 0 ? valor1 / valor2 : NAN;
    } else if (strcmp(operacao, "5") == 0 || strcmp(operacao, "resto") == 0) {
        return valor2 != 0 ? fmod(valor1, valor2) : NAN;
    } else if (strcmp(operacao, "6") == 0 || strcmp(operacao, "potência") == 0 || strcmp(operacao, "potencia") == 0) {
        return pow(valor1, valor2);
    } else {
        return NAN;
    }
}

void exibirResultado(double valor1, double valor2, char operacao[], double resultado) {
    if (isnan(resultado)) {
        if (strcmp(operacao, "4") == 0 || strcmp(operacao, "divisão") == 0 || strcmp(operacao, "divisao") == 0 ||
            strcmp(operacao, "5") == 0 || strcmp(operacao, "resto") == 0) {
            printf("Não é possível dividir por zero.\n");
        } else {
            printf("Operação não suportada.\n");
        }
        return;
    }

    char simbolo[10] = "";

    if (strcmp(operacao, "1") == 0 || strcmp(operacao, "soma") == 0) {
        strcpy(simbolo, "+");
    } else if (strcmp(operacao, "2") == 0 || strcmp(operacao, "subtração") == 0 || strcmp(operacao, "subtracao") == 0) {
        strcpy(simbolo, "-");
    } else if (strcmp(operacao, "3") == 0 || strcmp(operacao, "multiplicação") == 0 || strcmp(operacao, "multiplicacao") == 0) {
        strcpy(simbolo, "*");
    } else if (strcmp(operacao, "4") == 0 || strcmp(operacao, "divisão") == 0 || strcmp(operacao, "divisao") == 0) {
        strcpy(simbolo, "/");
    } else if (strcmp(operacao, "5") == 0 || strcmp(operacao, "resto") == 0) {
        strcpy(simbolo, "mod");
    } else if (strcmp(operacao, "6") == 0 || strcmp(operacao, "potência") == 0 || strcmp(operacao, "potencia") == 0) {
        strcpy(simbolo, "^");
    }

    printf("%.1f %s %.1f = %.1f\n", valor1, simbolo, valor2, resultado);
}

int main() {
    setlocale(LC_ALL, "");

    double valor1 = coletarPrimeiroValor();
    double valor2 = coletarSegundoValor();

    char operacao[100];
    coletarOperacao(operacao);

    double resultado = processarDados(valor1, valor2, operacao);

    exibirResultado(valor1, valor2, operacao, resultado);

    return 0;
}