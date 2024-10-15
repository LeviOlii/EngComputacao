#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;
typedef byte boolean;

#define TRUE 1
#define FALSE 0

//Estruturas
typedef struct No{
    int size; 
    int *dado;
    struct No *left;
    struct No *right;
    struct No *pai;
    int nivel;
}TNo;

typedef struct BinaryTree {
    TNo *raiz;
    int sizeNo;
    int nivel;
    int nelem;
}TBinaryTree;

//Protótipos
TNo     *TNo_create(TNo *no, int *dado, int size);
void     TNo_destroy(TNo *no);
TNo     *TNo_setLeftNode(TNo *no, TNo *left);
TNo     *TNo_setRightNode(TNo *no, TNo *right);
void    *TNo_dump(TNo *no);

TBinaryTree  *TBinaryTree_create(TBinaryTree *tree, int *rootValue, int sizeNo);
boolean       TBinaryTree_addNode(TBinaryTree *tree, TNo *noCurrent, int *dado, int level);
boolean       TBinaryTree_add(TBinaryTree *tree, int *dado);
void          TBinaryTree_print(TBinaryTree *tree);
void          TBinaryTree_dump(TBinaryTree *tree);
void          TBinaryTree_dumpChild(TBinaryTree *tree, TNo *child);
void          TBinaryTree_destroy(TBinaryTree *tree);
TNo          *TBinaryTree_find(TBinaryTree *tree, int *dado);

//Funções do Nó

TNo     *TNo_create(TNo *no, int *dado, int size){
    if((no = malloc(sizeof(TNo))) == NULL){
        printf("Ocorreu um erro na alocação do nó!\n");
        return NULL;
    }
    
    if((no->dado = malloc(size)) == NULL){
        return NULL;
        printf("Ocorreu um erro na alocação do dado!\n");
    }
    
    memcpy(no->dado, dado, size);
    no->size = size;
    no->left = NULL;
    no->right = NULL;
    no->pai = NULL;

    return no;
}

void     TNo_destroy(TNo *no){
    free(no->dado);
    no->dado = NULL;
    no->size = 0;
    no->left = no->right = NULL;
    free(no);
    no = NULL; //nozei
}

TNo     *TNo_setLeftNode(TNo *no, TNo *left){
    no->left = left;
}

TNo     *TNo_setRightNode(TNo *no, TNo *right){
    no->right = right;
}

void     *TNo_dump(TNo *no){
    if(no == NULL){ //por algum motivo, após ser destruído, o nó não é alterado para nulo
        printf("Nó inexistente!\n");
        return NULL;
    }
    printf("Nó:                         %x\n", (TNo *) no);
    printf("Nó left:                    %x\n", (TNo *) no->left);
    printf("Nó right:                   %x\n", (TNo *) no->right);
    printf("Tamanho do dado:            %d\n", no->size);
    printf("Nível do nó:                %d\n", no->nivel);
    printf("Dado:                      ");
    
    byte *pc;
    pc = (byte *) no->dado;
    for(int i = 0; i<no->size; i++){
        printf(" %.2x", pc[i]);
        
    }
    printf("\n\n");
}

//Funções da Arvore Binaria
TBinaryTree  *TBinaryTree_create(TBinaryTree *tree, int *rootValue, int sizeNo){
    if((tree = malloc(sizeof(TBinaryTree)))==NULL){
        printf("Ocorreu um erro na alocação da árvore!\n");
        return NULL;
    }
    
    
    tree->raiz = TNo_create(tree->raiz, rootValue, sizeNo);
    tree->sizeNo = sizeNo;
    tree->nivel = 0;
    tree->nelem = 1;
    
    return tree;
}

boolean     TBinaryTree_add(TBinaryTree *tree, int *dado){
    boolean resultado;
    resultado = TBinaryTree_addNode(tree, tree->raiz, dado, tree->raiz->nivel);
    return resultado;
}

