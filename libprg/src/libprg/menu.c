#include "libprg/projeto2.h"
#include "stdio.h"

void menu_tarefas () {
    int operador = 0;
    tarefa_no *lista_tarefa_nao_concluida = NULL;
    while (operador != 9) {
        fflush(stdin);
        printf("Escolha uma acao:\n");
        printf("1 - Nova tarefa:\n");
        printf("2 - Lista de tarefas:\n");
        printf("3 - Remover tarefa:\n");
        printf("4 - Editar tarefa:\n");
        printf("9 - Sair.\n");

        scanf("%d", &operador);

        if(operador != 9){
            switch (operador) {
                case 1: { // TODO -> verificar o por que da função fgets não funcionar corretamente no linux ubuntu
                    fflush(stdin);
                    char descricao[100], prazo[13];
                    int prioridade;
                    printf("Por favor informe a descricao da tarefa:");
                    fgets(descricao, 100, stdin);
                    fflush(stdin);
                    printf("Por favor informe o prazo da tarefa:");
                    fgets(prazo, 13, stdin);
                    fflush(stdin);
                    printf("Por favor informe o nivel de prioridade da tarefa.\n1 - Baixo\n2 - Medio\n3 - Alto\n");
                    scanf("%d", &prioridade);
                    fflush(stdin);
                    lista_tarefa_nao_concluida = inserir_tarefa(lista_tarefa_nao_concluida, descricao, prioridade, prazo);
                    break;
                }
                case 2: {
                    fflush(stdin);
                    imprimir_lista_tarefa(lista_tarefa_nao_concluida);
                    break;
                }
                case 3: {
                    fflush(stdin);
                    imprimir_lista_tarefa(lista_tarefa_nao_concluida);
                    if (lista_tarefa_nao_concluida) {
                        printf("\n");
                        int operador_removedor;
                        printf("Por favor, insira o codigo da tarefa que deseja remover: ");
                        scanf("%d", &operador_removedor);
                        fflush(stdin);
                        remover_tarefa(&lista_tarefa_nao_concluida, operador_removedor);
                    }
                    break;
                }
                case 4: { // TODO -> formular menu para edição da tarefa
                    int codigo, operador_edicao;
                    fflush(stdin);
                    imprimir_lista_tarefa(lista_tarefa_nao_concluida);
                    printf("Digite o codigo da tarefa que deseja editar:\n");
                    scanf("%d", &codigo);
                    fflush(stdin);
                    printf("Escolha o que deseja editar: \n");
                    printf("1 - descricao:");
                    printf("2 - prioridade:");
                    printf("3 - prazo:");
                    scanf("%d", &operador_edicao);

                    }
                default:
                    printf("Opcao invalida, escolha entre 1 e 3, ou pressione 9 para sair\n");
                fflush(stdin);
            }
        }
        else
            printf("Adeus!.\n");
    }
}