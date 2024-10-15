#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef unsigned char BOOL;

typedef struct ItemLista {
    void              *data;
    int                size;
    struct TItemLista *proximoItem;
    struct TItemLista *anteriorItem;
} TItemLista;

typedef struct ListaEncadeada{
    int               n;
    int        sizeItem;
    TItemLista *current;
    TItemLista   *first;
    TItemLista    *last;
    BOOL ehCircular;
} TListaEncadeada;

// prototipos das funcoes
TListaEncadeada *TListaEncadeada_create(TListaEncadeada *lista,int sizeItem, BOOL ehCircular);
void TListaEncadeada_destroy(TListaEncadeada *lista);
BOOL TListaEncadeada_adicionar(TListaEncadeada *lista,void *data);
BOOL TListaEncadeada_removerUltimo(TListaEncadeada *lista);
TItemLista *TListaEncadeada_goFirst(TListaEncadeada *lista);
TItemLista *TListaEncadeada_goLast(TListaEncadeada *lista);
TItemLista *TListaEncadeada_next(TListaEncadeada *lista);
void TListaEncadeada_print(TListaEncadeada *lista);

TItemLista *TItemLista_create(TItemLista *item,void *data, int size);
void TItemLista_destroy(TItemLista *item);
void TItemLista_print(TItemLista *item);

TItemLista *TItemLista_create(TItemLista *item,void *data, int size)
{
    // alocando espaco para item
    item = malloc(sizeof(TItemLista));
    if(item==NULL){
        return NULL;
    }
    item->data = malloc(size);
    // alocando espaco para dado
    if(item->data==NULL){
        free(item);
        return NULL;
    }
    // copiar o dado para dentro da area de dados do item
    item->size = size;
    memcpy(item->data,data,size);
    item->proximoItem = NULL;
    item->anteriorItem = NULL;
}
void TItemLista_destroy(TItemLista *item)
{
    free(item->data);
    item->data = NULL;
    free(item);
    item = NULL;
}
void TItemLista_print(TItemLista *item)
{
    char buffer[1000];
    char dataByte[4];
    char *point;
    int i;
   
    printf("---------------------------------------\n");
    printf("Ponteiro item : %x\n",item);
    printf("Proximo Item  : %x\n",item->proximoItem);
   
    strcpy(buffer,"");
    point = item->data;
    for(i=0;i<item->size;i++){
        sprintf(dataByte,"%02x ",point[i]);
        strcat(buffer,dataByte);
    }
    printf("Data : %s\n",buffer);
}
/*------------------------------------------------------------------------------*/
// Codigo dos metodos da lista

TListaEncadeada *TListaEncadeada_create(TListaEncadeada *lista,int sizeItem, BOOL ehCircular)
{
    lista = malloc(sizeof(TListaEncadeada));
    if(lista==NULL){
        return NULL;
    }
    // atribuindo as propriedades da Lista na condiçao inicial sem elementos
    lista->n = 0;
    lista->sizeItem = sizeItem;
    lista->current = NULL;
    lista->first = NULL;
    lista->ehCircular = ehCircular;
    
    return lista;
    
}

void TListaEncadeada_destroy(TListaEncadeada *lista)
{
    // Remove todos os elementos da lista
    while ( TListaEncadeada_removerUltimo(lista));

    free(lista);
}

TItemLista *TListaEncadeada_goLast(TListaEncadeada *lista)
{
    lista->current = lista->last;
    return lista->last;
}

BOOL TListaEncadeada_adicionar(TListaEncadeada *lista,void *data)
{
    TItemLista *item,*last,*penultimo;
    last = TListaEncadeada_goLast(lista);

    if((item = TItemLista_create(item,data, lista->sizeItem))==NULL){
        return FALSE;
    }
    if(lista->n == 0){
        // caso lista esta vazia
        lista->first = item;
        lista->last = item;
    }
    else if (lista->ehCircular == TRUE){
        // LEVI: caso que a lista ja tem elementos e é circular
        // LEVI: o proximo item do item recém adicionado é o primeiro
        last->proximoItem = item;
        item->proximoItem = lista->first;
    }
    else{
        //LEVI: caso que a lista tem elementos e não é circular
        //LEVI: o próximo item do item recém adicionado é o nulo
        last->proximoItem = item;
    }
    // atualiza o corrente
    lista->current = item;
    lista->last=item;
    // incrementa o numero de elemento
    lista->n++;

}
TItemLista *TListaEncadeada_goFirst(TListaEncadeada *lista){
    lista->current = lista->first;
    return lista->first;
}

TItemLista *TListaEncadeada_next(TListaEncadeada *lista){
    TItemLista *item;

    item = lista->current;
    //LEVI: caso que a lista é circular
    if(lista->ehCircular == TRUE){
        lista->current = item->proximoItem;
    }
    
    //LEVI: caso lista não circular
    else{
        if(item->proximoItem != NULL)
            lista->current = item->proximoItem;
    }

    return lista->current;
}