boolean    TBinaryTree_addNode(TBinaryTree *tree, TNo *noCurrent, int *dado, int nivel){
    TNo *novoNo;
    static TNo *pai;
    
    if(noCurrent == NULL){
        return FALSE;
    }
    
    else{
        if((novoNo = TNo_create(novoNo, dado, tree->sizeNo))==NULL){
            return FALSE;
        }
        if(*dado == *(noCurrent->dado)){
            printf("Dado já existe na árvore!\n");
            return FALSE;
        }
        else if(*dado < *(noCurrent->dado)){ 
            if(noCurrent->left == NULL){
                novoNo->nivel = nivel+1;
                tree->nivel = (nivel>tree->nivel)?(nivel):(tree->nivel);
                tree->nelem++;
                TNo_setLeftNode(noCurrent, novoNo);
                return TRUE;
            }
            else{
                TBinaryTree_addNode(tree, noCurrent->left, dado, nivel+1);
            }
            
        }
        else{                   //se *dado > *(noCurrent->dado)
            if(noCurrent->right == NULL){
                novoNo->nivel = nivel+1;
                tree->nivel = (nivel>tree->nivel)?(nivel):(tree->nivel);
                tree->nelem++;
                TNo_setRightNode(noCurrent, novoNo);
                return TRUE;
            }
            else{
                TBinaryTree_addNode(tree, noCurrent->right, dado, nivel+1);
            }
        }
    }
}   
//proximo passo: fazer o dump, print e find.

void     TBinaryTree_dump(TBinaryTree *tree){
    printf("No raiz\n");
    TBinaryTree_dumpChild(tree,tree->raiz);
    printf("sizeNo = %d\n",tree->sizeNo);
    printf("nivel  = %d\n",tree->nivel);
    printf("neleme = %d\n",tree->nelem);
   
}
void TBinaryTree_dumpChild(TBinaryTree *tree,TNo *child){
    if(child != NULL){
        printf("-------------------------------\n");
        TNo_dump(child);
        printf("-------------------------------\n");
        // Se o filho for uma folha
        if(( child->left==NULL)&&(child->right==NULL)){
            return;
        }
        else{
            if(child->left != NULL){
                TBinaryTree_dumpChild(tree,child->left);
            }
            if(child->right != NULL){
                TBinaryTree_dumpChild(tree,child->right);
            }
        }
    }
}





int main()
{
    //Testando as funções de nós
    TNo *no1, *no2, *no3;
    TBinaryTree *tree;
    int a, b, c, d, e, rootValue;
    a = 1;
    b = 5;
    c = 7;
    d = 0;
    e = 10;
    rootValue = 6;
    /*
    if((no1 = TNo_create(no1, &a, sizeof(int)))==NULL){
        return -1;
    }
    TNo_dump(no1);
    
    if((no2 = TNo_create(no2, &b, sizeof(int)))==NULL){
        return -1;
    }
    TNo_dump(no2);
    
    if((no3 = TNo_create(no3, &c, sizeof(int)))==NULL){
        return -1;
    }
    TNo_dump(no3);
    
    printf("-----------Mostrando Left e Right Functions-----------\n\n");
    TNo_setLeftNode(no1, no2);
    TNo_dump(no1);
    TNo_setRightNode(no1, no3);
    TNo_dump(no1);
    
    printf("-----------Mostrando Function de deleção-----------\n\n");
    TNo_destroy(no2);
    TNo_dump(no2);*/
    
    //Testando funções da árvore
    if((tree = TBinaryTree_create(tree, &rootValue, sizeof(int)))==NULL){
        return -1;
    }
    
    //Caso 1: adição quando a árvore tem apenas o nó raiz, e dado é menor que raiz->dado
    if((TBinaryTree_add(tree, &a))==TRUE){
        printf("Adição feita à esquerda da árvore!\n");
    }
    TNo_dump(tree->raiz);
    TNo_dump(tree->raiz->left);
    
    //Caso 2: adição quando a árvore tem apenas o nó raiz, e dado é maior que raiz->dado
    if((TBinaryTree_add(tree, &c))==TRUE){
        printf("Adição feita à direita da árvore!\n");
    }
    TNo_dump(tree->raiz);
    TNo_dump(tree->raiz->right);
    
    //Caso 3: adição à esquerda quando no->raiz->left tem filho, chamando addNode pelo menos 1 vez
    if((TBinaryTree_add(tree, &d))==TRUE){
        printf("Adição feita à esquerda da árvore!\n");
    }
    TNo_dump(tree->raiz);
    TNo_dump(tree->raiz->left);
    
    //Caso 4: adição à direita quando no->raiz->right tem filho, chamando addNode plmns 1 vez
    if((TBinaryTree_add(tree, &e))==TRUE){
        printf("Adição feita à direita da árvore!\n");
    }
    TNo_dump(tree->raiz);
    TNo_dump(tree->raiz->right);
    
    //Caso 5: dado já existe na árvore
    if((TBinaryTree_add(tree, &e))==TRUE){
        printf("Adição feita à direita da árvore!\n");
    }
    TNo_dump(tree->raiz);
    TNo_dump(tree->raiz->right);
    

    return 0;
}