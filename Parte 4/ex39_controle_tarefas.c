#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "");

    char tarefas[100][100];
    int concluidas[100];
    int qtdTarefas = 0, opcao, numero;

    do {
        printf("\n===== CONTROLE DE TAREFAS =====\n");
        printf("1. Adicionar tarefa\n");
        printf("2. Listar tarefas\n");
        printf("3. Marcar concluída\n");
        printf("4. Exibir pendentes\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                if (qtdTarefas >= 100) {
                    printf("Limite de tarefas atingido!\n");
                } else {
                    printf("Digite a descrição da tarefa: ");
                    fgets(tarefas[qtdTarefas], sizeof(tarefas[qtdTarefas]), stdin);
                    tarefas[qtdTarefas][strcspn(tarefas[qtdTarefas], "\n")] = '\0';

                    concluidas[qtdTarefas] = 0;
                    qtdTarefas++;

                    printf("Tarefa adicionada com sucesso!\n");
                }
                break;

            case 2:
                if (qtdTarefas == 0) {
                    printf("Não existem tarefas cadastradas!\n");
                } else {
                    printf("\nLista de tarefas:\n");

                    for (int i = 0; i < qtdTarefas; i++) {
                        printf("%d - [%s] %s\n", i + 1, concluidas[i] ? "X" : " ", tarefas[i]);
                    }
                }
                break;

            case 3:
                if (qtdTarefas == 0) {
                    printf("Não existem tarefas cadastradas!\n");
                } else {
                    printf("Digite o número da tarefa: ");
                    scanf("%d", &numero);

                    if (numero < 1 || numero > qtdTarefas) {
                        printf("Número de tarefa inválido!\n");
                    } else if (concluidas[numero - 1]) {
                        printf("Esta tarefa já foi concluída!\n");
                    } else {
                        concluidas[numero - 1] = 1;
                        printf("Tarefa %d marcada como concluída.\n", numero);
                    }
                }
                break;

            case 4:
                if (qtdTarefas == 0) {
                    printf("Não existem tarefas cadastradas!\n");
                } else {
                    int existePendente = 0;
                    printf("\nTarefas pendentes:\n");

                    for (int i = 0; i < qtdTarefas; i++) {
                        if (!concluidas[i]) {
                            printf("%d - [ ] %s\n", i + 1, tarefas[i]);
                            existePendente = 1;
                        }
                    }

                    if (!existePendente) {
                        printf("Não existem tarefas pendentes!\n");
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