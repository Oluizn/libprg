#include "libprg/projeto2.h"
#include "stdio.h"
#include "string.h"


void menu_tarefas () {
    int operador = 0;
    estrutura *lista_tarefa = NULL;
    while (operador != 9) {
        fflush(stdin);
        printf("Escolha uma acao:\n");
        printf("1 - Nova tarefa:\n");
        printf("2 - Lista de tarefas:\n");
        printf("3 - Remover tarefa:\n");
        printf("9 - Sair.\n");

        scanf("%d", &operador);

        if(operador != 9){
            switch (operador) {
                case 1: {
                    fflush(stdin);
                    char descricao[100], prazo[13];
                    int prioridade;
                    printf("Por favor informe a descricao da tarefa: ");
                    scanf("%c", &descricao);
                    printf("Por favor informe o prazo da tarefa: ");
                    scanf("%c", &prazo);
                    printf("Por favor informe o nivel de prioridade da tarefa.\n1 - Baixo\n2 - Medio\n3 - Alto\n");
                    scanf("%d", &prioridade);
                    inserir_inicio_tarefa(lista_tarefa, descricao, prioridade, prazo);
                    break;
                }
                case 2: {
                    fflush(stdin);
                    imprimir_lista_tarefa(lista_tarefa);
                    break;
                }
                case 3: {
                    fflush(stdin);
                    imprimir_lista_tarefa(lista_tarefa);
                    printf("\n");
                    int operador_removedor;
                    printf("Por favor, insira o codigo da tarefa que deseja remover: ");
                    scanf("%d", &operador_removedor);
                    remover_tarefa(&lista_tarefa, operador_removedor);
                    break;
                }
                default:
                    printf("Opcao invalida, escolha entre 1 e 3, ou pressione 9 para sair");
                fflush(stdin);
            }
        }
        else
            printf("Adeus!.\n");
    }
}