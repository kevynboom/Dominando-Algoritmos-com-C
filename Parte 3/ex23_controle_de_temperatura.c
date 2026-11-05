#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    double temp, maior = 0, menor = 0;
    int primeiraValida = 0;

    do {
        printf("Digite a temperatura (0 para sair): ");
        scanf("%lf", &temp);

        if (temp == 0) {
            break;
        }

        if (temp < -50 || temp > 60) {
            printf("Temperatura inválida\n");
        } else {
            if (!primeiraValida) {
                maior = temp;
                menor = temp;
                primeiraValida = 1;
            } else {
                if (temp > maior) {
                    maior = temp;
                }
                if (temp < menor) {
                    menor = temp;
                }
            }
        }
    } while (1);

    if (primeiraValida) {
        printf("Maior temperatura: %.0f\n", maior);
        printf("Menor temperatura: %.0f\n", menor);
    }

    return 0;
}