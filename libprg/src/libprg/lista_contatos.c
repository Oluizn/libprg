#include "stdio.h"
#include "stdlib.h"
#include "libprg/libprg.h"


// indice da lista
int counter = 0;
// vetor contendo struct contatos
contact contacts[SIZE];

void salvar_contato(contact ctt, FILE *file){

    // Insere as informações no arquivo em seus respectivos lugares da struct
    fputs(ctt.name, file);
    fputs(ctt.phone, file);
    fputs(ctt.email, file);
}

int inserir_contato(contact ctt){
    int r = 0; // Atributo booleano, 0 para falso e qualquer outro valor para verdadeiro
    FILE *file = fopen(FILE_NAME, "a+");        // Abre um arquivo, método "a+" para criar o arquivo caso ele ainda não exista

    // Teste para ver se arquivo existe
    if(file != NULL) {
        r = 1;  // Atribui true à variável
        salvar_contato(ctt, file);
        contacts[counter] = ctt;
        counter++;
    }
    fclose(file);
    return r;
}

// Função recursiva
int buscar_nome(char *nome_fornecido, char *nome_na_lista, int indexador_inicio, int indexador_limitante){
    if(nome_fornecido[indexador_inicio] == nome_na_lista[indexador_inicio]){
        indexador_inicio++;
        if(indexador_inicio < indexador_limitante){
            return buscar_nome(nome_fornecido, nome_na_lista, indexador_inicio, indexador_limitante);
        }
        else
            return 1;
    }
    else
        return 0;
}

void deletar_contato(int s){
    remove(FILE_NAME);
    FILE *file = fopen(FILE_NAME, "a+");
    for (int i = s; i < counter; ++i) {
        contacts[i] = contacts[i+1];
    }
    counter--;
    for (int i = 0; i < counter; ++i) {
        salvar_contato(contacts[i], file);
    }
    fclose(file);
}

void editar_contato(){
    remove(FILE_NAME);
    FILE *file = fopen(FILE_NAME, "a+");
    for (int i = 0; i < counter; ++i) {
        salvar_contato(contacts[i], file);
    }
    fclose(file);
}

void menu(){

    // Operador do switch
    int op = 0;

    while (op != 9){
        printf("Escolha uma acao:\n");
        printf("1 - Novo contato:\n");
        printf("2 - Lista de contatos:\n");
        printf("3 - Buscar contatos:\n");
        printf("9 - Sair.\n");

        scanf("%d", &op);


        if(op != 9){
            switch (op) {
                case 1:
                    criar_contato();
                    break;
                case 2:
                    contatos_disponiveis();
                    break;
                case 3:
                    buscar_contato();
                    break;
                default:
                    printf("Opcao invalida, escolha entre 1 e 3, ou pressione 9 para sair");
            }
        }
        else
            printf("Adeus!.\n");
    }
}

void menu_edicao_exclusao(){

    // s para ditar o indice da lista quando a pessoa for encontrada, op operador do switch
    int s = -1, op = 0;

    printf("Informe a posicao do contato para selecionar, ou 0 para sair\n");
    scanf("%d", &s);
    fflush(stdin);

    // Teste para ver se o valor inserido não está fora da lista
    if (s > 0 && s <= counter) {
        s--;
        printf("%s", contacts[s].name);
        printf("1 - Editar.\n2 - Excluir.\nOutra teclar para sair.\n");
        scanf("%d", &op);
        fflush(stdin);

        switch (op) {
            case 1:
                printf("O que deseja alterar?\n");
                printf("1 - Nome.\n2 - Telefone.\n3 - Email.\n");
                scanf("%d", &op);
                fflush(stdin);
                switch (op) {
                    case 1:
                        printf("insira o novo nome: ");
                        fgets(contacts[s].name, 60, stdin);
                        fflush(stdin);
                        break;
                    case 2:
                        printf("Insira o novo telefone: ");
                        fgets(contacts[s].phone, 20, stdin);
                        fflush(stdin);
                        break;
                    case 3:
                        printf("insira o novo email: ");
                        fgets(contacts[s].email, 250, stdin);
                        fflush(stdin);
                        break;
                    default:
                        printf("Opcao invalida.\n");
                }
                editar_contato();
                break;
            case 2:
                printf("Tem certeza que deseja excluir %s?\n1 - SIM\n0 - NAO\n", contacts[s].name);
                scanf("%d", &op);
                fflush(stdin);
                if(op == 1) {
                    deletar_contato(s);
                    break;
                }
                else
                    break;
            default:
                printf("Opcao invalida");
        }
    }
    else
        printf("Contato inexistente\n");
}

void mostrar_contatos(int i){
    printf("Posicao (%d)\n", i+1);
    printf("Nome: %s", contacts[i].name);
    printf("Telefone: %s", contacts[i].phone);
    printf("Email: %s", contacts[i].email);
}

void carregar_arquivo(){

    // Carrega o arquivo no inicio do programa, metodo R para modo de apenas leitura
    FILE *file = fopen(FILE_NAME, "r");
    if(file != NULL){
        counter = 0;
        // leitura linha a linha do arquivo, função feof para testar se está no final do arquivo
        while (!feof(file)){
            fgets(contacts[counter].name, 60, file);
            // Teste para ver se a linha está em branco
            if(strcmp(contacts[counter].name, "") > 0) {
                fgets(contacts[counter].phone, 20, file);
                fgets(contacts[counter].email, 250, file);
                counter++;
            }
        }
    }
    else
        printf("Failed load file.");
    fclose(file);
}

void criar_contato(){
    if(counter < SIZE) {
        printf("Novo contato.\n");

        contact ctt;        // variável do tipo struct contact

        printf("Nome: ");
        fgetc(stdin);
        fgets(ctt.name, 60, stdin);
        printf("Telefone: ");
        fgets(ctt.phone, 20, stdin);
        printf("Email: ");
        fgets(ctt.email, 250, stdin);

        // Teste booleano
        if (inserir_contato(ctt) == 1)
            printf("Contato salvo!\n");
        else
            printf("Falha no processo.\n");
    }
    else
        printf("Memoria cheia.\n");
}

void contatos_disponiveis(){
    printf("Lista de contatos.\n");

    for (int i = 0; i < counter; ++i) {
        mostrar_contatos(i);
        printf("\n");
    }

    if(counter > 0)
        menu_edicao_exclusao();
}

void buscar_contato(){
    char name[61] = {""};

    int encontrar = 0;      // variável booleana
    printf("Digite o nome: ");
    fgets(name, 60, stdin);
    fflush(stdin);

    // variável para atribuir a quantidade de caracter ter o nome inserido para busca
    int limit = strlen(name);
    limit--;        // Enter conta como um caracter, então é necessario subtrair

    // loop para varrer a array com os contatos
    for (int i = 0; i < counter; ++i)
        // teste para ver se o nome inserido tem está contido em algum nome presente na lista
        if(strlen(contacts[i].name) >= limit)
            if(buscar_nome(name, contacts[i].name, 0, limit)) {
                mostrar_contatos(i);
                printf("\n");
                encontrar = 1;
            }

    // Teste para abrir menu secundário de acordo com a variável boolena
    if(encontrar == 1)
        menu_edicao_exclusao();
    else
        printf("Pessoa nao encontrada\n");
}