TItemLista *TListaEncadeada_goPrev(TListaEncadeada *lista){
    //LEVI: essa função pressupõe que o usuário a utilize apenas quando o item
    //corrente tiver um item na posição anterior, e não verifica essa condição
    TItemLista *item = TListaEncadeada_goFirst(lista);

    if(lista->n == 1)
        return lista->first;

    //LEVI: devo tratar o caso com lista->n == 1, pois nesse caso específico o
    //não entra no for
    for(int i = 0; i<(lista->n)-1; i++){
        if(((lista->n-1) - i) == 1){
            lista->current = item;
            break;
        }
        item = TListaEncadeada_next(lista);
    }
    return lista->current;
}

BOOL TListaEncadeada_removerUltimo(TListaEncadeada *lista){
    TItemLista *corrente = TListaEncadeada_goFirst(lista);
    TItemLista *ultimo = TListaEncadeada_goLast(lista);

    //caso não tenha elementos na lista
    if(lista->n == 0)
        return FALSE;
    
    lista->last = TListaEncadeada_goPrev(lista);
    TItemLista_destroy(ultimo);
    if(lista->ehCircular == TRUE){
        lista->last->proximoItem = lista->first;
    }else{
        lista->last->proximoItem = NULL;
    }
    lista->n--;
    return TRUE;
}

void TListaEncadeada_print(TListaEncadeada *lista){
    int i;
    TItemLista *item;
    printf("Tamanho : %d\n",lista->n);
    printf("Tamanho Item : %d\n",lista->sizeItem);
    printf("First   : %x\n",lista->first);
    printf("current : %x\n",lista->current);

    item = TListaEncadeada_goFirst(lista);
    for(i=0; i < lista->n; i++){
        TItemLista_print(item);
        item= TListaEncadeada_next(lista);
    }
}


int main()
{

    //UPDATE: adaptei as funções create, add, next, removerUltimo e só eu acho
    //depois testar elas direitinho e resolver bug se tiver, só fiz a questão da
    //da verificação de ser circular ou não


    TItemLista       *Item;
    int              a,b,c;
    TListaEncadeada *lista;

    // Teste do ItemLista
    a =1; b =2; c =3;
    if ( (Item = TItemLista_create(Item,&a, sizeof(a)))==NULL){
        printf("Nao foi possivel criar o Item da lista\n");
        exit(1);
    }
    TItemLista_print(Item);
    TItemLista_destroy(Item);

    // testando a lista TListaEncadeada
    lista = TListaEncadeada_create(&lista,sizeof(int), FALSE);
    if(lista == NULL){
        printf("Não foi possivel criar a lista\n");
        exit(1);
    }
    printf("\n**********************************\n");
    printf("Adiciona elemento 1 na lista\n");
    // adiciona elementos na lista
    if(TListaEncadeada_adicionar(lista,&a)==FALSE){
        printf("Não foi possivel adicionar elemento a lista\n");
        exit(1);
    }
    TListaEncadeada_print(lista);
    printf("\n**********************************\n");
    printf("Adiciona elemento 2 na lista\n");
    if(TListaEncadeada_adicionar(lista,&b)==FALSE){
        printf("Não foi possivel adicionar elemento a lista\n");
        exit(1);
    }
    TListaEncadeada_print(lista);
    printf("\n**********************************\n");
    printf("Adiciona elemento 3 na lista\n");
    if(TListaEncadeada_adicionar(lista,&c)==FALSE){
        printf("Não foi possivel adicionar elemento a lista\n");
        exit(1);
    }
    TListaEncadeada_print(lista);
    // testar o remover
    printf("\n**********************************\n");
    printf("Remove ultimo elemento da lista\n");
    if(TListaEncadeada_removerUltimo(lista)==FALSE){
        printf("Erro ao remover elemento da lista\n");
        exit(1);
    }
    TListaEncadeada_print(lista);
    printf("\n**********************************\n");
    printf("Remove ultimo elemento da lista\n");
    if(TListaEncadeada_removerUltimo(lista)==FALSE){
        printf("Erro ao remover elemento da lista\n");
        exit(1);
    }
    TListaEncadeada_print(lista);
    printf("\n**********************************\n");
    printf("Remove ultimo elemento da lista\n");
    if(TListaEncadeada_removerUltimo(lista)==FALSE){
        printf("Erro ao remover elemento da lista\n");
        exit(1);
    }
    TListaEncadeada_print(lista);
    printf("\n**********************************\n");
    printf("Tenta remover ultimo elemento de lista vazia\n");

    if(TListaEncadeada_removerUltimo(lista)==FALSE){
        printf("Erro ao remover elemento da lista\n");
    }
    TListaEncadeada_print(lista);

    return 0;
}