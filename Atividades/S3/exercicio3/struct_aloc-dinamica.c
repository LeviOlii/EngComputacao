/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Ponto2D{
    float x;
    float y;
}Ponto2D;

//Calcula a distância entre dois pontos de duas structs Ponto2D
double distanciaPontos(Ponto2D *p1, Ponto2D *p2){
    double dx = (double) fabs(p1->x - p2->x);
    double dy = (double) fabs(p1->y - p2->y);
    
    return sqrt(dx * dx + dy * dy);
}



int main()
{
    
    int n;
    int scan;
    Ponto2D *vetorPontos;
    Ponto2D *p;
    float dx, dy;
    float soma = 0.0f;
    
    printf("Indique o número de pontos de coordenadas x e y: ");
    scanf("%d", &n);
    scan = n;
    float distancia[scan-1];
    
    vetorPontos = malloc(scan*sizeof(Ponto2D));
    p = vetorPontos;
    
    if(vetorPontos = NULL){
        printf("\nMemória não alocada corretamente.");
        return -1;
    }
    
    for(int i = 0; i<scan; i++){
        
        printf("\nIndique as coordenadas X do Ponto n°%d: ", (i+1));
        scanf("%f", &dx);
        p[i].x = dx;
        printf("\nIndique as coordenadas Y do Ponto n°%d: ", (i+1));
        scanf("%f", &dy);
        p[i].y = dy;
        
        if(i >= 1){
            distancia[i-1] = distanciaPontos(&p[i-1], &p[i]);
            soma = soma + distancia[i-1];
        }
    }
    
    for(int i = 0; i<scan; i++){
        printf("\nPonto %d: \nX: %f\nY: %f", i+1, p[i].x, p[i].y);
        
    }
    
    for(int i = 0; i<scan-1; i++){
        printf("\nDistancia entre Ponto %d ; Ponto %d: %f", i+1, i+2, distancia[i]);
    }
    
    printf("\nSoma das distâncias: %f", soma);
    
    return 0;
}









