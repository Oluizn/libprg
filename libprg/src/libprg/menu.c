#include "libprg/projeto2.h"
#include "stdio.h"

void menu_tarefas () {
    int operador = 0;
    tarefa_no *lista_tarefa = NULL;
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
                    lista_tarefa = inserir_tarefa(lista_tarefa, descricao, prioridade, prazo);
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
                    if (lista_tarefa) {
                        printf("\n");
                        int operador_removedor;
                        printf("Por favor, insira o codigo da tarefa que deseja remover: ");
                        scanf("%d", &operador_removedor);
                        fflush(stdin);
                        remover_tarefa(&lista_tarefa, operador_removedor);
                    }
                    break;
                }
                case 4: { // TODO -> formular menu para edição da tarefa
                    int codigo, operador_edicao, novo_prioridade;
                    char nova_descricao[100], prazo[13];
                    fflush(stdin);
                    imprimir_lista_tarefa(lista_tarefa);
                    printf("Digite o codigo da tarefa que deseja editar:\n");
                    scanf("%d", &codigo);
                    fflush(stdin);
                    printf("Escolha o que deseja editar: \n");
                    printf("1 - descricao:");
                    printf("2 - prioridade:");
                    printf("3 - prazo:");
                    scanf("%d", &operador_edicao);
                    if(operador_edicao == 1) {
                        printf("Insira a nova descricao: ");
                        fgets(nova_descricao, 100, stdin);
                        fflush(stdin);
                        editar_tarefa_descricao(lista_tarefa, nova_descricao, codigo);
                    }
                    else if(operador_edicao == 2) {
                        printf("Insira novo nivel de prioridade da tarefa.\n1 - Baixo\n2 - Medio\n3 - Alto\n");
                        scanf("%d", &novo_prioridade);
                        fflush(stdin);
                        editar_tarefa_prioridade(lista_tarefa, novo_prioridade, codigo);
                    }
                    else if(operador_edicao == 3) {
                        printf("Insira o novo prazo: ");
                        fgets(prazo, 13, stdin);
                        fflush(stdin);
                        editar_tarefa_prazo(lista_tarefa, prazo, codigo);
                    }
                    else
                        printf("Valor invalido");
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