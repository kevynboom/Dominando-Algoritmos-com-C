#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    char produtos[1000][100];
    int quantidades[1000];
    int qtdProdutos = 0, opcao, numero, quantidade;

    do {
        printf("\n===== CONTROLE DE ESTOQUE =====\n");
        printf("1. Adicionar produto\n");
        printf("2. Realizar entrada no estoque\n");
        printf("3. Realizar saída no estoque\n");
        printf("4. Listar estoque\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                if (qtdProdutos >= 1000) {
                    printf("Limite de produtos atingido!\n");
                } else {
                    printf("Digite o nome do produto: ");
                    fgets(produtos[qtdProdutos], sizeof(produtos[qtdProdutos]), stdin);
                    produtos[qtdProdutos][strcspn(produtos[qtdProdutos], "\n")] = '\0';

                    printf("Digite a quantidade inicial: ");
                    scanf("%d", &quantidades[qtdProdutos]);

                    qtdProdutos++;
                    printf("Produto adicionado com sucesso!\n");
                }
                break;

            case 2:
                if (qtdProdutos == 0) {
                    printf("Não existem produtos cadastrados!\n");
                } else {
                    printf("Digite o número do produto: ");
                    scanf("%d", &numero);

                    if (numero < 1 || numero > qtdProdutos) {
                        printf("Produto inválido!\n");
                    } else {
                        printf("Digite a quantidade de entrada: ");
                        scanf("%d", &quantidade);

                        if (quantidade > 0) {
                            quantidades[numero - 1] += quantidade;
                            printf("Entrada realizada com sucesso!\n");
                        } else {
                            printf("Quantidade inválida!\n");
                        }
                    }
                }
                break;

            case 3:
                if (qtdProdutos == 0) {
                    printf("Não existem produtos cadastrados!\n");
                } else {
                    printf("Digite o número do produto: ");
                    scanf("%d", &numero);

                    if (numero < 1 || numero > qtdProdutos) {
                        printf("Produto inválido!\n");
                    } else {
                        printf("Digite a quantidade de saída: ");
                        scanf("%d", &quantidade);

                        if (quantidade <= 0) {
                            printf("Quantidade inválida!\n");
                        } else if (quantidade > quantidades[numero - 1]) {
                            printf("Quantidade indisponível em estoque!\n");
                        } else {
                            quantidades[numero - 1] -= quantidade;
                            printf("Saída realizada com sucesso!\n");
                        }
                    }
                }
                break;

            case 4:
                if (qtdProdutos == 0) {
                    printf("Não existem produtos cadastrados!\n");
                } else {
                    printf("\n===== ESTOQUE ATUAL =====\n");
                    for (int i = 0; i < qtdProdutos; i++) {
                        printf("Produto %d: %s - %d unidades\n", i + 1, produtos[i], quantidades[i]);
                    }
                }
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}