#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int opcao;

    do {
        printf("Digite a opção: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            printf("Fim.\n");
        } else if (opcao >= 1 && opcao <= 4) {
            double n1, n2;

            printf("Digite o primeiro valor: ");
            scanf("%lf", &n1);

            printf("Digite o segundo valor: ");
            scanf("%lf", &n2);

            switch (opcao) {
                case 1:
                    printf("Resultado: %.2f + %.2f = %.2f\n", n1, n2, (n1 + n2));
                    break;
                case 2:
                    printf("Resultado: %.2f - %.2f = %.2f\n", n1, n2, (n1 - n2));
                    break;
                case 3:
                    printf("Resultado: %.2f * %.2f = %.2f\n", n1, n2, (n1 * n2));
                    break;
                case 4:
                    if (n2 == 0) {
                        printf("Divisão por zero não permitida\n");
                    } else {
                        printf("Resultado: %.2f / %.2f = %.2f\n", n1, n2, (n1 / n2));
                    }
                    break;
            }
        } else {
            printf("Opção inválida\n");
        }
    } while (opcao != 0);

    return 0;
}