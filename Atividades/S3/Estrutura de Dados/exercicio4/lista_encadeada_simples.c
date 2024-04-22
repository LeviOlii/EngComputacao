#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define TYPE_INT 2
#define TYPE_CHAR 3
#define TYPE_FLOAT 4
#define TYPE_DOUBLE 5
#define TYPE_STRING 6


typedef unsigned char BOOL;

//estrutura para o item
typedef struct Item{
    void *data;
    int size;
    struct Item *proximoItem;
    struct Item *anteriorItem;
}TItemLista;

//Criando a lista encadeada
typedef struct listaEncadeada{
    int tamanhoItem;
    int quantItem;
    TItemLista *corrente;
    TItemLista *primeiroItem;
    TItemLista *ultimoItem;
    BOOL ehCircular;
}TListaEncadeada;

TItemLista *TItemLista_create(TItemLista *item, int size, void *data);
void *TItemLista_dump(TItemLista *item);
void *TItemLista_print(TItemLista *item, unsigned int TYPE_STR);
void *TItemLista_delete(TItemLista *item);


TItemLista *TItemLista_create(TItemLista *item, int size, void *data){
    item = malloc(sizeof(TItemLista));
    if(item == NULL){
        printf("Memória não alocada corretamente\n");
        return NULL;
    }

    item->data = malloc(size);
    if(item->data == NULL){
        free(item);
        printf("Memória não alocada corretamente\n");
        return NULL;
    }
    memcpy(item->data, data, size);
    item->size = size;
    item->proximoItem = NULL;
    item->anteriorItem = NULL;

    return item;
}

void *TItemLista_dump(TItemLista *item){
    if(item == NULL){
        printf("O item ainda não foi alocado!\n");
        return NULL;
    }
    char buffer[1000];
    char dataByte[4];
    char *ponto;
    
    ponto = item->data;
    strcpy(buffer, "");
    //printf("-----------------------------------------\n");
    for(int i = 0; i<item->size; i++){
        sprintf(dataByte, "%x ", ponto[i]);
        strcat(buffer, dataByte);
    }

    printf("Dump do dado: %s\n", buffer);
}

void *TItemLista_print(TItemLista *item, unsigned int TYPE_STR){
    switch (TYPE_STR)
    {
    case TYPE_INT: ; //esse ponto e virgula serve para resolver o erro "a label can only be part of a statement and a declaration is not a statement", nao sei pq mas funciona
    //caso funciona
        int *inteiro;
        inteiro = malloc(sizeof(int));
        memcpy(inteiro, item->data, sizeof(int));
        printf("Print do dado: %d\n", *inteiro);
        free(inteiro);
        break;
    case TYPE_CHAR: ; //esse caso não imprime o caractere verdadeiro do item, erro desconhecido
        char *character;
        character = calloc(1, sizeof(char));
        memcpy(character, item->data, sizeof(char));
        printf("Print do dado: %c\n", *character);
        free(character);
        break;
    case TYPE_FLOAT: ; //caso funciona
        float *flutuante;
        flutuante = calloc(1, sizeof(float));
        memcpy(flutuante, item->data, sizeof(float));
        printf("Print do dado: %.2f\n", *flutuante);
        free(flutuante);
        break;
    case TYPE_DOUBLE: ;
        double *flutuante2;
        flutuante2 = calloc(1, sizeof(double));
        memcpy(flutuante2, item->data, sizeof(double));
        printf("Print do dado: %.2f\n", *flutuante2);
        free(flutuante2);
        break;
    }
}

void *TItemLista_delete(TItemLista *item){
    free(item->data);
    item->data = NULL;
    free(item);
    item = NULL;
}

TListaEncadeada *TListaEncadeada_create(TListaEncadeada *lista, int tamanhoItem, BOOL ehCircular){
    lista = malloc(sizeof(TListaEncadeada));
    
    if(lista == NULL){
        printf("Memória não alocada corretamente!\n");
        return NULL;
    }
    
    lista->corrente = NULL;
    lista->ehCircular = ehCircular;
    lista->primeiroItem = NULL;
    lista->quantItem = 0;
    lista->tamanhoItem = tamanhoItem;

    return lista;
}

TItemLista *TListaEncadeada_goFirst(TListaEncadeada *lista){
    lista->corrente = lista->primeiroItem;
    return lista->primeiroItem;
}

TItemLista *TListaEncadeada_goLast(TListaEncadeada *lista){
    lista->corrente = lista->ultimoItem;
    return lista->ultimoItem;
}

TItemLista *TListaEncadeada_goNext(TListaEncadeada *lista){
//tentei fazer assim deu errado
//----------------------------------------------------------------------------
   /* //caso o corrente não seja o último elemento (circular ou não circular)
    if(lista->corrente->proximoItem != NULL){
        lista->corrente = lista->corrente->proximoItem;
        return lista->corrente->proximoItem;
    }//caso o corrente seja o último elemento, não retorna nada
}*/
//----------------------------------------------------------------------------
    TItemLista *item;
    
    //caso o corrente não seja o último elemento (circular ou não circular)
    item = lista->corrente;
    if( item->proximoItem != NULL){
        lista->corrente = item->proximoItem;
    }
    return lista->corrente;
    //caso o corrente seja o último elemento, não retorna nada
}


