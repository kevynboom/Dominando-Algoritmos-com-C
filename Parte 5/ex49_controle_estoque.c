#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int coletarOpcao() {
    exibirMenu();

    int opcao;
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    while (getchar() != '\n');

    return opcao;
}

void exibirMenu() {
    printf("\nMenu de Opções\n");
    printf("1. Adicionar produto\n");
    printf("2. Realizar entrada no estoque\n");
    printf("3. Realizar saída no estoque\n");
    printf("4. Listar estoque\n");
    printf("0. Sair\n");
}

void coletarNome(char nome[]) {
    printf("Digite o nome do produto: ");
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0';
}

int coletarQuantidade() {
    int quantidade;
    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);
    while (getchar() != '\n');

    return quantidade;
}

int coletarProduto() {
    int produto;
    printf("Digite o número do produto: ");
    scanf("%d", &produto);
    while (getchar() != '\n');

    return produto;
}

int processarCadastro(char nomes[][100], int quantidades[], int total, char nome[], int quantidade) {
    if (total >= 1000) {
        return -1;
    }

    strcpy(nomes[total], nome);
    quantidades[total] = quantidade;

    return total + 1;
}

int processarEntrada(int quantidades[], int produto, int quantidade, int total) {
    if (produto < 1 || produto > total || quantidade <= 0) {
        return 0;
    }

    quantidades[produto - 1] += quantidade;
    return 1;
}

int processarSaida(int quantidades[], int produto, int quantidade, int total) {
    if (produto < 1 || produto > total || quantidade <= 0) {
        return -1;
    }

    if (quantidade > quantidades[produto - 1]) {
        return -2;
    }

    quantidades[produto - 1] -= quantidade;
    return 1;
}

void exibirEstoque(char nomes[][100], int quantidades[], int total) {
    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Estoque atual:\n");

    for (int i = 0; i < total; i++) {
        printf("Produto %d: %s - %d unidades\n", i + 1, nomes[i], quantidades[i]);
    }
}

void exibirMensagem(char mensagem[]) {
    printf("%s\n", mensagem);
}

int main() {
    setlocale(LC_ALL, "");

    char nomes[1000][100];
    int quantidades[1000];
    int total = 0, opcao;

    do {
        opcao = coletarOpcao();

        switch (opcao) {
            case 1: {
                if (total >= 1000) {
                    exibirMensagem("Limite de produtos atingido.");
                } else {
                    char nome[100];
                    coletarNome(nome);
                    int quantidade = coletarQuantidade();

                    int vazio = 1;

                    for (int i = 0; nome[i] != '\0'; i++) {
                        if (!isspace((unsigned char)nome[i])) {
                            vazio = 0;
                            break;
                        }
                    }

                    if (vazio || quantidade < 0) {
                        exibirMensagem("Dados inválidos.");
                    } else {
                        total = processarCadastro(nomes, quantidades, total, nome, quantidade);
                        exibirMensagem("Produto adicionado com sucesso!");
                    }
                }
                break;
            }

            case 2: {
                if (total == 0) {
                    exibirMensagem("Nenhum produto cadastrado.");
                } else {
                    exibirEstoque(nomes, quantidades, total);
                    int produto = coletarProduto();
                    int quantidade = coletarQuantidade();

                    if (processarEntrada(quantidades, produto, quantidade, total)) {
                        exibirMensagem("Entrada realizada com sucesso!");
                    } else {
                        exibirMensagem("Dados inválidos.");
                    }
                }
                break;
            }

            case 3: {
                if (total == 0) {
                    exibirMensagem("Nenhum produto cadastrado.");
                } else {
                    exibirEstoque(nomes, quantidades, total);
                    int produto = coletarProduto();
                    int quantidade = coletarQuantidade();
                    int resultado = processarSaida(quantidades, produto, quantidade, total);

                    switch (resultado) {
                        case 1:
                            exibirMensagem("Saída realizada com sucesso!");
                            break;

                        case -2:
                            exibirMensagem("Quantidade insuficiente em estoque.");
                            break;

                        default:
                            exibirMensagem("Dados inválidos.");
                    }
                }
                break;
            }

            case 4:
                exibirEstoque(nomes, quantidades, total);
                break;

            case 0:
                exibirMensagem("Encerrando o programa...");
                break;

            default:
                exibirMensagem("Opção inválida.");
        }

    } while (opcao != 0);

    return 0;
}