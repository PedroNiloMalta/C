#include <stdio.h>
#include <stdlib.h>

typedef struct node { //Nó
    int valor;
    struct node *next;
} node;

typedef struct list { //Lista
    node *first, *end;
    int size;
} list;

//Mostrar a lista
void print(list *list){
    node *first = list->first;
    printf("Tamanho da Lista..: %d\n", list->size);
    while(first != NULL){
        printf("%d ",first->valor);
        first = first->next;
    }printf("\n");
}

// Inserir na lista
void insert(list *list, int num){
    node *new = (node*)malloc(sizeof(node)); // Cria um novo nó
    new->valor=num;

    if(list->first == NULL){ //Se a lista estiver vazia
         new->next = NULL;
         list -> end = new;
         list->first = new;
    } else{ //A lista não está vazia
        node *antigo=list->end;
        new->next=NULL;
        list->end = new;
        antigo->next= new;
    }list->size++;
        
}

//Deletar o primeiro elemento da lista
void pop(list*list){
    node *antigo = list -> first;
    list->first = list->first->next;
    free(antigo);
    list->size--;
    
}

//Deletar o ultimo elemento da lista
void pop_back(list*list){
    node *antigo = list->end;
    node *aux = list->first;
    int count=0;
    while(count<list->size - 2){
        aux= aux->next;
        count++;
    }
    free(antigo);
    list->end = aux;
    aux->next = NULL;
    list->size--;
}

//Mostrar o final da lista
void print_end(list*list){
    node *end=list->end;
    printf("%d",end->valor);
}

//Mostrar o inicio da lista
void print_first(list *list){
    node *first= list->first;
    printf("%d \n",first->valor);
}

int main() {
    list list;
    int valor;
    int opcao;
    list.first = NULL;
    list.end = NULL;
    list.size = 0;

    do { // menu de opções
        printf("1 - Inserir\n2 - Imprimir\n3 - Remover o primeiro\n4 - Remover o ultimo\n5 - Imprimir o ultimo\n6 - Imprimir o primeiro\n7 - Sair.\n");
        scanf("%d", &opcao);

        switch(opcao) {
        case 1:
            printf("Digite um valor a ser inserido: ");
            scanf("%d", &valor);
            insert(&list, valor);
            break;
        case 2:
            print(&list);
            break;
        case 3:
            printf("Removendo o primeiro...\n");
            pop(&list);
            break;
        case 4:
            printf("Removendo o ultimo...\n");
            pop_back(&list);
            break;
        case 5:
            printf("Ultimo elemento da lista..: ");
            print_end(&list);
            break;
        case 6:
             printf("Primeiro elemento da lista..: ");
            print_first(&list);
            break;
        case 7:
            printf("Finalizando...\n");
            break;
        default:
            printf("Opcao invalida!\n");}
    } while(opcao != 7);

    return 0;
}
