#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0 
#define TRUE 1

typedef unsigned char byte;

typedef byte boolean;

typedef struct Fila {
    int quantElementosMax;  // Quantidade máxima de elementos que a fila comporta
    int quantElementos;     //Quantidade de elementos
    int sizeElem;           //Tamanho em bytes do elemento
    byte *buffer;           //Área alocada para a fila
    byte *pin;              //Ponteiro apontando para o último elemento a ser colocado na fila
    byte *pout;             //Ponteiro apontando para o primeiro elemento a ser colocado na fila
} Fila;

Fila *Fila_cria(Fila *fila, int quantElementosMax, int sizeElem);
void Fila_destroy(Fila *fila);
void *Fila_push(Fila *fila, char *item);
void *Fila_pop(Fila *fila);
int Fila_getSize(Fila *fila);
boolean Fila_isEmpty(Fila *fila);
void Fila_show(Fila *fila);
    
Fila *Fila_cria(Fila *fila, int quantElementosMax, int sizeElem){
    fila = malloc(sizeof(Fila));
    if(fila == NULL){
        printf("Ocorreu um erro!");
        return NULL;
    }
    
    fila->buffer = malloc(sizeElem*quantElementosMax);
    
    fila->pin = fila->buffer;
    fila->pout = fila->buffer;
    fila->quantElementosMax = quantElementosMax;
    fila->quantElementos = 0;
    fila->sizeElem = sizeElem;
    
    return fila;
}

void Fila_destroy(Fila *fila){
    free(fila->buffer);
    free(fila);
    fila = NULL;
}

void *Fila_push(Fila *fila, char *item){
    if(fila == NULL || (fila->quantElementos == fila->quantElementosMax)){
        printf("A fila não foi alocada ou já está cheia");
        return NULL;
    }
    if(fila->pout > fila->buffer + (fila->sizeElem * fila->quantElementos)){ 
        fila->pout = fila->buffer;
    }
    
    memcpy(fila->pout, item, fila->sizeElem);
    fila->pout += fila->sizeElem;
    fila->quantElementos++;
    
}

void *Fila_pop(Fila *fila){
    if(fila == NULL || (fila->quantElementos == 0)){
        printf("A fila não foi alocada ou ainda está vazia");
        return NULL;
    }
    for(int i = 0; i<fila->sizeElem; i++){
        printf("%.2x ", fila->pin[i]);
    }
    memset(fila->pin, 0x00, fila->sizeElem);
    fila->pin += fila->sizeElem;
    fila->quantElementos--;
}

int Fila_getSize(Fila *fila){
    return fila->sizeElem;
}

boolean Fila_isEmpty(Fila *fila){
    boolean resultado = fila->quantElementos==0?TRUE:FALSE;
    return resultado;
}

void Fila_show(Fila *fila){
    printf("Quantidade máxima de elementos:     %d\n", fila->quantElementosMax);
    printf("Quantidade de elementos:            %d\n", fila->quantElementos);
    printf("Tamanho do elemento:                %d\n", fila->sizeElem);
    printf("Primeiro endereço do buffer:        %x\n", fila->buffer);
    printf("Primeiro endereço da fila:          %x\n", fila->pin);
    printf("Último endereço da fila + 1 byte:   %x\n\n", fila->pout);
    
    
    byte *pcur = fila->pin;
    int i, j;
    for(i = 0; i<fila->quantElementos; i++){ //loop pra andar pelos elementos da fila
        
        if(pcur > fila->buffer + (fila->sizeElem * fila->quantElementos)){ 
            pcur = fila->buffer; //continua dando errado
        }
        
        for(j = 0; j<fila->sizeElem; j++){   //loop pra andar por cada byte de cada elemento     
            printf("%.2x ", pcur[j]);
        }
        printf(" <- ");
        
        pcur += fila->sizeElem;
    }
    printf("\n\n");
}


 





int main(){
    int a = 6;
    int b = 5;
    int c = 4;
    int d = 3;
    int e = 2;
    int f = 1;
    
    Fila *fila = Fila_cria(fila, 5, sizeof(int));
    
    Fila_push(fila, &a);
    Fila_show(fila);

    Fila_push(fila, &b);
    Fila_show(fila);

    Fila_push(fila, &c);
    Fila_show(fila);

    Fila_push(fila, &d);
    Fila_show(fila);
    
    Fila_push(fila, &e);
    Fila_show(fila);
    
    Fila_pop(fila);
    Fila_show(fila);
    
    Fila_pop(fila);
    Fila_show(fila);
    
    Fila_push(fila, &f);
    Fila_show(fila);
    
    
}