TListaEncadeada *TListaEncadeada_add(TListaEncadeada *lista, TItemLista *item){
    TItemLista *ultimo, *aux;
    //caso que cobre circular ou não circular
    if(lista->quantItem == 0){
        lista->corrente = item;
        lista->primeiroItem = item;
        lista->ultimoItem = item;
    }
    //caso a lista tenha mais que um item: analisar caso seja circular ou não
    else{
        lista->corrente = item;
        ultimo = TListaEncadeada_goLast(lista);
        ultimo->proximoItem = item;
        if(lista->ehCircular == TRUE){
            item->proximoItem = lista->primeiroItem;
            lista->ultimoItem = item;
        }
        else{
            lista->ultimoItem = item;
        }
    }
    
    lista->quantItem++;
    return lista;
}

void *TListaEncadeada_print(TListaEncadeada *lista, unsigned int TYPE_STR){
    if(lista->quantItem == 0){
        printf("A listá está vazia.\n");
    }
    lista->corrente = TListaEncadeada_goFirst(lista);
    for(int i = 0; i<lista->quantItem; i++){
        printf("-----------------------------------------\n");
        printf("Item n°%d:\n", i+1);
        TItemLista_print(lista->corrente, TYPE_STR);
        lista->corrente = TListaEncadeada_goNext(lista);
    }
}

void *TListaEncadeada_dump(TListaEncadeada *lista){
    if(lista->quantItem == 0){
        printf("A listá está vazia.\n");
    }
    lista->corrente = TListaEncadeada_goFirst(lista);
    for(int i = 0; i<lista->quantItem; i++){
        printf("-----------------------------------------\n");
        printf("Item n°%d:\n", i+1);
        printf("Item corrente: %x\n", lista->corrente);
        printf("Próximo item: %x\n", lista->corrente->proximoItem);
        printf("Primeiro item: %x\n", lista->primeiroItem);
        printf("Último item: %x\n", lista->ultimoItem);
        TItemLista_dump(lista->corrente);
        lista->corrente = TListaEncadeada_goNext(lista);
    }
}

void *TListaEncadeada_removerUltimo(TListaEncadeada *lista){
    TItemLista *corrente = TListaEncadeada_goFirst(lista);

    TItemLista_delete(lista->ultimoItem);
    lista->quantItem--;
    
    //percorrer a lista até atualizar o último elemento e fazer seu próximo apontar pra nulo
    for(int i = 0; i<lista->quantItem; i++){
        if(((lista->quantItem)-i) == 1){
            lista->ultimoItem = corrente;
            if(lista->ehCircular == FALSE)
                lista->ultimoItem->proximoItem = NULL;
            else
                lista->ultimoItem->proximoItem = lista->primeiroItem;
            break;
        }
        corrente = TListaEncadeada_goNext(lista);
    }
}

void *TListaEncadeada_destroy(TListaEncadeada *lista){
    while(lista->quantItem != 0){
        TListaEncadeada_removerUltimo(lista);
    }
}

int main()
{
    TItemLista *item, *item2, *item3;
    TListaEncadeada *lista;
    int a, b, c;
    a=35;
    b=2;
    c=3;
    double d = 12.2;

    //criando os itens
    item = TItemLista_create(item, sizeof(int), &a);
    item2 = TItemLista_create(item2, sizeof(int), &b);
    item3 = TItemLista_create(item3, sizeof(int), &c);
    
    lista = TListaEncadeada_create(lista, sizeof(int), FALSE);
    
    //printando a lista
    printf("-------------------PRINTANDO A LISTA--------------------\n");
    lista = TListaEncadeada_add(lista, item);
    TListaEncadeada_print(lista, TYPE_INT);
    printf("-----------------------------------------------\n\n\n");
    
    lista = TListaEncadeada_add(lista, item2);
    TListaEncadeada_print(lista, TYPE_INT);
    printf("-----------------------------------------------\n\n\n");
    
    lista = TListaEncadeada_add(lista, item3);
    TListaEncadeada_print(lista, TYPE_INT);
    printf("-----------------------------------------------\n\n\n");

    
    //testando função de remover último
    TListaEncadeada_removerUltimo(lista);
    TListaEncadeada_print(lista, TYPE_INT);
    printf("-----------------------------------------------\n\n\n");

    
    //dumpando a lista
    printf("-------------------DUMPANDO A LISTA--------------------\n");
    TListaEncadeada_dump(lista);
    printf("-----------------------------------------------\n\n\n");

    //testando a função de destruir a lista
    TListaEncadeada_destroy(lista);
    printf("-------------------DUMPANDO A LISTA--------------------\n");
    TListaEncadeada_dump(lista);
    printf("-----------------------------------------------\n\n\n");

    return 0;
}







