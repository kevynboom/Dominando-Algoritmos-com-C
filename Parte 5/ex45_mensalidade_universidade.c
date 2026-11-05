#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

void coletarCurso(char curso[]) {
    printf("Digite a sigla do curso: ");
    fgets(curso, 100, stdin);
    curso[strcspn(curso, "\n")] = '\0';

    for (int i = 0; curso[i] != '\0'; i++) {
        curso[i] = toupper((unsigned char)curso[i]);
    }
}

int coletarIsencao() {
    char resposta[100];

    printf("O aluno é isento? (Sim ou Não): ");
    fgets(resposta, 100, stdin);
    resposta[strcspn(resposta, "\n")] = '\0';

    return strcmp(resposta, "sim") == 0 || strcmp(resposta, "SIM") == 0;
}

double coletarDesconto() {
    char entrada[100];

    printf("Digite o desconto (%%): ");
    fgets(entrada, 100, stdin);

    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] == ',') {
            entrada[i] = '.';
        }
    }

    double desconto;
    sscanf(entrada, "%lf", &desconto);

    return desconto;
}

double processarMensalidade(char curso[], int isento, double desconto) {
    double valor;

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
        return -1;
    }

    if (isento) {
        return 0;
    }

    return valor - (valor * desconto / 100);
}

void exibirResultado(double mensalidade) {
    if (mensalidade == -1) {
        printf("Curso não encontrado\n");
    } else {
        printf("Valor da mensalidade: R$ %.2f\n", mensalidade);
    }
}

int main() {
    setlocale(LC_ALL, "");

    char curso[100];

    coletarCurso(curso);
    int isento = coletarIsencao();
    double desconto = coletarDesconto();

    double mensalidade = processarMensalidade(curso, isento, desconto);

    exibirResultado(mensalidade);

    return 0;
}