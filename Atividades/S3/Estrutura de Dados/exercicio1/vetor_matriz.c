#include <stdio.h>
#include <string.h>

#define MAX_VETOR 100
#define MAX_LIN 10
#define MAX_COL 10

void memoryDump(void *address, int number, int sizeofType);

void memoryDump(void *address, int number, int sizeofType){
    char *pointer; 
    int i,n;
    
    n = number*sizeofType;
    
    pointer = address;
    
    for(int i = 0; i<n; i++){
        if(i % sizeofType == 0){
            printf("--------------------------\n");
            printf("%x :: %x\n", (unsigned char) pointer, *pointer);
            pointer++;
        }
    }
}

int main(){
        
        int vetor[MAX_VETOR];
        int matriz[MAX_LIN][MAX_COL];
        
        memset(vetor, 0x0A, sizeof(vetor[0])*MAX_VETOR);
        printf("Print do Dump: \n");
        memoryDump(vetor, MAX_VETOR, sizeof(vetor[0]));
        
        memset(matriz, 0xAF, MAX_COL*MAX_LIN*sizeof(matriz[0][0]));
        printf("\nPrint do Dump: \n");
        memoryDump(matriz, MAX_LIN*MAX_COL, sizeof(matriz[0][0]));
        
        (*(int *) (&matriz)) = vetor;
        memset(vetor, 0x00, sizeof(vetor[0]*MAX_VETOR));
        printf("Print do Dump: \n");
        memoryDump(vetor, MAX_VETOR, sizeof(vetor[0]));
        memoryDump(matriz, MAX_LIN*MAX_COL, sizeof(matriz[0][0]));
        
}
