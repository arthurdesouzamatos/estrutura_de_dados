#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
}No;


void inserir_no_inicio(No **lista, int num) {
    No *novo = malloc(sizeof(No));

    if(novo) {
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    } else
        printf("Erro ao alocar memoria!\n");
}

void inserir_no_fim(No **lista, int num) {
    No *aux, *novo = malloc(sizeof(No));

    if(novo) {
        novo->valor = num;
        novo->proximo = NULL;

        if(*lista == NULL)
            *lista = novo;
        else {
            aux = *lista;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
}

void imprimir (No *no) {
    printf("\n\tLista: ");
    while (no) {
        printf("%d", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main() {

    int opcao, valor;
    No *lista = NULL;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_no_inicio(&lista, valor);
                break;
            case 2:
                imprimir(lista);
                break;
            case 3:
                printf("Digite um valor");
                scanf("%d", &valor);
                inserir_no_fim(&lista, valor);
                break;

            default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }
    } while (opcao !=0);

    return 0;
    
}

